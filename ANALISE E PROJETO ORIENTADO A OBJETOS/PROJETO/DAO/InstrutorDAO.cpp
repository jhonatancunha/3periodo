#include <iostream>
#include <string>
#include "../Entities/Instrutor/Instrutor.h"

using namespace std;


class InstrutorDAO{
  private:
    string path = "../Database/instrutor.bin";
  public:
    void create(Instrutor Instrutor);
    void update(string cpf);
    void remove(string cpf);
    Instrutor getByCPF(string cpf);
    Instrutor* retrieveAll();
};