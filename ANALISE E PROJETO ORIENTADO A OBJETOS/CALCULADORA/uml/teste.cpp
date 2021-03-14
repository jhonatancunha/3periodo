#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <stdexcept>


enum DIGIT{ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE };
enum OPERATION{ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, SQRT , EQUAl, NONE};
enum STATE{gettingOperandOne, gettingOperandTwo};

using namespace std;

//OK
class Display{
  private:
    float result;

  public:
    Display(){
      this->result = 0;
    }

    void addDigit(float number){
      cout << number;
    };

    void addOperation(OPERATION op){
      switch(op){
        case ADDITION:
          cout << '+';
          break;
        case SUBTRACTION:
          cout << '-';
          break;
        case DIVISION:
          cout << '/';
          break;
        case MULTIPLICATION:
          cout << '*';
          break;
        case SQRT:
          cout << "Sqrt of ";
          break;
        case EQUAl:
          cout << '=';
          break;
      }
    }

    void clear(){
      cout << "\n";
      this->result = 0;
    };

    void addDot(){
      cout << '.';
    }

};

//OK
class CPU{
  private:
    int maxDigits = 8;
    Display *display;
    DIGIT *operandOne;
    DIGIT *operandTwo;
    int operandOneCounter;
    int operandTwoCounter;
    OPERATION mathOperator;
    STATE state;
    int dotCounterOne;
    int dotCounterTwo;

    float convertOperand(DIGIT *operand, int operandCounter, int dotCounter){
      float result = 0;

      for(int i = 0; i < operandCounter; i++){
        result *= 10;
        result += operand[i];
      }

      if(dotCounter > 0)
        return result*(pow(10, -(operandCounter-dotCounter)));
      else 
        return result;
    }

  public:
    CPU(){
      this->state = gettingOperandOne;
      this->operandOne = new DIGIT[this->maxDigits];
      this->operandTwo = new DIGIT[this->maxDigits];
      this->operandOneCounter = 0;
      this->operandTwoCounter = 0;
      this->dotCounterOne = 0;
      this->dotCounterTwo = 0;
    }

    ~CPU(){
      delete this->operandOne;
      delete this->operandTwo;
    }

    void setDisplay(Display *display){
      this->display = display;
    }

    void dispatchDigit(DIGIT digit){
      if(this->operandOneCounter >= this->maxDigits) throw overflow_error();
      if(this->operandTwoCounter >= this->maxDigits) return;

      this->display->addDigit(digit);

      if(this->state == gettingOperandOne){
        this->operandOne[this->operandOneCounter] = digit;
        this->operandOneCounter++;
      }else{
        this->operandTwo[this->operandTwoCounter] = digit;
        this->operandTwoCounter++;
      }
    }

    void setOperator(OPERATION mathOperator){
      this->display->addOperation(mathOperator);

      if(this->state == gettingOperandOne) this->state = gettingOperandTwo;
      else this->calculate();
      this->mathOperator = mathOperator;
    }

    void reset(){
      this->operandOneCounter = 0;
      this->operandTwoCounter = 0;
      this->state = gettingOperandOne;
      this->dotCounterOne = 0;
      this->dotCounterTwo = 0;
    }

    void calculate(){
      float resultOperandA = this->convertOperand(this->operandOne, this->operandOneCounter, this->dotCounterOne);
      float resultOperandB = this->convertOperand(this->operandTwo, this->operandTwoCounter, this->dotCounterTwo);
      
      switch (this->mathOperator){
      case ADDITION:
        this->display->addDigit(resultOperandA+resultOperandB);
        break;
      case SUBTRACTION:
        this->display->addDigit(resultOperandA-resultOperandB);
        break;
      case DIVISION:
        this->display->addDigit(resultOperandA/resultOperandB);
        break;
      case MULTIPLICATION:
        this->display->addDigit(resultOperandA*resultOperandB);
        break;
      case SQRT:
          if(resultOperandA > 0) this->display->addDigit(sqrt(resultOperandB));
          else this->display->addDigit(sqrt(resultOperandB));
        break;
      }
    }

    void setDotCounter(){
      this->display->addDot();

      if(this->state == gettingOperandOne)
        this->dotCounterOne = this->operandOneCounter;
      else
        this->dotCounterTwo = this->operandTwoCounter;
    }
};

//OK
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

//OK
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

    void pressDot(){
      this->cpu->setDotCounter();
    }
};

//OK
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

    void pressCE(){
      this->cpu->reset();
      this->display->clear();
    }
};

int main(int argc, char* argv[]){

  Calculator *calc = new Calculator();

  //1.4+2.5=3.9
  calc->getNumericKeyBoard()->pressOne();
  calc->getNumericKeyBoard()->pressDot();
  calc->getNumericKeyBoard()->pressFour();
  calc->getOperationKeyBoard()->pressAddition();
  calc->getNumericKeyBoard()->pressTwo();
  calc->getNumericKeyBoard()->pressDot();
  calc->getNumericKeyBoard()->pressFive();
  calc->getOperationKeyBoard()->pressEquals();
  calc->pressCE();

  //1.288*20=25.76
  calc->getNumericKeyBoard()->pressOne();
  calc->getNumericKeyBoard()->pressDot();
  calc->getNumericKeyBoard()->pressTwo();
  calc->getNumericKeyBoard()->pressEight();
  calc->getNumericKeyBoard()->pressEight();
  calc->getOperationKeyBoard()->pressMultiplication();
  calc->getNumericKeyBoard()->pressTwo();
  calc->getNumericKeyBoard()->pressZero();
  calc->getOperationKeyBoard()->pressEquals();
  calc->pressCE();

  //√4.2 = 2.04939
  calc->getOperationKeyBoard()->pressSquareRoot();
  calc->getNumericKeyBoard()->pressFour();
  calc->getNumericKeyBoard()->pressDot();
  calc->getNumericKeyBoard()->pressTwo();
  calc->getOperationKeyBoard()->pressEquals();
  calc->pressCE();

  return 0;
}