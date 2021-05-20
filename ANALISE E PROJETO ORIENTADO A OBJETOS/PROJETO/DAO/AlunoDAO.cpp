#include <iostream>
#include <string>
#include "../Entities/Aluno/Aluno.h"

using namespace std;


class AlunoDAO{
  private:
    string path = "../Database/aluno.bin";
  public:
    void create(Aluno aluno);
    void update(string cpf);
    void remove(string cpf);
    Aluno getByCPF(string cpf);
    Aluno* retrieveAll();
};