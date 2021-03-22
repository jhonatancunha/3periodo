#include "../myCalculator.h"
#include <math.h>
#include <exception>
#include <string>

// PUBLIC (+)
MyCpu::MyCpu(){
  this->operandOneCounter = 0;
  this->operandTwoCounter = 0;
  this->operation = NONE;
  this->signal = POSITIVE;
}

void MyCpu::setDisplay(Display *display){
  this->display = display;
}

void MyCpu::receiveDigit(Digit digit){
  try{
    if(this->operandOneCounter >= this->maxDigits) throw;
    if(this->operandTwoCounter >= this->maxDigits) throw;
    
    this->display->addDigit(digit);
    
    if(this->operation == NONE){
      this->operandOne[this->operandOneCounter] = digit;
      this->operandOneCounter++;
    }else{
      this->operandTwo[this->operandTwoCounter] = digit;
      this->operandTwoCounter++;
    }
  }catch(...){}

}

void MyCpu::receiveOperation(Operation operation){
  this->display->clear();

  if(operation == EQUAL) {
    this->calculate();
    return;
  }

  this->operation = operation;
}

void MyCpu::cancel(){
  this->display->clear();

  if(this->operation == NONE){
    this->operandOneCounter = 0;
  }else{
    this->operandTwoCounter = 0;
  }
}

void MyCpu::reset(){
  this->operandOneCounter = 0;
  this->operandTwoCounter = 0;
  this->operation = NONE;
  this->signal = POSITIVE;
}

int MyCpu::digitToInt(Digit *operand, int count){
  int result = 0;
  
  for(int i = 0; i < count; i++){
    result *= 10;
    result += operand[i];
  }

  return result;
}

void MyCpu::intToDigit(int number, Digit *digit, int *digitLenght, Signal *signal){
  *digitLenght = 0;

  *signal = (number < 0) ? NEGATIVE : POSITIVE;

  while(number > 0){
    digit[(*digitLenght)++] = Digit(number % 10);
    number /= 10;
  }

  for(int i = 0; i < (*digitLenght)/2; i++){
    Digit temp = digit[i];
    digit[i] = digit[*digitLenght-i-1];
    digit[*digitLenght-i-1] = temp;
  }
}

void MyCpu::calculate(){
  int n1 = digitToInt(this->operandOne, this->operandOneCounter);
  int n2 = digitToInt(this->operandTwo, this->operandTwoCounter);

  switch (this->operation){
  case ADDITION:
    this->intToDigit(n1+n2, this->operandOne, &this->operandOneCounter, &this->signal);
    break;
  case SUBTRACTION:
    this->intToDigit(n1-n2, this->operandOne, &this->operandOneCounter, &this->signal);
    break;
  case DIVISION:
    this->intToDigit(n1/n2, this->operandOne, &this->operandOneCounter, &this->signal);
    break;
  case MULTIPLICATION:
    this->intToDigit(n1*n2, this->operandOne, &this->operandOneCounter, &this->signal);
    break;
  }

  this->display->setSignal(this->signal);
  for(int i = 0; i < this->operandOneCounter; i++){
    this->display->addDigit(this->operandOne[i]);
  }

  this->operandTwoCounter = 0;

}
