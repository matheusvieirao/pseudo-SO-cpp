#include "memoria.hpp"
#include <iostream>

// instância de Memory
Memoria::Memoria()
{
	for (int i = 0; i < MAX_MEM; i++)
	{
		memoria[i] = 0; // zera memória
	}
}