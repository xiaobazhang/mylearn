/**
 * Created by suli on 17/2/25.
 */
#include "SimpleFactory.h"

int main(void)
{
  Factory* factory = new Factory();
  Product* productA = factory->CreateProduct(TypeA);
  productA->show();

  Product* productB = factory->CreateProduct(TypeB);
  productB->show();

  Product* productC = factory->CreateProduct(TypeC);
  productC->show();

  delete productA;
  delete productB;
  delete productC;
  delete factory;
}
