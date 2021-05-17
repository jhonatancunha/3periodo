#pragma once
#include<iostream>
#include<string>

using namespace std;

class AvaliacaoFisica {
  private:
    int id;
    float massa_magra;
    float massa_gorda;
    float peso_total;
    float perc_gordura;
    float altura;
    string tipo_pisada;
    float medida_braco;
    float medida_antebraco;
    float medida_quadriceps;
    float medida_panturrilha;
    float medida_ombro;
    float medida_cintura_pelvica;
    float medida_cintura_escapular;
  public:

  AvaliacaoFisica();

  void setMassaMagra(float massa_magra);
  float getMassaMagra();

  void setMassaGorda(float massa_gorda);
  float getMassaGorda();

  void setPesoTotal(float peso_total);
  float getPesoTotal();

  void setPercGordura(float perc_gordura);
  float getPercGordura();

  void setAltura(float altura);
  float getAltura();

  void setPisada(string tipo_pisada);
  string getPisada();

  void setMedidaBraco(float medida_braco);
  float getMedidaBraco();

  void setMedidaAntebraco(float medida_antebraco);
  float getMedidaAntebraco();

  void setMedidaQuadriceps(float medida_quadriceps);
  float getMedidaQuadriceps();

  void setMedidaPanturrilha(float medida_panturrilha);
  float getMedidaPanturrilha();

  void setMedidaOmbro(float medida_ombro);
  float getMedidaOmbro();

  void setMedidaCinturaPelvica(float medida_cintura_pelvica);
  float getMedidaCinturaPelvica();

  void setMedidaCinturaEscapular(float medida_cintura_escapular);
  float getMedidaCinturaEscapular();
};