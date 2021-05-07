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

using namespace std;

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


  Calculator *c1 = new JhonatanCalculator(cpu2 , display3, numKey1, opKey4);
  Calculator *c2 = new JhonatanCalculator(cpu1 , display3, numKey4, opKey2);
  Calculator *c3 = new JhonatanCalculator(cpu3 , display2, numKey1, opKey4);
  Calculator *c4 = new JhonatanCalculator(cpu4 , display1, numKey2, opKey3);


  cout << "=======================================" << '\n';
  cout << "TESTANDO CALCULADORA 1" << '\n';
  cout << "CPU: Jesse Pires\nDisplay: Nakao\nNumericKeyBoard: Arthur\nOperationKeyBoard: Jhonatan Cunha\n";
  cout << "=======================================" << '\n';
  CalculatorTest::run(c1);  

  cout << "=======================================" << '\n';
  cout << "TESTANDO CALCULADORA 2" << '\n';
  cout << "CPU: Arthur\nDisplay: Nakao\nNumericKeyBoard: Jhonatan Cunha\nOperationKeyBoard: Jesse Pires\n";
  cout << "=======================================" << '\n';
  CalculatorTest::run(c2);  

  cout << "=======================================" << '\n';
  cout << "TESTANDO CALCULADORA 3" << '\n';
  cout << "CPU: Nakao\nDisplay: Jesse Pires\nNumericKeyBoard: Arthur\nOperationKeyBoard: Jhonatan Cunha\n";
  cout << "=======================================" << '\n';
  CalculatorTest::run(c3);

  cout << "=======================================" << '\n';
  cout << "TESTANDO CALCULADORA 4" << '\n';
  cout << "CPU: Jhonatan Cunha\nDisplay: Arthur\nNumericKeyBoard: Jesse Pires\nOperationKeyBoard: Nakao\n";
  cout << "=======================================" << '\n';
  CalculatorTest::run(c4);  

  return 0;
}