#include "../JhonatanCalculator.h"

// PUBLIC (+)
void JhonatanOperationKeyBoard::setCpu(Cpu *cpu){
  this->cpu = cpu;
}

void JhonatanOperationKeyBoard::pressAddition(){
  this->cpu->receiveOperation(ADDITION);
}

void JhonatanOperationKeyBoard::pressDivision(){
  this->cpu->receiveOperation(DIVISION);
}

void JhonatanOperationKeyBoard::pressMultiplication(){
  this->cpu->receiveOperation(MULTIPLICATION);
}


void JhonatanOperationKeyBoard::pressSubtraction(){
  this->cpu->receiveOperation(SUBTRACTION);
}

void JhonatanOperationKeyBoard::pressEquals(){
  this->cpu->receiveOperation(EQUAL);
}
