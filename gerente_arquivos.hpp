#ifndef GERENTE_ARQUIVOS_HPP
#define GERENTE_ARQUIVOS_HPP

class Arquivo
{
private:
    char nome;
    int primeiroBloco;
    int blocosOcupados;

public:
    Arquivo(char nome, int primeiroBloco, int blocosOcupados);
    ~Arquivo();
};

class Operacao
{
private:
    int opCode;

public:
    Operacao(int opCode);
    ~Operacao();
};

#endif //GERENTE_ARQUIVOS_HPP
