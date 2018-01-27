/**
 * Created by suli on 18/1/17.
 */

#ifndef MYLEARN_THREADPOOL_H
#define MYLEARN_THREADPOOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

class Task {
 public:
	Task() {}
	virtual ~Task() {}

	virtual void Run() {
		std::cout << "task running!!" << std::endl;
	}
};

class Thread {
 public:

	Thread() : free_(true), task_(NULL) {
		thread_ = std::thread(&Thread::run, this);
		thread_.detach();
	}
	~Thread() {}

 private:
	Task *task_;
	std::mutex mutex_;
	std::thread thread_;
	bool free_;

 public:

	bool is_free() {
		return free_;
	}
	bool addTask(Task *task) {
		if (free_) {
			mutex_.lock();
			free_ = false;
			task_ = task;
			mutex_.unlock();
		}
		return true;
	}
	void run() {
		while (1) {
			if (task_) {
				mutex_.lock();
				free_ = false;
				task_->Run();
				task_ = NULL;
				free_ = true;
				mutex_.unlock();
			}
			sleep(1);
		}
	}
};

class ThreadPool {
 public:
	ThreadPool(int num = 6) {
		t_num = num;
		for (int i = 0; i < num; i++) {
			std::cout << "create thread!!" << std::endl;
			thread_.push_back(new Thread());
		}
	}
	~ThreadPool() {
		for (int i = 0; i < thread_.size(); i++) {
			delete thread_[i];
		}
		thread_.clear();
	}

	void AddTask(Task *task) {
		mutex_.lock();
		if (task) {
			std::cout << "push task!!" << std::endl;
			task_.push(task);
		}
		mutex_.unlock();
	}

	void Run() {
		while (true) {
			mutex_.lock();
			for (int i = 0; i < thread_.size(); i++) {
				if (thread_[i]->is_free()) {
					std::cout << "ThreadPool run!!" << std::endl;
					if (!task_.empty()) {
						thread_[i]->addTask(task_.front());
						task_.pop();
					}
					std::cout << "ThreadPool1 run!!" << std::endl;
				}
			}
			mutex_.unlock();
			sleep(1);
		}
	}

 private:
	std::vector<Thread *> thread_;
	std::queue<Task *> task_;
	std::mutex mutex_;
	int t_num;
};

#endif //MYLEARN_THREADPOOL_H
