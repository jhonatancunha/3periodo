#include <iostream>
using namespace std;

enum DIGIT{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVE, EIGHT, NINE};

class CPU{
  private:

  public:
};

class Display{
  private:
    float result;

  public:
    Display(){
      this->result = 0;
    }

    void setDigit(DIGIT number);
    void clear();
};

class OperationKeyBoard{
  private:
    CPU *cpu;

  public:
    OperationKeyBoard(CPU *processor){
      this->cpu = processor;
    }

    void pressAddition();
    void pressDivision();
    void pressMultiplication();
    void pressSquareRoot();
    void pressSubtraction();

};

class NumericKeyBoard{
  private:
    CPU *cpu;

  public:
    NumericKeyBoard(CPU *processor){
      this->cpu = processor;
    }

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

class Calculator{
  private:
    CPU *cpu;
    Display *display;
    NumericKeyBoard *numericKeyBoard;
    OperationKeyBoard *operationKeyBoard;

  public:
    Calculator(){
      this->cpu = new CPU();
      this->display = new Display();
      this->numericKeyBoard = new NumericKeyBoard(this->cpu);
      this->operationKeyBoard = new OperationKeyBoard(this->cpu);
    }
};

int main(int argc, char* argv[]){

  cout << "Hello Word!";
  return 0;
}