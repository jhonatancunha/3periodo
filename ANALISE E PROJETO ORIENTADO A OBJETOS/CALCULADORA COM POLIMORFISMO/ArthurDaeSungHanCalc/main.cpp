#include "arthurCalculator.h"
#include "calculatorTest.cpp"

int main(){
    
    Display* display = new ArthurDisplay();
    Cpu* cpu = new ArthurCpu();
    NumericKeyBoard* numericKeyBoard = new ArthurNumericKeyBoard(); 
    OperationKeyBoard* operationKeyBoard = new ArthurOperationKeyBoard();

    Calculator* calculator = new ArthurCalculator(cpu, display, numericKeyBoard, operationKeyBoard);
    
    CalculatorTest::run(calculator);

    delete display;
    delete cpu;
    delete numericKeyBoard;
    delete operationKeyBoard;    
    delete calculator;

    return 0;
}