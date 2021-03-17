#include "../myCalculator.h"
#include <math.h>
#include <exception>
#include <string>

// PUBLIC (+)
MyCpu::MyCpu(){
  this->operandOneCounter = 0;
  this->operandTwoCounter = 0;
  this->operation = NONE;
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
  if(this->operation != NONE) {
    this->calculate();
    this->operation = NONE;
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
}

int MyCpu::digitToInt(Digit *operand, int count){
  int result = 0;
  for(int i = 0; i < count; i++){
    result *= 10;
    result += operand[i];
  }
  return result;
}

void MyCpu::intToDigit(int result){
  int size = std::to_string(result).size();
  Digit resultInDigits[size];
  for(int i = size-1; i >= 0; i--){
    resultInDigits[i] = Digit(int(result % 10));
    result /= 10;
  }
  for(Digit x: resultInDigits)
    this->display->addDigit(x);
}

void MyCpu::calculate(){
  int n1 = digitToInt(this->operandOne, this->operandOneCounter);
  int n2 = digitToInt(this->operandTwo, this->operandTwoCounter);
  switch (this->operation){
  case ADDITION:
    this->intToDigit(n1+n2);
    break;
  case SUBTRACTION:
    this->intToDigit(n1-n2);
    break;
  case DIVISION:
    this->intToDigit(n1/n2);
    break;
  case MULTIPLICATION:
    this->intToDigit(n1*n2);
    break;
  }
}
