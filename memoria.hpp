#ifndef MEMORIA_HPP
#define MEMORIA_HPP

#include "processo.hpp"

#define MAX_MEM 1024                //tamanho da memoria total
#define MAX_REAL 64                 //tamanho da memoria reservada para tempo-real
#define USER_MAX MAX_MEM - MAX_REAL //tamanho reservado para usuario (960)

class Memoria
{
public:
    Memoria();

private:
    int memoria[MAX_MEM]; //vetor que simula a memoria
};

#endif //MEMORIA_HPP
