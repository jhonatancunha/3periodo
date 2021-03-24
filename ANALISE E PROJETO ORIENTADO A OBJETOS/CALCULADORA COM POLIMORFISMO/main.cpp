#include <iostream>
#include "JhonatanCalculator.h"
#include "InterfaceTest.cpp"

//JESSÉ PIRES BARBATO ROCHA
#include "CalculatorJessePires/Components/CpuJessePires/CpuJessePires.h"
#include "CalculatorJessePires/Components/DisplayJessePires/DisplayJessePires.h"
#include "CalculatorJessePires/Components/NumericKeyBoardJessePires/NumericKeyBoardJessePires.h"
#include "CalculatorJessePires/Components/OperationKeyBoardJessePires/OperationKeyBoardJessePires.h"

//ARTHUR DAE SUNG HAN
#include "ArthurDaeSungHanCalc/arthurCalculator.h"

int main(int argc, char* argv[]){
  Display * display1 = new ArthurDisplay();  
  Display * display2 = new DisplayJessePires();  
  Display * display3 = new JhonatanDisplay();   

 
  Cpu * cpu1 = new ArthurCpu();
  Cpu * cpu2 = new CpuJessePires();

  OperationKeyBoard *opKey1 = new ArthurOperationKeyBoard();
  OperationKeyBoard *opKey2 = new OperationKeyBoardJessePires();



  NumericKeyBoard *numKey1 = new ArthurNumericKeyBoard();
  NumericKeyBoard *numKey2 = new NumericKeyBoardJessePires();
  

  Calculator *c1 = new JhonatanCalculator(cpu1 ,display1, numKey1, opKey1);


  Calculator *c2 = new JhonatanCalculator(cpu2 ,display2, numKey2, opKey2);


  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA 1" << '\n';
  std::cout << "=======================================" << '\n';
  // CalculatorTest::run(c1);  

  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA 2" << '\n';
  std::cout << "=======================================" << '\n';
  CalculatorTest::run(c2);  

  // CalculatorTest::run(c3);  
  // CalculatorTest::run(c4);  

  return 0;
}