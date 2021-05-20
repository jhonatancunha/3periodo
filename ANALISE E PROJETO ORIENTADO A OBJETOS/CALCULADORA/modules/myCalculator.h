#pragma once
#include "interface.h"
#include <iostream>

class MyDisplay: public Display{
  private:
    float result;

  public:
    MyDisplay();
    void addDigit(DIGIT number);
    void clear();
};

class MyCPU: public CPU{
  private:
    static const int maxDigits = 8;
    Display *display;
    DIGIT operandOne[maxDigits];
    DIGIT operandTwo[maxDigits];
    int operandOneCounter;
    int operandTwoCounter;
    OPERATION mathOperator;

    void intToDigit(int result);
    int digitToInt(DIGIT *operand, int count);

  public:
    MyCPU();
    void setDisplay(Display *display);
    void dispatchDigit(DIGIT digit);
    void setOperator(OPERATION mathOperator);
    void reset();
    void calculate();
};

class MyOperationKeyBoard: public OperationKeyBoard{
  private:
    CPU *cpu;
  public:
    MyOperationKeyBoard();
    void setCPU(CPU *cpu);
    void pressAddition();
    void pressDivision();
    void pressMultiplication();
    void pressSquareRoot();
    void pressSubtraction();
    void pressEquals();
};

class MyNumericKeyBoard: public NumericKeyBoard{
  private:
    CPU *cpu;
  public:
    MyNumericKeyBoard();
    void setCPU(CPU *cpu);
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

class MyCalculator: public Calculator{
  private:
    CPU *cpu;
    Display *display;
    NumericKeyBoard *numericKeyBoard;
    OperationKeyBoard *operationKeyBoard;

  public:
    MyCalculator(CPU *cpu, Display *display, NumericKeyBoard *numericKeyBoard, OperationKeyBoard *OperationKeyBoard);
    ~MyCalculator();
    void setCPU(CPU *cpu);
    void setDisplay(Display *display);
    void setNumericKeyBoard(NumericKeyBoard *numericKeyBoard);
    void setOperationKeyBoard(OperationKeyBoard *operationKeyBoard);
    NumericKeyBoard* getNumericKeyBoard();
    OperationKeyBoard* getOperationKeyBoard();
    void pressCE();
};
