#include <iostream>
#include "myCalc.h"


int main(){
  MyCalculator *c = new MyCalculator();


  //14+25=39
  c->getNumericKeyBoard()->pressOne();
  c->getNumericKeyBoard()->pressFour();
  c->getOperationKeyBoard()->pressAddition();

  c->getNumericKeyBoard()->pressTwo();
  c->getNumericKeyBoard()->pressFive();
  c->getOperationKeyBoard()->pressEquals();
  c->pressCE();

    //1288*20=25760
  c->getNumericKeyBoard()->pressOne();
  c->getNumericKeyBoard()->pressTwo();
  c->getNumericKeyBoard()->pressEight();
  c->getNumericKeyBoard()->pressEight();
  c->getOperationKeyBoard()->pressMultiplication();
  c->getNumericKeyBoard()->pressTwo();
  c->getNumericKeyBoard()->pressZero();
  c->getOperationKeyBoard()->pressEquals();
  c->pressCE();

  //√4 = 2
  c->getOperationKeyBoard()->pressSquareRoot();
  c->getNumericKeyBoard()->pressFour();
  c->getOperationKeyBoard()->pressEquals();
  c->pressCE();
  return 0;
}