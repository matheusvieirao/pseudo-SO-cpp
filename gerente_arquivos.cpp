#include "gerente_arquivos.hpp"

Arquivo::Arquivo(char nome, int primeiroBloco, int blocosOcupados, int PID)
{
    this->nome = nome;
    this->inicio = primeiroBloco;
    this->tamanho = blocosOcupados;
    this->criador = PID;
}

inline char Arquivo::getNome()
{
    return this->nome;
}

inline int Arquivo::getInicio()
{
    return this->inicio;
}

inline int Arquivo::getTamanho()
{
    return this->tamanho;
}

Arquivo::~Arquivo()
{
}

Operacao::Operacao(int pid, int opCode, char nomeArquivo, int blocosOcupados)
{
    this->pid = pid;
    this->opCode = opCode;
    this->nomeArquivo = nomeArquivo;

    if (opCode == 0)
    {
        this->blocosOcupados = blocosOcupados;
    }
}

Operacao::~Operacao()
{
}

GerenteArquivos::GerenteArquivos(int qtdBlocos, int qtdSegmentos, vector<Arquivo> arquivos, vector<Operacao> operacoes)
{
    this->qtdBlocos = qtdBlocos;
    this->qtdSegmentos = qtdSegmentos;
    this->arquivos = arquivos;
    this->operacoes = operacoes;
}

void GerenteArquivos::iniciaDisco()
{
    for (auto i = 0; i < this->qtdBlocos; i++)
    {
        this->disco[i] = ' ';
    }

    for (auto &&arquivo : this->arquivos)
    {
        for (auto i = arquivo.getInicio(); i < arquivo.getInicio() + arquivo.getTamanho(); i++)
        {
            disco[i] = arquivo.getNome();
        }
    }
}

void GerenteArquivos::imprimeMapa()
{
    cout << "|";

    for (auto &&bloco : this->disco)
    {
        cout << bloco.second << "|";
    }

    cout << endl;
}

void GerenteArquivos::criaArquivo()
{
}

void GerenteArquivos::deletaArquivo(Arquivo arquivo)
{
    for (auto i = arquivo.getInicio(); i < arquivo.getInicio() + arquivo.getTamanho(); i++)
    {
        this->disco[i] = ' ';
    }
}

GerenteArquivos::~GerenteArquivos()
{
}