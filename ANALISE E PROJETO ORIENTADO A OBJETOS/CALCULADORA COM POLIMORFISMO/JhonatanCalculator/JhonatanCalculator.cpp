#include "../JhonatanCalculator.h"
#include <cstdlib>

// PUBLIC (+)
JhonatanCalculator::JhonatanCalculator(Cpu *cpu, Display *display, NumericKeyBoard *numericKeyBoard, OperationKeyBoard *operationKeyBoard){
  
  this->setCpu(cpu);
  this->setDisplay(display);
  this->setNumericKeyBoard(numericKeyBoard);
  this->setOperationKeyBoard(operationKeyBoard);
  
  this->cpu->setDisplay(display);
  this->numericKeyBoard->setCpu(cpu);
  this->operationKeyBoard->setCpu(cpu);
}

JhonatanCalculator::~JhonatanCalculator(){
  delete this->cpu;
  delete this->display;
  delete this->numericKeyBoard;
  delete this->operationKeyBoard;
}

void JhonatanCalculator::setNumericKeyBoard(NumericKeyBoard *numericKeyBoard){
  this->numericKeyBoard = numericKeyBoard;
}

void JhonatanCalculator::setOperationKeyBoard(OperationKeyBoard *operationKeyBoard){
  this->operationKeyBoard = operationKeyBoard;
}

NumericKeyBoard* JhonatanCalculator::getNumericKeyBoard(){
  return this->numericKeyBoard;
}

OperationKeyBoard* JhonatanCalculator::getOperationKeyBoard(){
  return this->operationKeyBoard;
}

void JhonatanCalculator::setDisplay(Display *display){
  this->display = display;
}

Display* JhonatanCalculator::getDisplay(){
  return this->display;
}

void JhonatanCalculator::setCpu(Cpu* cpu){
  this->cpu = cpu;
}

Cpu* JhonatanCalculator::getCpu(){
  return this->cpu;
}