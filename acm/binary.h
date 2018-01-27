/**
 * Created by suli on 18/1/16.
 */

#ifndef MYLEARN_BINARY_H
#define MYLEARN_BINARY_H

#include <stdio.h>
#include <iostream>

template<typename T>
struct Node {
	Node(T data) {
		value = data;
	}
	T value;
	Node *pre;
	Node *next;
};

class algo {
 public:
	int binary(int *array, int start, int end, int target);
	void binary_test();

};

template<class T>
class List {
 public:
	List() : head(NULL), tail(NULL) {
	}
	List(T &value) {
		push_back(value);
	}
	List(T value) {
		push_back(value);
	}
	~List() {
		Node<T> *tmp = head;
		while (tmp != NULL) {
			delete tmp;
			tmp = tmp->next;
		}
	}
	bool push_back(T &value) {
		Node<T> *tmp = new Node<T>(value);
		if (tail) {
			tail->next = tmp; //加尾节点
		}
		tmp->pre = tail;
		if (head == NULL) {
			head = tmp;
		}
		tail = tmp; //尾节点更新
		len++;
		return true;
	}
	bool push_back(T value) {
		Node<T> *tmp = new Node<T>(value);
		if (tail) {
			tail->next = tmp; //加尾节点
		}
		tmp->pre = tail;
		if (head == NULL) {
			head = tmp;
		}
		tail = tmp; //尾节点更新
		len++;
		return true;
	}
	Node<T> *find(T &value) {
		Node<T> *tmp = head;
		while (tmp) {
			if (tmp->value == value) {
				return tmp;
			}
			tmp = tmp->next;
		}
		return NULL;
	}
	bool remove(T &value) {
		Node<T> *tmp = find(value);
		if (tmp) {
			tmp->pre->next = tmp->next;
			tmp->next->pre = tmp->pre;
			len--;
			delete tmp;
			return true;
		} else {
			std::cout << "no this node!!" << std::endl;
		}
		return true;
	}
	int size() {
		return len;
	}

	T operator[](int index) {
		if (index < 0) {
			T tmp;
			return tmp;
		}
		Node<T> *tmp = head;
		for (int i = 0; i < index; i++) {
			if (tmp) {
				tmp = tmp->next;
			} else {
				T tmp;
				return tmp;
			}
		}
		return tmp->value;
	}

 private:
	int len;
	Node<T> *head;
	Node<T> *tail;
};

#endif //MYLEARN_BINARY_H
