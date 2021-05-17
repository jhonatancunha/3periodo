#pragma once
#include <iostream>
#include <string>
#include "../Pessoa/Pessoa.h"

class Aluno: public Pessoa {
  private:
    string telefone;
  public:
    Aluno(string telefone);
    void setTelefone(string telefone);
    string getTelefone();
};