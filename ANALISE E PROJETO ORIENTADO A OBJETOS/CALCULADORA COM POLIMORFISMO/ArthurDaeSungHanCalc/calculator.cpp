/*
 * CPP file with implemented methods
 */

#include "arthurCalculator.h"
 
//PUBLIC DISPLAY METHODS

void ArthurDisplay::addDigit(Digit number){
    switch(number){
    case ZERO: std::cout<< "0000\n0  0\n0  0\n0  0\n0000\n\n";break;
    case ONE:  std::cout<< "   0\n   0\n   0\n   0\n   0\n\n";break;
    case TWO: std::cout<< "0000\n   0\n0000\n0  \n0000\n\n";break;
    case THREE: std::cout<< "0000\n   0\n0000\n   0\n0000\n\n";break;
    case FOUR: std::cout<< "0  0\n0  0\n0000\n   0\n   0\n\n";break;
    case FIVE: std::cout<< "0000\n0   \n0000\n   0\n0000\n\n";break;
    case SIX: std::cout<< "0000\n0   \n0000\n0  0\n0000\n\n";break;
    case SEVEN: std::cout<< "0000\n   0\n   0\n   0\n   0\n\n";break;
    case EIGHT: std::cout<< "0000\n0  0\n0000\n0  0\n0000\n\n";break;
    case NINE: std::cout<< "0000\n0  0\n0000\n   0\n   0\n\n";break;

    // case ZERO: std::cout<< "0";break;
    // case ONE:  std::cout<< "1;break;
    // case TWO: std::cout<< "2";break;
    // case THREE: std::cout<< "3";break;
    // case FOUR: std::cout<< "4";break;
    // case FIVE: std::cout<< "5";break;
    // case SIX: std::cout<< "6";break;
    // case SEVEN: std::cout<< "7";break;
    // case EIGHT: std::cout<< "8";break;
    // case NINE: std::cout<< "9";break;
    }  
};
void ArthurDisplay::addDecimalSeparator(){
    std::cout << "0\n\n";
    // std::cout << ".";
};
void ArthurDisplay::setSignal(Signal signal){
    if(signal == NEGATIVE) std::cout << "\n\n0000\n";
    // if(signal == NEGATIVE) std::cout << "-";
};
void ArthurDisplay::clear(){
    std::cout << "\n\n";
};

//
//PRIVATE CPU METHODS
//

int ArthurCpu::calculateResult(int firstNumber, int secondNumber){
    if(this->operation == ADDITION)
        return (signal == NEGATIVE) ? (-1) * firstNumber + secondNumber : firstNumber + secondNumber;
    else if(this->operation == SUBTRACTION)
        return (signal == NEGATIVE) ? (-1) * firstNumber - secondNumber : firstNumber - secondNumber;
    else if(this->operation == DIVISION)
        return (signal == NEGATIVE) ? (-1) * (float)firstNumber / secondNumber : (float)firstNumber / secondNumber;
    else
        return (signal == NEGATIVE) ? (-1) * firstNumber * secondNumber : firstNumber * secondNumber;
};
void ArthurCpu::getNumber(Stack* operand, int* number){
    int aux = 1;
    int size = operand->getSize();
    int* v = new int[operand->getSize()];
    int* v1 = new int[operand->getSize()];

    operand->popStack(v);
    
    for (int i = 0; i < size; i++){
        v1[i] = v[i] * aux;
        aux *= 10;
    }
    for (int i = 0; i < size; i++){
        *number += v1[i];
    }
    delete v;
    delete v1;
};

void ArthurCpu::sendToDisplay(Stack* resultInDigits){
    this->display->setSignal(this->signal);
    while(!resultInDigits->isEmpty()){
        this->display->addDigit((Digit)resultInDigits->getTop()->getValue());
        resultInDigits->pop();
    }
    
};

void ArthurCpu::intToDigit(int result){
    int size = std::to_string(result).size();
    Stack* resultInDigits = new Stack();

    for(int i = 0; i < size; i++){
    resultInDigits->push(result % 10);
    result = result / 10;
    }
    sendToDisplay(resultInDigits);
    resultInDigits->~Stack();
};

void ArthurCpu::setOperation(){
    int firstNumber = 0;
    int secondNumber = 0;
    getNumber(firstOperand, &firstNumber);
    getNumber(secondOperand, &secondNumber);
    secondNumber = calculateResult(firstNumber, secondNumber);
    if(secondNumber < 0) this->signal = NEGATIVE;
    intToDigit(secondNumber);
    this->reset();
};

//
//PUBLIC CPU METHODS
//

ArthurCpu::ArthurCpu(){ 
    this->signal = POSITIVE;
    this->firstOperand = new Stack();
    this->secondOperand = new Stack();
    this->hasOperator = false;
};
void ArthurCpu::setDisplay(Display* display){
    this->display = display;
};
void ArthurCpu::receiveDigit(Digit digit){
    this->display->addDigit(digit);
    if(!this->hasOperator) this->firstOperand->push(digit);
    else this->secondOperand->push(digit);
};
void ArthurCpu::receiveOperation(Operation operation){
    if(operation == SUBTRACTION && this->firstOperand->isEmpty()){
        this->signal = NEGATIVE;
        return;
    }
    this->display->clear();
    if(this->hasOperator){
        this->setOperation();
        return;
    }
    this->operation = operation;
    this->hasOperator = true;
};
void ArthurCpu::cancel(){
    if(!this->hasOperator) {
        while (!this->firstOperand->isEmpty()) this->firstOperand->pop();
        this->signal = POSITIVE;
    }
    else 
        while (!this->secondOperand->isEmpty()) this->secondOperand->pop();
    this->display->clear();
};
void ArthurCpu::reset(){
    while (!this->firstOperand->isEmpty()) this->firstOperand->pop();
    while (!this->secondOperand->isEmpty()) this->secondOperand->pop();
    this->hasOperator = false;
    this->signal = POSITIVE;
    this->display->clear();
};

//
//PUBLIC OPERATION KEYBOARD METHODS
//

ArthurOperationKeyBoard::ArthurOperationKeyBoard(){this->cpu = NULL;};

void ArthurOperationKeyBoard::setCpu(Cpu *cpu){this->cpu = cpu;};

void ArthurOperationKeyBoard::pressAddition(){this->cpu->receiveOperation(ADDITION);};
void ArthurOperationKeyBoard::pressDivision(){this->cpu->receiveOperation(DIVISION);};
void ArthurOperationKeyBoard::pressMultiplication(){this->cpu->receiveOperation(MULTIPLICATION);};
void ArthurOperationKeyBoard::pressSubtraction(){this->cpu->receiveOperation(SUBTRACTION);};
void ArthurOperationKeyBoard::pressEquals(){this->cpu->receiveOperation(EQUAL);};

//
//PUBLIC NUMERIC KEYBOARD METHODS
//

ArthurNumericKeyBoard::ArthurNumericKeyBoard() {this->cpu = NULL;};

void ArthurNumericKeyBoard::setCpu(Cpu *cpu){this->cpu = cpu;};

void ArthurNumericKeyBoard::pressZero(){this->cpu->receiveDigit(ZERO);};
void ArthurNumericKeyBoard::pressOne(){this->cpu->receiveDigit(ONE);};
void ArthurNumericKeyBoard::pressTwo(){this->cpu->receiveDigit(TWO);};
void ArthurNumericKeyBoard::pressThree(){this->cpu->receiveDigit(THREE);};
void ArthurNumericKeyBoard::pressFour(){this->cpu->receiveDigit(FOUR);};
void ArthurNumericKeyBoard::pressFive(){this->cpu->receiveDigit(FIVE);};
void ArthurNumericKeyBoard::pressSix(){this->cpu->receiveDigit(SIX);};
void ArthurNumericKeyBoard::pressSeven(){this->cpu->receiveDigit(SEVEN);};
void ArthurNumericKeyBoard::pressEight(){this->cpu->receiveDigit(EIGHT);};
void ArthurNumericKeyBoard::pressNine(){this->cpu->receiveDigit(NINE);};

//
//PUBLIC CALCULATOR METHODS
//
ArthurCalculator::ArthurCalculator(Cpu *cpu, Display *display, NumericKeyBoard *numericKeyBoard, OperationKeyBoard *operationKeyBoard){ 
    this->setCpu(cpu);
    this->setDisplay(display);
    this->setNumericKeyBoard(numericKeyBoard);
    this->setOperationKeyBoard(operationKeyBoard);

    this->cpu->setDisplay(display);
    this->numericKeyBoard->setCpu(cpu);
    this->operationKeyBoard->setCpu(cpu);
};
ArthurCalculator::~ArthurCalculator(){ 
    delete this->numericKeyBoard;
    delete this->operationKeyBoard;
    delete this->display;
    delete this->cpu;
};
//SETTERS
void ArthurCalculator::setNumericKeyBoard(NumericKeyBoard* numericKeyBoard){
    this->numericKeyBoard = numericKeyBoard;
};
void ArthurCalculator::setOperationKeyBoard(OperationKeyBoard* operationKeyBoard){
    this->operationKeyBoard = operationKeyBoard;
};
void ArthurCalculator::setDisplay(Display* display){
    this->display = display;
};
void ArthurCalculator::setCpu(Cpu* cpu){
    this->cpu = cpu;
};
//GETTERS
NumericKeyBoard* ArthurCalculator::getNumericKeyBoard(){
    return this->numericKeyBoard;
};
OperationKeyBoard* ArthurCalculator::getOperationKeyBoard(){
    return this->operationKeyBoard;
};
Display* ArthurCalculator::getDisplay(){
    return this->display;
};
Cpu* ArthurCalculator::getCpu(){
    return this->cpu;
};

