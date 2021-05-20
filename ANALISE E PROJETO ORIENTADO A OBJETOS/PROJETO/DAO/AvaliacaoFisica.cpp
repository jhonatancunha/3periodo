#include <iostream>
#include <string>
#include "../Entities/AvaliacaoFisica/AvaliacaoFisica.h"

using namespace std;


class AvaliacaoFisicaDAO{
  private:
    string path = "../Database/avaliacao_fisica.bin";
  public:
    void create(AvaliacaoFisica avaliacao);
    void update(int id);
    void remove(int id);
    AvaliacaoFisica getByID(int id);
    AvaliacaoFisica* retrieveAll();
};