#include <iostream>
#include <cstdlib>
#include <string>

enum DIGIT{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
enum OPERATION{ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, SQRT, EQUAl};
enum STATE{gettingOperandOne, gettingOperandTwo};

using namespace std;

class Display{
  private:
    float result;

  public:
    Display(){
      this->result = 0;
    }

    void setDigit(float number){
      cout << number;
    };

    void clear(){
      cout << "\n";
      this->result = 0;
    };
};

class CPU{
  private:
    int maxDigits = 8;
    STATE state;
    OPERATION mathOperator;
    Display *display;
    DIGIT *operandOne;
    DIGIT *operandTwo;
    int operandOneCounter;
    int operandTwoCounter;

    float convertOperand(DIGIT *operand, int operandCounter){
      float result = 0;

      for(int i = 0; i < operandCounter; i++){
        result *= 10;
        result += operand[i];
      }

      return result;
    }

  public:
    CPU(){
      this->state = gettingOperandOne;
      this->operandOne = new DIGIT[this->maxDigits];
      this->operandTwo = new DIGIT[this->maxDigits];
      this->operandOneCounter = 0;
      this->operandTwoCounter = 0;
    }

    ~CPU(){
      delete this->operandOne;
      delete this->operandTwo;
    }

    void setDisplay(Display *display){
      this->display = display;
    }

    void dispatchDigit(DIGIT number){
      if(this->operandOneCounter >= this->maxDigits) return;
      if(this->operandTwoCounter >= this->maxDigits) return;

      this->display->setDigit(number);

      if(this->state == gettingOperandOne){
        this->operandOne[this->operandOneCounter] = number;
        this->operandOneCounter++;
      }else{
        this->operandTwo[this->operandTwoCounter] = number;
        this->operandTwoCounter++;
      }
    }

    void setOperator(OPERATION op){
      this->display->clear();

      if(this->state == gettingOperandOne){
        this->state = gettingOperandTwo;
      }else{
        this->calculate();
      }

      this->mathOperator = op;
    }

    void reset();

    void calculate(){
      float resultOperandA = this->convertOperand(this->operandOne, this->operandOneCounter);
      float resultOperandB = this->convertOperand(this->operandTwo, this->operandTwoCounter);
      
      switch (this->mathOperator){
      case ADDITION:
        this->display->setDigit(resultOperandA+resultOperandB);
        break;
      case SUBTRACTION:
        this->display->setDigit(resultOperandA-resultOperandB);
        break;
      case DIVISION:
        this->display->setDigit(resultOperandA/resultOperandB);
        break;
      case MULTIPLICATION:
        this->display->setDigit(resultOperandA*resultOperandB);
        break;
      case SQRT:
        break;
      }
    }
};

class OperationKeyBoard{
  private:
    CPU *cpu;

  public:
    OperationKeyBoard(){};

    void setCPU(CPU *cpu){
      this->cpu = cpu;
    }

    void pressAddition(){
      this->cpu->setOperator(ADDITION);
    }

    void pressDivision(){
      this->cpu->setOperator(DIVISION);
    }

    void pressMultiplication(){
      this->cpu->setOperator(MULTIPLICATION);
    }

    void pressSquareRoot(){
      this->cpu->setOperator(SQRT);
    }

    void pressSubtraction(){
      this->cpu->setOperator(SUBTRACTION);
    }

    void pressEquals(){
      this->cpu->setOperator(EQUAl);
    }

};

class NumericKeyBoard{
  private:
    CPU *cpu;

  public:
    NumericKeyBoard(){};

    void setCPU(CPU *cpu){
      this->cpu = cpu;
    }

    void pressZero(){
      this->cpu->dispatchDigit(ZERO);
    };

    void pressOne(){
      this->cpu->dispatchDigit(ONE);
    };

    void pressTwo(){
      this->cpu->dispatchDigit(TWO);
    };

    void pressThree(){
      this->cpu->dispatchDigit(THREE);
    };

    void pressFour(){
      this->cpu->dispatchDigit(FOUR);
    };

    void pressFive(){
      this->cpu->dispatchDigit(FIVE);
    };

    void pressSix(){
      this->cpu->dispatchDigit(SIX);
    };
    
    void pressSeven(){
      this->cpu->dispatchDigit(SEVEN);
    };

    void pressEight(){
      this->cpu->dispatchDigit(EIGHT);
    };

    void pressNine(){
      this->cpu->dispatchDigit(NINE);
    };
};

class Calculator{
  private:
    CPU *cpu;
    Display *display;
    NumericKeyBoard *numericKeyBoard;
    OperationKeyBoard *operationKeyBoard;

  public:
    Calculator(){
      this->display = new Display();
      this->cpu = new CPU();
      this->numericKeyBoard = new NumericKeyBoard();
      this->operationKeyBoard = new OperationKeyBoard();

      this->cpu->setDisplay(this->display);
      this->numericKeyBoard->setCPU(this->cpu);
      this->operationKeyBoard->setCPU(this->cpu);
    }

    ~Calculator(){
      delete this->cpu;
      delete this->display;
      delete this->numericKeyBoard;
      delete this->operationKeyBoard;
    }

    NumericKeyBoard *getNumericKeyBoard(){
      return this->numericKeyBoard;
    }

    OperationKeyBoard *getOperationKeyBoard(){
      return this->operationKeyBoard;
    }
};

int main(int argc, char* argv[]){

  Calculator *calc = new Calculator();

  calc->getNumericKeyBoard()->pressOne();
  calc->getNumericKeyBoard()->pressFour();
  calc->getOperationKeyBoard()->pressAddition();
  calc->getNumericKeyBoard()->pressTwo();
  calc->getOperationKeyBoard()->pressEquals();

  return 0;
}