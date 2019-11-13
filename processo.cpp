#include "processo.hpp"

int Processo::getPID()
{
    return this->pid;
}

void Processo::setPID(const int pid)
{
    this->pid = pid;
}