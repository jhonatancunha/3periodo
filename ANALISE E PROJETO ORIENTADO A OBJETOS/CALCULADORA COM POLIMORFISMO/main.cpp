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
  Display * display4 = new JhonatanDisplay();   


 
  Cpu * cpu1 = new ArthurCpu();
  Cpu * cpu2 = new CpuJessePires();
  Cpu * cpu3 = new NakaoCpu();
  Cpu * cpu4 = new JhonatanCpu();   



  OperationKeyBoard *opKey1 = new ArthurOperationKeyBoard();
  OperationKeyBoard *opKey2 = new OperationKeyBoardJessePires();
  OperationKeyBoard *opKey3 = new NakaoOperationKeyBoard();
  OperationKeyBoard *opKey4 = new JhonatanOperationKeyBoard();



  NumericKeyBoard *numKey1 = new ArthurNumericKeyBoard();
  NumericKeyBoard *numKey2 = new NumericKeyBoardJessePires();
  NumericKeyBoard *numKey3 = new NakaoNumericKeyBoard();
  NumericKeyBoard *numKey4 = new JhonatanNumericKeyBoard();


  Calculator *c1 = new JhonatanCalculator(cpu1 , display1, numKey2, opKey2);
  Calculator *c2 = new JhonatanCalculator(cpu2 , display2, numKey2, opKey2);
  Calculator *c3 = new JhonatanCalculator(cpu3 , display3, numKey3, opKey3);
  Calculator *c4 = new JhonatanCalculator(cpu4 , display4, numKey4, opKey4);


  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA ARTHUR" << '\n';
  std::cout << "=======================================" << '\n';
  CalculatorTest::run(c1);  

  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA JESSÉ" << '\n';
  std::cout << "=======================================" << '\n';
  CalculatorTest::run(c2);  

  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA NAKAO" << '\n';
  std::cout << "=======================================" << '\n';
  CalculatorTest::run(c3);

  std::cout << "=======================================" << '\n';
  std::cout << "TESTANDO CALCULADORA JHONATAN" << '\n';
  std::cout << "=======================================" << '\n';
  CalculatorTest::run(c4);  

  return 0;
}