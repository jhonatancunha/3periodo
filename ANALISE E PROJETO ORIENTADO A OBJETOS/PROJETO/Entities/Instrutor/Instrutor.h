#pragma once
#include <iostream>
#include <string>
#include "../Funcionario/Funcionario.h"

class Instrutor: public Funcionario {
  private:
    string cref;
    string senha;
  public:
    void setCREF(string cref_instrutor);
    string getCREF();

    void setSenha(string senha_instrutor);
    string getSenha();
};