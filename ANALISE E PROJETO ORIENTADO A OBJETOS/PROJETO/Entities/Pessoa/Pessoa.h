#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pessoa {
  private:
    string cpf;
    string nome;
    string data_nascimento;
    string email;
  public: 

  Pessoa(){};
  Pessoa(string cpf, string nome, string data_nascimento, string email);

  void setNome(string nome_pessoa);
  string getNome();
  void setDataNascimento(string data_nascimento_pessoa);
  string getDataNascimento();
  void setCPF(string cpf_pessoa);
  string getCPF();
  void setEmail(string email_pessoa);
  string getEmail();
};