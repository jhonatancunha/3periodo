#include<iostream>
#include<string>
#include"AvaliacaoFisica.h"

void AvaliacaoFisica::setMassaMagra(float massa_magra){
  this->massa_magra = massa_magra;
}

float AvaliacaoFisica::getMassaMagra(){
  return this->massa_magra;
}


void AvaliacaoFisica::setMassaGorda(float massa_gorda){
  this->massa_gorda = massa_gorda;
}

float AvaliacaoFisica::getMassaGorda(){
  return this->massa_gorda;
}


void AvaliacaoFisica::setPesoTotal(float peso_total){
  this->peso_total = peso_total;
}

float AvaliacaoFisica::getPesoTotal(){
  return this->peso_total;
}


void AvaliacaoFisica::setPercGordura(float perc_gordura){
  this->perc_gordura = perc_gordura;
}

float AvaliacaoFisica::getPercGordura(){
  return this->perc_gordura;
}


void AvaliacaoFisica::setAltura(float altura){
  this->altura = altura;
}

float AvaliacaoFisica::getAltura(){
  return this->altura;
}


void AvaliacaoFisica::setPisada(string tipo_pisada){
  this->tipo_pisada = tipo_pisada;
}

string AvaliacaoFisica::getPisada(){
  return this->tipo_pisada;
}


void AvaliacaoFisica::setMedidaBraco(float medida_braco){
  this->medida_braco = medida_braco;
}

float AvaliacaoFisica::getMedidaBraco(){
  return this->medida_braco;
}


void AvaliacaoFisica::setMedidaAntebraco(float medida_antebraco){
  this->medida_antebraco = medida_antebraco;
}

float AvaliacaoFisica::getMedidaAntebraco(){
  return this->medida_antebraco;
}


void AvaliacaoFisica::setMedidaQuadriceps(float medida_quadriceps){
  this->medida_quadriceps = medida_quadriceps;
}

float AvaliacaoFisica::getMedidaQuadriceps(){
  return this->medida_quadriceps;
}


void AvaliacaoFisica::setMedidaPanturrilha(float medida_panturrilha){
  this->medida_panturrilha = medida_panturrilha;
}

float AvaliacaoFisica::getMedidaPanturrilha(){
  return this->medida_panturrilha;
}


void AvaliacaoFisica::setMedidaOmbro(float medida_ombro){
  this->medida_ombro = medida_ombro;
}

float AvaliacaoFisica::getMedidaOmbro(){
  return this->medida_ombro;
}


void AvaliacaoFisica::setMedidaCinturaPelvica(float medida_cintura_pelvica){
  this->medida_cintura_pelvica = medida_cintura_escapular;
}

float AvaliacaoFisica::getMedidaCinturaPelvica(){
  return this->medida_cintura_pelvica;
}


void AvaliacaoFisica::setMedidaCinturaEscapular(float medida_cintura_escapular){
  this->medida_cintura_escapular = medida_cintura_escapular;
}

float AvaliacaoFisica::getMedidaCinturaEscapular(){
  return this->medida_cintura_escapular;
}
