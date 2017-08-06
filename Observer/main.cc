#include <iostream>
#include "Simple.h"
using namespace std;


int main(){

  Click* myclick = new Click();
  ObserverReceive1 *ob1 = new ObserverReceive1(myclick);
  ObserverReceive2 *ob2 = new ObserverReceive2(myclick);
  myclick->SecondClick();
  return 0;
}