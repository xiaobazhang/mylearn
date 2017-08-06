/**
 * Created by suli on 17/2/25.
 */

#ifndef MYLEARN_SIMPLEFACTORY_H_H
#define MYLEARN_SIMPLEFACTORY_H_H
#include <vector>
#include <iostream>

using namespace std;

typedef enum ProductType{
  TypeA = 1,
  TypeB,
  TypeC
}PRODUCTTYPE;

class Product{
 public:
  virtual void show() = 0;
  virtual ~Product(){};
};

class ProductA : public Product{
 public:
  void show()
  {
    cout<<"This is ProductA"<<endl;
  }
};

class ProductB : public  Product{
 public:
  void show()
  {
    cout<<"This is ProductB"<<endl;
  }
};

class ProductC : public Product{
 public:
  void show()
  {
    cout<<"This is ProductC"<<endl;
  }
};

class Factory{
 public:
  Product* CreateProduct(PRODUCTTYPE type){
    switch(type){
      case TypeA:
        return new ProductA();
      case TypeB:
        return new ProductB();
      case TypeC:
        return new ProductC();
      default:
        return NULL;
    }
  }
};



#endif //MYLEARN_SIMPLEFACTORY_H_H
