#ifndef GERENTE_PROCESSOS_HPP
#define GERENTE_PROCESSOS_HPP

#include "processo.hpp"
#include <vector>
#include <iostream>
using namespace std;

class GerenteProcessos
{
public:
    void setFilaPrincipal(vector<Processo> processos);
    vector<Processo> getFilaPrincipal();
    void setFilaTempoReal(Processo processo);
    vector<Processo> getFilaTempoReal();
    void setFilaUsuario(Processo processo);
    vector<Processo> getFilaUsuario();
    void setFilaPrioridade1(Processo processo);
    vector<Processo> getFilaPrioridade1();
    void setFilaPrioridade2(Processo processo);
    vector<Processo> getFilaPrioridade2();
    void setFilaPrioridade3(Processo processo);
    vector<Processo> getFilaPrioridade3();
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