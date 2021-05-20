#include <iostream>

enum DIGIT{ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE};
enum OPERATION{ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, SQRT , EQUAl, NONE};

class Display{
  public:
    virtual void addDigit(DIGIT number) = 0;
    virtual void clear() = 0;
};

class CPU{
  public:
    virtual void setDisplay(Display *display) = 0;
    virtual void dispatchDigit(DIGIT digit) = 0;
    virtual void setOperator(OPERATION mathOperator) = 0;
    virtual void reset() = 0;
    virtual void calculate() = 0;
};

class OperationKeyBoard{
  public:
    virtual void setCPU(CPU *cpu) = 0;
    virtual void pressAddition() = 0;
    virtual void pressDivision() = 0;
    virtual void pressMultiplication() = 0;
    virtual void pressSquareRoot() = 0;
    virtual void pressSubtraction() = 0;
    virtual void pressEquals() = 0;
};

class NumericKeyBoard{
  public:
    virtual void setCPU(CPU *cpu) = 0;
    virtual void pressZero() = 0;
    virtual void pressOne() = 0;
    virtual void pressTwo() = 0;
    virtual void pressThree() = 0;
    virtual void pressFour() = 0;
    virtual void pressFive() = 0;
    virtual void pressSix() = 0;
    virtual void pressSeven() = 0;
    virtual void pressEight() = 0;
    virtual void pressNine() = 0;
};

class Calculator{
  public:
    virtual void setCPU(CPU *cpu) = 0;
    virtual void setDisplay(Display *cpu) = 0;
    virtual void setNumericKeyBoard(NumericKeyBoard *cpu) = 0;
    virtual void setOperationKeyBoard(OperationKeyBoard *cpu) = 0;
    virtual NumericKeyBoard* getNumericKeyBoard() = 0;
    virtual OperationKeyBoard* getOperationKeyBoard() = 0;
    virtual void pressCE() = 0;
};