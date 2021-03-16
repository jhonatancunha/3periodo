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
    MyDisplay *display;
    DIGIT operandOne[maxDigits];
    DIGIT operandTwo[maxDigits];
    int operandOneCounter;
    int operandTwoCounter;
    OPERATION mathOperator;

    void intToDigit(int result);
    int digitToInt(DIGIT *operand, int count);

  public:
    MyCPU();
    void setDisplay(MyDisplay *display);
    void dispatchDigit(DIGIT digit);
    void setOperator(OPERATION mathOperator);
    void reset();
    void calculate();
};

class MyOperationKeyBoard: public OperationKeyBoard{
  private:
    MyCPU *cpu;
  public:
    MyOperationKeyBoard();
    void setCPU(MyCPU *cpu);
    void pressAddition();
    void pressDivision();
    void pressMultiplication();
    void pressSquareRoot();
    void pressSubtraction();
    void pressEquals();
};

class MyNumericKeyBoard: public NumericKeyBoard{
  private:
    MyCPU *cpu;
  public:
    MyNumericKeyBoard();
    virtual void setCPU(MyCPU *cpu);
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
    MyCPU *cpu;
    MyDisplay *display;
    MyNumericKeyBoard *numericKeyBoard;
    MyOperationKeyBoard *operationKeyBoard;

  public:
    MyCalculator();
    ~MyCalculator();
    MyNumericKeyBoard* getNumericKeyBoard();
    MyOperationKeyBoard* getOperationKeyBoard();
    void pressCE();
};
