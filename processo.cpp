#include "processo.hpp"

int Processo::getPID()
{
	return this->pid;
}

void Processo::setPID(const int pid)
{
	this->pid = pid;
}
int Processo::getPrioridade()
{
	return this->prioridade;
}

void Processo::setPrioridade(const int prioridade)
{
	this->prioridade = pid;
}
Processo::Processo(int pid, //id do processo
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
	int execucoes){}