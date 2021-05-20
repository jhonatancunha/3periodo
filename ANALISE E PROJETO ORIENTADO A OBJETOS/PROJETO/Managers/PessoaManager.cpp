#include <iostream>
#include <string>
#include "../DAO/PessoaDAO.cpp"
#include "../Entities/Pessoa/Pessoa.h"

using namespace std;


class PessoaManager{
  private:
  public:

    static void store(string cpf, string nome, string data_nascimento, string email){
      try
      {
        /* code */
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
      
    }
  
};