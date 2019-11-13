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

Operacao::Operacao(int pid, int opCode, char nomeArquivo, int blocosOcupados, int operacaoProcesso)
{
    this->pid = pid;
    this->opCode = opCode;
    this->arquivo = nomeArquivo;
    this->blocosOcupados = blocosOcupados;
    this->operacaoProcesso = operacaoProcesso;
}

inline int Operacao::getPID()
{
    return this->pid;
}

inline int Operacao::getOpCode()
{
    return this->opCode;
}

inline char Operacao::getArquivo()
{
    return this->arquivo;
}

inline int Operacao::getBlocosOcupados()
{
    return this->blocosOcupados;
}

inline int Operacao::getOperacaoProcesso()
{
    return this->operacaoProcesso;
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

void GerenteArquivos::imprimeOperacoes()
{
    for (auto &&operacao : this->operacoes)
    {
        cout << operacao.getPID() << ", " << operacao.getOpCode() << ", " << operacao.getArquivo() << ", ";

        if (operacao.getOpCode() == 0)
        {
            cout << operacao.getBlocosOcupados() << ", ";
        }

        cout << operacao.getOperacaoProcesso() << endl;
    }
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