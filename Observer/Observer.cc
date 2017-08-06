//
// Created by suli on 17/1/5.
//

#include "Observer.h"
#include <list>

using namespace std;
void Subject::Attach(Observer * observer)
{
  _observer.push_back(observer);
}

void Subject::Detach(Observer * observer)
{
  vector<Observer*>::iterator iter = _observer.begin();
  while (iter != _observer.end()){
    if((*iter) == observer)
      _observer.erase(iter);
  }
}
void Subject::Notify()
{
  vector<Observer*>::iterator iter = _observer.begin();
  for(;iter != _observer.end();iter++){
    (*iter)->Update(this);
  }
}