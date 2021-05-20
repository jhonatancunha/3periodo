#include <iostream>
#include <string>
#include "../Entities/Pessoa/Pessoa.h"

using namespace std;


class PessoaDAO{
  private:
    string path = "../Database/pessoa.bin";
  public:
    void create(Pessoa Pessoa);
    void update(string cpf);
    void remove(string cpf);
    Pessoa getByCPF(string cpf);
    Pessoa* retrieveAll();
};