#include<iostream>
#include<string>
#include"Aluno.h"


Aluno::Aluno(string telefone){
  this->setTelefone(telefone);
}


void Aluno::setTelefone(string telefone){
  this->telefone = telefone;
}

string Aluno::getTelefone(){
  return this->telefone;
}
