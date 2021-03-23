#include <iostream>
#include "JhonatanCalculator.h"
#include "InterfaceTest.cpp"


int main(int argc, char* argv[]){
  Display *display = new JhonatanDisplay();
  OperationKeyBoard *operationKeyBoard = new JhonatanOperationKeyBoard();
  NumericKeyBoard *numericKeyBoard = new JhonatanNumericKeyBoard();
  Cpu *cpu = new JhonatanCpu();
  Calculator *JhonatanCalc = new JhonatanCalculator(cpu, display, numericKeyBoard, operationKeyBoard);
  
  
  CalculatorTest::run(JhonatanCalc);

  return 0;
}