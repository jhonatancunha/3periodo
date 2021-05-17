#include <iostream>
#include <string>
#include "Pessoa.h"

using namespace std;


Pessoa::Pessoa(string cpf, string nome, string data_nascimento, string email){
  this->setCPF(cpf);
  this->setDataNascimento(data_nascimento);
  this->setEmail(email);
  this->setNome(nome);
}


void Pessoa::setNome(string nome_pessoa){
  this->nome = nome_pessoa;
}

string Pessoa::getNome(){
  return this->nome;
}

void Pessoa::setDataNascimento(string data_nascimento_pessoa){
  this->data_nascimento = data_nascimento_pessoa;
}

string Pessoa::getDataNascimento(){
  return this->data_nascimento;
}

void Pessoa::setCPF(string cpf_pessoa){
  this->cpf = cpf_pessoa;
}

string Pessoa::getCPF(){
  return this->cpf;
}

void Pessoa::setEmail(string email_pessoa){
  this->email = email_pessoa;
}

string Pessoa::getEmail(){
  return this->email;
}

