#ifndef PROCESSO_HPP
#define PROCESSO_HPP

class Processo
{
public:
	Processo(int pid, //id do processo
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
	int execucoes);
	int getPID();
	void setPID(const int pid);
	int getPrioridade();
	void setPrioridade(const int prioridade);

private:
	int pid; //id do processo
	int tempo_init;
    int prioridade;
   	int tempo_processador;
	int blocos_memoria;
    int numero_impressora;
	int requisicao_scanner;
	int requisicao_modem;
	int numero_disco;
	int offset;
	int PID;
	int execucoes;
};
#endif // PROCESSO_HPP
