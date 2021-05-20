#include<iostream>
#include<string>
#include "Instrutor.h"

void Instrutor::setCREF(string cref_instrutor){
  this->cref = cref_instrutor;
}

string Instrutor::getCREF(){
  return this->cref;
}


void Instrutor::setSenha(string senha_instrutor){
  this->senha = senha;
}

string Instrutor::getSenha(){
  return this->senha;
}