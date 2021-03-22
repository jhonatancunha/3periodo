#include "../myCalculator.h"
#include <cstdlib>

// PUBLIC (+)
MyCalculator::MyCalculator(Cpu *cpu, Display *display, NumericKeyBoard *numericKeyBoard, OperationKeyBoard *operationKeyBoard){
  
  this->setCpu(cpu);
  this->setDisplay(display);
  this->setNumericKeyBoard(numericKeyBoard);
  this->setOperationKeyBoard(operationKeyBoard);
  
  this->cpu->setDisplay(display);
  this->numericKeyBoard->setCpu(cpu);
  this->operationKeyBoard->setCpu(cpu);
}

MyCalculator::~MyCalculator(){
  delete this->cpu;
  delete this->display;
  delete this->numericKeyBoard;
  delete this->operationKeyBoard;
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

void MyCalculator::setDisplay(Display *display){
  this->display = display;
}

Display* MyCalculator::getDisplay(){
  return this->display;
}

void MyCalculator::setCpu(Cpu* cpu){
  this->cpu = cpu;
}

Cpu* MyCalculator::getCpu(){
  return this->cpu;
}