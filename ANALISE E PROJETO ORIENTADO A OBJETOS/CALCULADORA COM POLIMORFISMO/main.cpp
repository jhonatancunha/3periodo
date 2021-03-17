#include <iostream>
#include "myCalculator.h"
#include "myInterfaceTest.cpp"


int main(int argc, char* argv[]){
  Display *myDisplay = new MyDisplay();
  OperationKeyBoard *opKey = new MyOperationKeyBoard();
  NumericKeyBoard *numberKey = new MyNumericKeyBoard();
  Cpu *myCpu = new MyCpu();
  Calculator *myCalc = new MyCalculator(myCpu, myDisplay, numberKey, opKey);
  
  
  CalculatorTest calcTest;
  calcTest.run(myCalc);
  return 0;
}