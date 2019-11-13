#ifndef GERENTE_ARQUIVOS_HPP
#define GERENTE_ARQUIVOS_HPP

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Arquivo
{
private:
    char nome;
    int inicio;
    int tamanho;
    int criador;

public:
    Arquivo(char nome, int primeiroBloco, int blocosOcupados, int PID = 0);
    char getNome();
    int getInicio();
    int getTamanho();
    ~Arquivo();
};

class Operacao
{
private:
    int pid;
    int opCode;
    char nomeArquivo;
    int blocosOcupados;

public:
    Operacao(int pid, int opCode, char nomeArquivo, int blocosOcupados = 0);
    ~Operacao();
};

class GerenteArquivos
{
private:
    int qtdBlocos;
    int qtdSegmentos;
    vector<Arquivo> arquivos;
    vector<Operacao> operacoes;
    map<int, char> disco;

public:
    GerenteArquivos(int qtdBlocos, int qtdSegmentos, vector<Arquivo> arquivos, vector<Operacao> operacoes);
    void iniciaDisco();
    void imprimeMapa();
    void criaArquivo();
    void deletaArquivo(Arquivo arquivo);
    ~GerenteArquivos();
};

#endif //GERENTE_ARQUIVOS_HPP
