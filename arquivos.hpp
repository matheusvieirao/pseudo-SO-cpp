#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

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

#endif //PSEUDO_SO_CPP_ARQUIVOS_HPP
