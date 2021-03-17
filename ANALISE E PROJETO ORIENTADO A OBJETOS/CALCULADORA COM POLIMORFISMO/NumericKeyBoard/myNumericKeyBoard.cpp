#include "../myCalculator.h"

// PUBLIC (+)
void MyNumericKeyBoard::setCpu(Cpu *cpu){
  this->cpu = cpu;
}

void MyNumericKeyBoard::pressZero(){
  this->cpu->receiveDigit(ZERO);
}

void MyNumericKeyBoard::pressOne(){
  this->cpu->receiveDigit(ONE);
}

void MyNumericKeyBoard::pressTwo(){
  this->cpu->receiveDigit(TWO);
}

void MyNumericKeyBoard::pressThree(){
  this->cpu->receiveDigit(THREE);
}

void MyNumericKeyBoard::pressFour(){
  this->cpu->receiveDigit(FOUR);
}

void MyNumericKeyBoard::pressFive(){
  this->cpu->receiveDigit(FIVE);
}

void MyNumericKeyBoard::pressSix(){
  this->cpu->receiveDigit(SIX);
}

void MyNumericKeyBoard::pressSeven(){
  this->cpu->receiveDigit(SEVEN);
}

void MyNumericKeyBoard::pressEight(){
  this->cpu->receiveDigit(EIGHT);
}

void MyNumericKeyBoard::pressNine(){
  this->cpu->receiveDigit(NINE);
}