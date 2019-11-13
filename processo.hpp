#ifndef PROCESSO_HPP
#define PROCESSO_HPP

class Processo
{
public:
	Processo(
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
	int getTempo_init();
	void setTempo_init(const int tempo_init);

private:
	int _tempo_init;
    int _prioridade;
   	int _tempo_processador;
	int _blocos_memoria;
    int _numero_impressora;
	int _requisicao_scanner;
	int _requisicao_modem;
	int _numero_disco;
	int _offset;
	int _PID;
	int _execucoes;
};
#endif // PROCESSO_HPP
