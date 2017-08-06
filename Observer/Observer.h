//
// Created by suli on 17/1/5.
//

#ifndef MYLEARN_OBSERVER_H
#define MYLEARN_OBSERVER_H
#include <list>
#include <vector>

using namespace std;

class Subject;

class Observer {
 public:
  virtual ~Observer(){};
  virtual void Update(Subject* ChangObserver)=0;
 protected:
  Observer(){};
};


class Subject{
 public:
  virtual ~Subject(){};
  virtual void Attach(Observer*);
  virtual void Detach(Observer*);
  virtual void Notify();
 protected:
  Subject(){};
 private:
  vector<Observer*> _observer;
};

#endif //MYLEARN_OBSERVER_H
