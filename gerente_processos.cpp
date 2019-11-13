#include "gerente_processos.hpp"

vector<Processo> GerenteProcessos::getFilaPrincipal(){
    return this->_fila_principal;
}
void GerenteProcessos::setFilaPrincipal(vector<Processo> processos){
    this->_fila_principal = processos;
}
void GerenteProcessos::setFilaTempoReal(Processo processo){
    this->_fila_tempo_real.push_back(processo);
}
void separaProcessos(){
    GerenteProcessos gp;
    vector<Processo> fila;


    for(int i=0;i<fila.size();i++)
    cout <<i;
}