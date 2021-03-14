#include "myCalc.h"
#include <cstdlib>
// PUBLIC (+)


MyCalculator::MyCalculator(){
  this->display = new MyDisplay();
  this->cpu = new MyCPU();
  this->numericKeyBoard = new MyNumericKeyBoard();
  this->operationKeyBoard = new MyOperationKeyBoard();

  this->cpu->setDisplay(this->display);
  this->numericKeyBoard->setCPU(this->cpu);
  this->operationKeyBoard->setCPU(this->cpu);
}

MyCalculator::~MyCalculator(){
  delete this->cpu;
  delete this->display;
  delete this->numericKeyBoard;
  delete this->operationKeyBoard;
}

MyNumericKeyBoard* MyCalculator::getNumericKeyBoard(){
  return this->numericKeyBoard;
}

MyOperationKeyBoard* MyCalculator::getOperationKeyBoard(){
  return this->operationKeyBoard;
}

void MyCalculator::pressCE(){
  this->cpu->reset();
  this->display->clear();
  this->display->clear();
}