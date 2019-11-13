#ifndef PROCESSO_HPP
#define PROCESSO_HPP

class Processo
{
public:
	Processo();
	int get_tempo_init();
	void set_tempo_init(int _tempo_init);
	int get_prioridade();
	void set_prioridade(int _prioridade);
	int get_tempo_processador();
	void set_tempo_processador(int _tempo_processador);
	int get_blocos_memoria();
	void set_blocos_memoria(int _blocos_memoria);
	int get_numero_impressora();
	void set_numero_impressora(int _numero_impressora);
	int get_requisicao_scanner();
	void set_requisicao_scanner(int _requisicao_scanner);
	int get_requisicao_modem();
	void set_requisicao_modem(int _requisicao_modem);
	int get_numero_disco();
	void set_numero_disco(int _numero_disco);
	int get_offset();
	void set_offset(int _offset);
	int get_PID();
	void set_PID(int _PID);
	int get_execucoes();
	void set_execucoes(int _execucoes);

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
