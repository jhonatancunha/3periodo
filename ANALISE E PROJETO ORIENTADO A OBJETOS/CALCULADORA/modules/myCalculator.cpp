#include "myCalculator.h"
#include <cstdlib>

// PUBLIC (+)
MyCalculator::MyCalculator(CPU *cpu, Display *display, NumericKeyBoard *numericKeyBoard, OperationKeyBoard *operationKeyBoard){
  
  this->setCPU(cpu);
  this->setDisplay(display);
  this->setNumericKeyBoard(numericKeyBoard);
  this->setOperationKeyBoard(operationKeyBoard);
  
  this->cpu->setDisplay(display);
  this->numericKeyBoard->setCPU(cpu);
  this->operationKeyBoard->setCPU(cpu);
}

MyCalculator::~MyCalculator(){
  delete this->cpu;
  delete this->display;
  delete this->numericKeyBoard;
  delete this->operationKeyBoard;
}

void MyCalculator::setCPU(CPU *cpu){
  this->cpu = cpu;
}

void MyCalculator::setDisplay(Display *display){
  this->display = display;
}

void MyCalculator::setNumericKeyBoard(NumericKeyBoard *numericKeyBoard){
  this->numericKeyBoard = numericKeyBoard;
}

void MyCalculator::setOperationKeyBoard(OperationKeyBoard *operationKeyBoard){
  this->operationKeyBoard = operationKeyBoard;
}

NumericKeyBoard* MyCalculator::getNumericKeyBoard(){
  return this->numericKeyBoard;
}

OperationKeyBoard* MyCalculator::getOperationKeyBoard(){
  return this->operationKeyBoard;
}

void MyCalculator::pressCE(){
  this->cpu->reset();
  this->display->clear();
  this->display->clear();
}