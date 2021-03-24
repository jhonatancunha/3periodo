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

//NAKAO
#include "MatheusKenjiNakao/calculatorNakao.cpp"

int main(int argc, char* argv[]){
  Display * display1 = new ArthurDisplay();  
  Display * display2 = new DisplayJessePires();  
  Display * display3 = new NakaoDisplay();   

 
  Cpu * cpu1 = new ArthurCpu();
  Cpu * cpu2 = new CpuJessePires();
  Cpu * cpu3 = new NakaoCpu();


  OperationKeyBoard *opKey1 = new ArthurOperationKeyBoard();
  OperationKeyBoard *opKey2 = new OperationKeyBoardJessePires();
  OperationKeyBoard *opKey3 = new NakaoOperationKeyBoard();



  NumericKeyBoard *numKey1 = new ArthurNumericKeyBoard();
  NumericKeyBoard *numKey2 = new NumericKeyBoardJessePires();
  NumericKeyBoard *numKey3 = new NakaoNumericKeyBoard();


  Calculator *c1 = new JhonatanCalculator(cpu1 , display1, numKey1, opKey1);
  Calculator *c2 = new JhonatanCalculator(cpu2 , display2, numKey2, opKey2);
  Calculator *c3 = new JhonatanCalculator(cpu3 , display3, numKey3, opKey3);


  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA 1" << '\n';
  std::cout << "=======================================" << '\n';
  CalculatorTest::run(c1);  

  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA 2" << '\n';
  std::cout << "=======================================" << '\n';
  CalculatorTest::run(c2);  

  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA 3" << '\n';
  std::cout << "=======================================" << '\n';
  CalculatorTest::run(c3);  

  return 0;
}