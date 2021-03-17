#include "../myCalculator.h"

// PUBLIC (+)
void MyOperationKeyBoard::setCpu(Cpu *cpu){
  this->cpu = cpu;
}

void MyOperationKeyBoard::pressAddition(){
  this->cpu->receiveOperation(ADDITION);
}

void MyOperationKeyBoard::pressDivision(){
  this->cpu->receiveOperation(DIVISION);
}

void MyOperationKeyBoard::pressMultiplication(){
  this->cpu->receiveOperation(MULTIPLICATION);
}


void MyOperationKeyBoard::pressSubtraction(){
  this->cpu->receiveOperation(SUBTRACTION);
}

void MyOperationKeyBoard::pressEquals(){
  this->cpu->receiveOperation(EQUAL);
}
