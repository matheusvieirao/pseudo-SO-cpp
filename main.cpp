#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "processo.hpp"
#include "gerente_arquivos.hpp"
#include "gerente_processos.hpp"

using namespace std;

void leProcessos(string);
GerenteArquivos leArquivos(string);

vector<Processo> vet_processos;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "\a Para o programa executar eh necessario passar exatamente 2 arquivos por parametro" << endl;
        cerr << "\a Exemplo: ./pseudo-so processes.txt files.txt" << endl;
        return -1;
    }

    leProcessos(argv[1]);
    GerenteArquivos gerenteArquivos = leArquivos(argv[2]);
    gerenteArquivos.iniciaDisco();

    for (int i = 0; i < vet_processos.size(); i++)
    {
        cout << "dispatcher =>" << endl;
        cout << "\tPID: " << vet_processos[i].get_PID() << endl;
        cout << "\toffset: " << vet_processos[i].get_offset() << endl;
        cout << "\tblocks: " << vet_processos[i].get_blocos_memoria() << endl;
        cout << "\tpriority: " << vet_processos[i].get_prioridade() << endl;
        cout << "\ttime: " << vet_processos[i].get_tempo_processador() << endl;
        cout << "\tprintrs: " << vet_processos[i].get_numero_impressora() << endl;
        cout << "\tscanners: " << vet_processos[i].get_requisicao_scanner() << endl;
        cout << "\tmodems: " << vet_processos[i].get_requisicao_modem() << endl;
        cout << "\tdrives: " << vet_processos[i].get_numero_disco() << endl;
        cout << endl;
    }

    gerenteArquivos.imprimeMapa();

    return 0;
}

void leProcessos(string processes)
{
    ifstream inFile;
    inFile.open(processes);

    if (!inFile)
    {
        cout << "\nErro ao abrir arquivo " << processes << endl;
    }

    int v1, v2, v3, v4, v5, v6, v7, v8;
    string line;
    int pid = 0;
    while (getline(inFile, line))
    {
        replace(line.begin(), line.end(), ',', ' '); // remove as ',' para poder fazer a leitura em stream
        istringstream value_str_stream(line);
        value_str_stream >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7 >> v8;
        //cout <<v1<<v2<<v3<<v4<<v5<<v6<<v7<<v8<<endl; ////inserir aqui o construtor de processo!
        //criaArrayProcessos(value_str_stream);
        cout << "valor 1: " << pid << endl;
        Processo instancia = Processo();
        instancia.set_tempo_init(v1);
        instancia.set_prioridade(v2);
        instancia.set_tempo_processador(v3);
        instancia.set_blocos_memoria(v4);
        instancia.set_numero_impressora(v5);
        instancia.set_requisicao_scanner(v6);
        instancia.set_requisicao_modem(v7);
        instancia.set_numero_disco(v8);
        instancia.set_offset(0);
        instancia.set_PID(pid);
        instancia.set_execucoes(0);
        vet_processos.push_back(instancia);
        pid++;
    }
    inFile.close();
}

GerenteArquivos leArquivos(string files)
{
    ifstream inFile;
    inFile.open(files);

    if (!inFile)
    {
        cout << "\nErro ao abrir arquivo " << files << endl;
    }

    string line;
    int i = 0;
    int blocosDisco;
    int segmentosOcupados = 0;
    char nomeArquivo;
    int primeiroBloco, blocosOcupados;
    int pid, opCode, operacaoProcesso;
    vector<Arquivo> arquivos;
    vector<Operacao> operacoes;

    while (getline(inFile, line))
    {
        if (i < 1)
        {
            blocosDisco = atoi(line.c_str()); //quantidade de blocos no disco
        }
        else if (i < 2)
        {
            segmentosOcupados = atoi(line.c_str()); //quantidade de segmentos ocupados no disco
        }
        else if (i < (segmentosOcupados + 2))
        {
            replace(line.begin(), line.end(), ',', ' ');
            istringstream value_str_stream(line);
            value_str_stream >> nomeArquivo >> primeiroBloco >> blocosOcupados;

            arquivos.insert(arquivos.end(), Arquivo(nomeArquivo, primeiroBloco, blocosOcupados));
        }
        else
        {
            replace(line.begin(), line.end(), ',', ' ');
            istringstream value_str_stream(line);
            value_str_stream >> pid >> opCode >> nomeArquivo >> blocosOcupados >> operacaoProcesso;

            operacoes.insert(operacoes.end(), Operacao(pid, opCode, nomeArquivo, blocosOcupados));
        }

        i++;
    }

    inFile.close();

    GerenteArquivos gerenteArquivos(blocosDisco, segmentosOcupados, arquivos, operacoes);

    return gerenteArquivos;
}