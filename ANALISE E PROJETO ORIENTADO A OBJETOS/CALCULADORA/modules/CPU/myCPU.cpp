#include "../myCalculator.h"
#include <math.h>
#include <exception>
#include <string>

// PUBLIC (+)
MyCPU::MyCPU(){
  this->operandOneCounter = 0;
  this->operandTwoCounter = 0;
  this->mathOperator = NONE;
}

void MyCPU::setDisplay(MyDisplay *display){
  this->display = display;
}

void MyCPU::dispatchDigit(DIGIT digit){
  try{
    if(this->operandOneCounter >= this->maxDigits) throw;
    if(this->operandTwoCounter >= this->maxDigits) throw;
    
    this->display->addDigit(digit);
    if(this->mathOperator == NONE){
      this->operandOne[this->operandOneCounter] = digit;
      this->operandOneCounter++;
    }else{
      this->operandTwo[this->operandTwoCounter] = digit;
      this->operandTwoCounter++;
    }
  }catch(...){}

}

void MyCPU::setOperator(OPERATION mathOperator){
  this->display->clear();
  if(this->mathOperator != NONE) {
    this->calculate();
    this->mathOperator = NONE;
    return;
  }

  this->mathOperator = mathOperator;
}

void MyCPU::reset(){
  this->operandOneCounter = 0;
  this->operandTwoCounter = 0;
  this->mathOperator = NONE;
}

int MyCPU::digitToInt(DIGIT *operand, int count){
  int result = 0;

  for(int i = 0; i < count; i++){
    result *= 10;
    result += operand[i];
  }

  return result;
}

void MyCPU::intToDigit(int result){
  int size = std::to_string(result).size();
  DIGIT resultInDigits[size];

  for(int i = size-1; i >= 0; i--){
    resultInDigits[i] = DIGIT(int(result % 10));
    result /= 10;
  }

  for(DIGIT x: resultInDigits)
    this->display->addDigit(x);

}

void MyCPU::calculate(){
  int n1 = digitToInt(this->operandOne, this->operandOneCounter);
  int n2 = digitToInt(this->operandTwo, this->operandTwoCounter);

  switch (this->mathOperator){
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
  case SQRT:
      if(n1 > 0) this->intToDigit(sqrt(n1));
      else this->intToDigit(sqrt(n2));
    break;
  }
}
