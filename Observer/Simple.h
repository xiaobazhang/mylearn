//
// Created by suli on 17/1/5.
//

#ifndef MYLEARN_SIMPLE_H
#define MYLEARN_SIMPLE_H
#include "Observer.h"

class Click : public Subject  {
 public:
  Click(){}
  void SecondClick();
};

class ObserverReceive1 : public Observer {
 public:
  ObserverReceive1(Click*);
  virtual ~ObserverReceive1();

  virtual void Update(Subject* );

  virtual void DisplayInfo();
 private:
  Click* m_click;
};

class ObserverReceive2 : public Observer{
 public:
  ObserverReceive2(Click*);
  virtual ~ObserverReceive2();

  virtual void Update(Subject*);

  virtual void DisplayInfo();
 private:
  Click* m_click;
};



#endif //MYLEARN_SIMPLE_H
