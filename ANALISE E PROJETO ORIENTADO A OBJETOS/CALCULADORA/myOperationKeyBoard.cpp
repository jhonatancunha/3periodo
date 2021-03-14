#include "myCalc.h"

// PUBLIC (+)
MyOperationKeyBoard::MyOperationKeyBoard(){};

void MyOperationKeyBoard::setCPU(MyCPU *cpu){
  this->cpu = cpu;
}

void MyOperationKeyBoard::pressAddition(){
  this->cpu->setOperator(ADDITION);
}

void MyOperationKeyBoard::pressDivision(){
  this->cpu->setOperator(DIVISION);
}

void MyOperationKeyBoard::pressMultiplication(){
  this->cpu->setOperator(MULTIPLICATION);
}

void MyOperationKeyBoard::pressSquareRoot(){
  this->cpu->setOperator(SQRT);
}

void MyOperationKeyBoard::pressSubtraction(){
  this->cpu->setOperator(SUBTRACTION);
}

void MyOperationKeyBoard::pressEquals(){
  this->cpu->setOperator(EQUAl);
}
