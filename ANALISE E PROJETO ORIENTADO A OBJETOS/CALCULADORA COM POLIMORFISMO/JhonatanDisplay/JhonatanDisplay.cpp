#include "../JhonatanCalculator.h"

void JhonatanDisplay::addDigit(Digit number){
  switch (number){
  case ZERO:
    std::cout << "\n00000\n0   0\n0   0\n0   0\n00000\n";
    break;
  case ONE:
    std::cout << "\n  0  \n  0  \n  0  \n  0  \n  0  \n";
    break;
  case TWO:
    std::cout << "\n000000\n     0\n000000\n0     \n000000\n";
    break;
  case THREE:
    std::cout << "\n000000\n     0\n000000\n     0\n000000\n";
    break;
  case FOUR:
    std::cout << "\n0    0\n0    0\n000000\n     0\n     0\n";
    break;
  case FIVE:
    std::cout << "\n000000\n0     \n000000\n     0\n000000\n";
    break;
  case SIX:
    std::cout << "\n000000\n0     \n000000\n0    0\n000000\n";
    break;
  case SEVEN:
    std::cout << "\n000000\n     0\n     0\n     0\n     0\n";
    break;
  case EIGHT:
    std::cout << "\n000000\n0    0\n000000\n0    0\n000000\n";
    break;
  case NINE:
    std::cout << "\n000000\n0    0\n000000\n     0\n000000\n";
    break;
  }
};


void JhonatanDisplay::addDecimalSeparator(){
  std::cout << "\n0\n";
}

void JhonatanDisplay::setSignal(Signal signal){
  switch(signal){
    case POSITIVE:
      std::cout <<"  0  \n  0  \n00000\n  0  \n  0  \n" ;
      break;
    case NEGATIVE:
      std::cout << "00000\n";
      break;
  };
}

void JhonatanDisplay::clear(){
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";  
};


