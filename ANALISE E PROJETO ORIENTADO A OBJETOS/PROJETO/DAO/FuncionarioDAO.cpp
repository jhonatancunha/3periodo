#include <iostream>
#include <string>
#include "../Entities/Funcionario/Funcionario.h"

using namespace std;


class FuncionarioDAO{
  private:
    string path = "../Database/funcionario.bin";
  public:
    void create(Funcionario Funcionario);
    void update(string cpf);
    void remove(string cpf);
    Funcionario getByCPF(string cpf);
    Funcionario* retrieveAll();
};