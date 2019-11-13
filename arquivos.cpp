#include "arquivos.hpp"

Arquivo::Arquivo(char nome, int primeiroBloco, int blocosOcupados)
{
    this.nome = nome;
    this.primeiroBloco = primeiroBloco;
    this.blocosOcupados = blocosOcupados;
}

Arquivo::~Arquivo()
{
}