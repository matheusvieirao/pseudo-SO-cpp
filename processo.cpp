#include "processo.hpp"

Processo::Processo()
{
}

Processo::Processo(
    int tempo_init,
    int prioridade,
    int tempo_processador,
    int blocos_memoria,
    int numero_impressora,
    int requisicao_scanner,
    int requisicao_modem,
    int numero_disco,
    int offset,
    int PID,
    int execucoes)
{
    _PID = PID;
    _tempo_init = tempo_init;
}

int Processo::getPID()
{
    return this->_PID;
}

void Processo::setPID(const int pid)
{
    this->_PID = pid;
}
int Processo::getTempo_init()
{
    return this->_tempo_init;
}

void Processo::setTempo_init(const int tempo_init)
{
    this->_tempo_init = tempo_init;
}
int Processo::getPrioridade()
{
    return this->_prioridade;
}

void Processo::setPrioridade(const int prioridade)
{
    this->_prioridade = prioridade;
}
