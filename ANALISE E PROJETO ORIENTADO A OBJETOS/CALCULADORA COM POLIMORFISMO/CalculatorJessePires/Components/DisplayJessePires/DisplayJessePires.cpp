#include "DisplayJessePires.h"
#include <iostream>

using namespace std;


void DisplayJessePires::addDigit (Digit number) {
  cout << number;
}

void DisplayJessePires::setSignal (Signal signal) {
  cout << signal;
}

void DisplayJessePires::clear() {
  cout << "\n";
}

void DisplayJessePires::addDecimalSeparator(){
  cout << ".";
}