#pragma once
#include <iostream>
#include <string>
#include "../Pessoa/Pessoa.h"

class Funcionario: public Pessoa {
  private:
    string numero_pis;
  public:
    void setPis(string pis);
    string getPis();
};