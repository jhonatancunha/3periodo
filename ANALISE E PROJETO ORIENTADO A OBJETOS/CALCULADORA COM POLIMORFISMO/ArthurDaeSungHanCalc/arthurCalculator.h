/*
 * Header file with the calculator methods.
 */

#pragma once 

#include "calculator.h"
#include "stack.h"
#include <iostream>

class ArthurDisplay: public Display{
    public:
        void addDigit(Digit number);
        void addDecimalSeparator();
        void setSignal(Signal signal);
        void clear();
};

class ArthurCpu: public Cpu{
    private:
        Display* display;   
        Operation operation;           
        Signal signal;
        Stack* firstOperand; 
        Stack* secondOperand;  
        bool hasOperator; 

    private:
        int calculateResult(int firstNumber, int secondNumber);
        void getNumber(Stack* operand, int* number);
        void sendToDisplay(Stack* resultInDigits);
        void intToDigit(int result);
        void setOperation();

    public:
        ArthurCpu();
        void setDisplay(Display* display);
        void receiveDigit(Digit digit);
        void receiveOperation(Operation operation);
        void cancel();
        void reset();
};

class ArthurOperationKeyBoard: public OperationKeyBoard{
    private:
        Cpu* cpu;
    public:
        ArthurOperationKeyBoard();
        void setCpu(Cpu *cpu);
        void pressAddition();
        void pressDivision();
        void pressMultiplication();
        void pressSubtraction();
        void pressEquals();
};

class ArthurNumericKeyBoard: public NumericKeyBoard{
    private:
        Cpu* cpu;
    public:
        ArthurNumericKeyBoard();
        void setCpu(Cpu *cpu);
        void pressZero();
        void pressOne();
        void pressTwo();
        void pressThree();
        void pressFour();
        void pressFive();
        void pressSix();
        void pressSeven();
        void pressEight();
        void pressNine();
};

class ArthurCalculator: public Calculator{
    private:
        Display* display;
        Cpu* cpu;
        NumericKeyBoard* numericKeyBoard; 
        OperationKeyBoard* operationKeyBoard;
    public: 
        ArthurCalculator(Cpu *cpu, Display *display, NumericKeyBoard *numericKeyBoard, OperationKeyBoard *operationKeyBoard);
        ~ArthurCalculator();
        //getters
        void setNumericKeyBoard(NumericKeyBoard* numericKeyBoard);
        void setOperationKeyBoard(OperationKeyBoard* operationKeyBoard);
        void setDisplay(Display* display);
        void setCpu(Cpu* cpu);
        //setters
        NumericKeyBoard* getNumericKeyBoard();
        OperationKeyBoard* getOperationKeyBoard();
        Display* getDisplay();
        Cpu* getCpu();
};
