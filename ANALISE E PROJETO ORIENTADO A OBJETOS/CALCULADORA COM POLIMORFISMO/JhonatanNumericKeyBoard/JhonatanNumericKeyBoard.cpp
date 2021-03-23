#include "../JhonatanCalculator.h"

// PUBLIC (+)
void JhonatanNumericKeyBoard::setCpu(Cpu *cpu){
  this->cpu = cpu;
}

void JhonatanNumericKeyBoard::pressZero(){
  this->cpu->receiveDigit(ZERO);
}

void JhonatanNumericKeyBoard::pressOne(){
  this->cpu->receiveDigit(ONE);
}

void JhonatanNumericKeyBoard::pressTwo(){
  this->cpu->receiveDigit(TWO);
}

void JhonatanNumericKeyBoard::pressThree(){
  this->cpu->receiveDigit(THREE);
}

void JhonatanNumericKeyBoard::pressFour(){
  this->cpu->receiveDigit(FOUR);
}

void JhonatanNumericKeyBoard::pressFive(){
  this->cpu->receiveDigit(FIVE);
}

void JhonatanNumericKeyBoard::pressSix(){
  this->cpu->receiveDigit(SIX);
}

void JhonatanNumericKeyBoard::pressSeven(){
  this->cpu->receiveDigit(SEVEN);
}

void JhonatanNumericKeyBoard::pressEight(){
  this->cpu->receiveDigit(EIGHT);
}

void JhonatanNumericKeyBoard::pressNine(){
  this->cpu->receiveDigit(NINE);
}