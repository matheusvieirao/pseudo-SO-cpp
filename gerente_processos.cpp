#include "gerente_processos.hpp"

vector<Processo> GerenteProcessos::getFilaPrincipal()
{
    return this->_fila_principal;
}
void GerenteProcessos::setFilaPrincipal(vector<Processo> processos)
{
    this->_fila_principal = processos;
}