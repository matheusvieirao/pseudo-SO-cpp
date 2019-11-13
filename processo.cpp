#include "processo.hpp"

Processo::Processo()
{
}

int Processo::get_tempo_init()
{
	return this->_tempo_init;
}

void Processo::set_tempo_init(int _tempo_init)
{
	this->_tempo_init = _tempo_init;
}

int Processo::get_prioridade()
{
	return this->_prioridade;
}

void Processo::set_prioridade(int _prioridade)
{
	this->_prioridade = _prioridade;
}

int Processo::get_tempo_processador()
{
	return this->_tempo_processador;
}

void Processo::set_tempo_processador(int _tempo_processador)
{
	this->_tempo_processador = _tempo_processador;
}

int Processo::get_blocos_memoria()
{
	return this->_blocos_memoria;
}

void Processo::set_blocos_memoria(int _blocos_memoria)
{
	this->_blocos_memoria = _blocos_memoria;
}

int Processo::get_numero_impressora()
{
	return this->_numero_impressora;
}

void Processo::set_numero_impressora(int _numero_impressora)
{
	this->_numero_impressora = _numero_impressora;
}

int Processo::get_requisicao_scanner()
{
	return this->_requisicao_scanner;
}

void Processo::set_requisicao_scanner(int _requisicao_scanner)
{
	this->_requisicao_scanner = _requisicao_scanner;
}

int Processo::get_requisicao_modem()
{
	return this->_requisicao_modem;
}

void Processo::set_requisicao_modem(int _requisicao_modem)
{
	this->_requisicao_modem = _requisicao_modem;
}

int Processo::get_numero_disco()
{
	return this->_numero_disco;
}

void Processo::set_numero_disco(int _numero_disco)
{
	this->_numero_disco = _numero_disco;
}

int Processo::get_offset()
{
	return this->_offset;
}

void Processo::set_offset(int _offset)
{
	this->_offset = _offset;
}

int Processo::get_PID()
{
	return this->_PID;
}

void Processo::set_PID(int _PID)
{
	this->_PID = _PID;
}

int Processo::get_execucoes()
{
	return this->_execucoes;
}

void Processo::set_execucoes(int _execucoes)
{
	this->_execucoes = _execucoes;
};