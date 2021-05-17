#include<iostream>
#include<string>
#include "Funcionario.h"

void Funcionario::setPis(string pis){
  this->numero_pis = pis;
}

string Funcionario::getPis(){
  return this->numero_pis;
}
