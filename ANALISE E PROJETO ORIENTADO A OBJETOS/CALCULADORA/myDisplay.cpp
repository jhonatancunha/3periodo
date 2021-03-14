#include "myCalc.h"

MyDisplay::MyDisplay(){
  this->result = 0;
}

void MyDisplay::addDigit(DIGIT number){
  std::cout << number;
};

void MyDisplay::clear(){
  std::cout << "\n";
  this->result = 0;
};


