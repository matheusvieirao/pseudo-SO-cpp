#include "gerente_arquivos.hpp"

Arquivo::Arquivo()
{
}

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

void Arquivo::setNome(char nome)
{
    this->nome = nome;
}

inline int Arquivo::getInicio()
{
    return this->inicio;
}

inline int Arquivo::getTamanho()
{
    return this->tamanho;
}

inline int Arquivo::getCriador()
{
    return this->criador;
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

void GerenteArquivos::criaArquivo(char nome, int tamanho, int criador)
{
    for (auto &&arquivo : this->arquivos)
    {
        if (nome == arquivo.getNome())
        {
            cout << "P" << criador << " instruction" << 0 << " - FALHA" << endl;
            cout << "O processo " << criador << " nao pode criar o arquivo " << nome << " porque já existe um arquivo com esse nome." << endl
                 << endl;

            return;
        }
    }

    int vazios = 0;

    for (auto i = 0; i < this->qtdBlocos; i++)
    {
        if (disco[i] == ' ')
        {
            vazios++;

            if (vazios == tamanho)
            {
                int inicio = i - vazios + 1;

                for (auto j = inicio; j < inicio + tamanho; j++)
                {
                    disco[j] = nome;
                }

                arquivos.push_back(Arquivo(nome, inicio, tamanho, criador));

                cout << "P" << criador << " instruction" << 0 << " - SUCESSO" << endl;
                cout << "O processo " << criador << " criou o arquivo " << nome << " (blocos " << inicio << " a " << inicio + tamanho - 1 << ")." << endl
                     << endl;

                return;
            }
        }
        else
        {
            vazios = 0;
        }
    }

    cout << "P" << criador << " instruction" << 0 << " - FALHA" << endl;
    cout << "O processo " << criador << " nao pode criar o arquivo " << nome << " por falta de espaço." << endl
         << endl;
}

void GerenteArquivos::deletaArquivo(Arquivo arquivo)
{
    for (auto i = arquivo.getInicio(); i < arquivo.getInicio() + arquivo.getTamanho(); i++)
    {
        this->disco[i] = ' ';
    }
}

void GerenteArquivos::executaOperacoes(Processo processo)
{
    vector<Operacao> opExec;

    for (auto &&operacao : this->operacoes)
    {
        if (processo.get_PID() == operacao.getPID())
        {
            opExec.push_back(operacao);
        }
    }

    for (auto &&operacao : this->operacoes)
    {
        if (operacao.getOpCode() == 0)
        {
            this->criaArquivo(operacao.getArquivo(), operacao.getBlocosOcupados(), operacao.getPID());
        }
        else
        {
            Arquivo deleterio = Arquivo();
            deleterio.setNome('-');

            for (auto &&arquivo : this->arquivos)
            {
                if (arquivo.getNome() == operacao.getArquivo())
                {
                    deleterio = arquivo;
                }
            }

            if (deleterio.getNome() != '-')
            {
                if (processo.get_prioridade() == 0 || deleterio.getCriador() == 0 || deleterio.getCriador() == operacao.getPID())
                {
                    this->deletaArquivo(deleterio);

                    cout << "P" << operacao.getPID() << " instruction" << operacao.getOperacaoProcesso() << " - SUCESSO" << endl;
                    cout << "O processo " << operacao.getPID() << " deletou o arquivo " << operacao.getArquivo() << "." << endl
                         << endl;
                }
                else
                {
                    cout << "P" << operacao.getPID() << " instruction" << operacao.getOperacaoProcesso() << " - FALHA" << endl;
                    cout << "O processo " << operacao.getPID() << " nao pode deletar o arquivo " << operacao.getArquivo() << " porque nao possui permissao." << endl
                         << endl;
                }
            }
            else
            {
                cout << "P" << operacao.getPID() << " instruction" << operacao.getOperacaoProcesso() << " - FALHA" << endl;
                cout << "O processo " << operacao.getPID() << " nao pode deletar o arquivo " << operacao.getArquivo() << " porque nao existe esse arquivo." << endl
                     << endl;
            }
        }
    }
}

GerenteArquivos::~GerenteArquivos()
{
}