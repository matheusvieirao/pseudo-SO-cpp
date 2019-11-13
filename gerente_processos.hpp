#ifndef GERENTE_PROCESSOS_HPP
#define GERENTE_PROCESSOS_HPP

#include "processo.hpp"
#include <vector>
#include <iostream>
using namespace std;

class GerenteProcessos
{
public:
    vector<Processo> getFilaPrincipal();
    void setFilaPrincipal(vector<Processo> processos);
    void setFilaTempoReal(Processo processo);
    vector<Processo> getFilaTempoReal();

private:
    vector<Processo> _fila_tempo_real;
    vector<Processo> _fila_usuario;
    vector<Processo> _prioridade_1;
    vector<Processo> _prioridade_2;
    vector<Processo> _prioridade_3;
    vector<Processo> _fila_principal;
    Processo _em_execucao;
    int _ultimoPID;
};

#endif