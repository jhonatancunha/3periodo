#include "../myCalculator.h"

// PUBLIC (+)
MyNumericKeyBoard::MyNumericKeyBoard(){};

void MyNumericKeyBoard::setCPU(CPU *cpu){
  this->cpu = cpu;
}

void MyNumericKeyBoard::pressZero(){
  this->cpu->dispatchDigit(ZERO);
}

void MyNumericKeyBoard::pressOne(){
  this->cpu->dispatchDigit(ONE);
}

void MyNumericKeyBoard::pressTwo(){
  this->cpu->dispatchDigit(TWO);
}

void MyNumericKeyBoard::pressThree(){
  this->cpu->dispatchDigit(THREE);
}

void MyNumericKeyBoard::pressFour(){
  this->cpu->dispatchDigit(FOUR);
}

void MyNumericKeyBoard::pressFive(){
  this->cpu->dispatchDigit(FIVE);
}

void MyNumericKeyBoard::pressSix(){
  this->cpu->dispatchDigit(SIX);
}

void MyNumericKeyBoard::pressSeven(){
  this->cpu->dispatchDigit(SEVEN);
}

void MyNumericKeyBoard::pressEight(){
  this->cpu->dispatchDigit(EIGHT);
}

void MyNumericKeyBoard::pressNine(){
  this->cpu->dispatchDigit(NINE);
}