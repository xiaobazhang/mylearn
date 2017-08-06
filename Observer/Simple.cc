//
// Created by suli on 17/1/5.
//

#include "Simple.h"
#include <unistd.h>
#include <iostream>


void Click::SecondClick()
{
  while(1){
    sleep(1);
    Notify();
  }
}

ObserverReceive1::ObserverReceive1(Click *c)
{
  m_click = c;
  m_click->Attach(this);//注册自己;
}
ObserverReceive1::~ObserverReceive1() {
  m_click->Detach(this);
}

void ObserverReceive1::Update(Subject *change) {
  if(change == m_click){
    DisplayInfo();//显示打印信息
  }
}
void ObserverReceive1::DisplayInfo() {
  std::cout<<"I am ObserverReceive1 ,now I'm receive the update."<<std::endl;
}




ObserverReceive2::ObserverReceive2(Click* c){
  m_click = c;
  m_click->Attach(this);
}

ObserverReceive2::~ObserverReceive2(){
  m_click->Detach(this);
}
void ObserverReceive2::Update(Subject *change) {
  if(change == m_click){
    DisplayInfo();
  }
}
void ObserverReceive2::DisplayInfo() {
  std::cout<<"I am ObserverReceive2 ,now I'm receive the update."<<std::endl;
}