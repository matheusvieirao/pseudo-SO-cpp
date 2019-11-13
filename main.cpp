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
void criaFilaPrioridades();
vector<Processo> vet_processos;
GerenteProcessos gp;
vector<Processo> fila_tempo_real;
vector<Processo> fila_usuario;
vector<Processo> fila_prioridade_1;
vector<Processo> fila_prioridade_2;
vector<Processo> fila_prioridade_3;
void dispatcher(vector<Processo>);
void criaFilaTempoReal();

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
    criaFilaTempoReal();
    fila_tempo_real = gp.getFilaTempoReal();
    fila_usuario = gp.getFilaUsuario();
    criaFilaPrioridades();
    fila_prioridade_1 = gp.getFilaPrioridade1();
    fila_prioridade_2 = gp.getFilaPrioridade2();
    fila_prioridade_3 = gp.getFilaPrioridade3();
    dispatcher(fila_tempo_real);
    dispatcher(fila_prioridade_1);
    dispatcher(fila_prioridade_2);
    dispatcher(fila_prioridade_3);

    gerenteArquivos.imprimeMapa();
    cout << endl;

    for (auto &&processo : fila_tempo_real)
    {
        gerenteArquivos.executaOperacoes(processo);
        gerenteArquivos.imprimeMapa();
        cout << endl;
    }

    for (auto &&processo : fila_prioridade_1)
    {
        gerenteArquivos.executaOperacoes(processo);
        gerenteArquivos.imprimeMapa();
        cout << endl;
    }

    for (auto &&processo : fila_prioridade_2)
    {
        gerenteArquivos.executaOperacoes(processo);
        gerenteArquivos.imprimeMapa();
        cout << endl;
    }

    for (auto &&processo : fila_prioridade_3)
    {
        gerenteArquivos.executaOperacoes(processo);
        gerenteArquivos.imprimeMapa();
        cout << endl;
    }

    //gerenteArquivos.imprimeOperacoes();
    // gerenteArquivos.deletaArquivo(Arquivo('X', 0, 2));
    // gerenteArquivos.imprimeMapa();
    // gerenteArquivos.deletaArquivo(Arquivo('A', 7, 6));
    // gerenteArquivos.imprimeMapa();
    // gerenteArquivos.criaArquivo('V', 4, 2);
    // gerenteArquivos.imprimeMapa();

    return 0;
}

void dispatcher(vector<Processo> fila)
{
    for (int i = 0; i < fila.size(); i++)
    {
        cout << "dispatcher =>" << endl;
        cout << "\tPID: " << fila[i].get_PID() << endl;
        cout << "\toffset: " << fila[i].get_offset() << endl;
        cout << "\tblocks: " << fila[i].get_blocos_memoria() << endl;
        cout << "\tpriority: " << fila[i].get_prioridade() << endl;
        cout << "\ttime: " << fila[i].get_tempo_processador() << endl;
        cout << "\tprintrs: " << fila[i].get_numero_impressora() << endl;
        cout << "\tscanners: " << fila[i].get_requisicao_scanner() << endl;
        cout << "\tmodems: " << fila[i].get_requisicao_modem() << endl;
        cout << "\tdrives: " << fila[i].get_numero_disco() << endl;
        cout << endl;
    }
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
    gp.setFilaPrincipal(vet_processos);

    inFile.close();
}
void criaFilaTempoReal()
{
    for (int i = 0; i < vet_processos.size(); i++)
    {
        if (vet_processos[i].get_prioridade() == 0)
        {
            gp.setFilaTempoReal(vet_processos[i]);
        }
        else
        {
            gp.setFilaUsuario(vet_processos[i]);
        }
    }
}
void criaFilaPrioridades()
{
    for (int i = 0; i < fila_usuario.size(); i++)
    {
        if (fila_usuario[i].get_prioridade() == 1)
        {
            gp.setFilaPrioridade1(fila_usuario[i]);
        }
        else if (fila_usuario[i].get_prioridade() == 2)
        {
            gp.setFilaPrioridade2(fila_usuario[i]);
        }
        else if (fila_usuario[i].get_prioridade() == 3)
        {
            gp.setFilaPrioridade3(fila_usuario[i]);
        }
    }
}
GerenteArquivos leArquivos(string files)
{
    ifstream file(files);

    if (!file)
    {
        cerr << "Erro ao abrir o arquivo " << files << endl;
        exit(1); // call system to stop
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

    while (getline(file, line))
    {
        if (i == 0)
        {
            blocosDisco = atoi(line.c_str()); // quantidade de blocos do disco
        }
        else if (i == 1)
        {
            segmentosOcupados = atoi(line.c_str()); // quantidade de segmentos ocupados no disco
        }
        else if (i < segmentosOcupados + 2)
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
            value_str_stream >> pid >> opCode >> nomeArquivo;

            if (opCode == 0)
            {
                value_str_stream >> blocosOcupados >> operacaoProcesso;
            }
            else if (opCode == 1)
            {
                value_str_stream >> operacaoProcesso;
                blocosOcupados = 0;
            }

            operacoes.insert(operacoes.end(), Operacao(pid, opCode, nomeArquivo, blocosOcupados, operacaoProcesso));
        }

        i++;
    }

    file.close();

    GerenteArquivos gerenteArquivos(blocosDisco, segmentosOcupados, arquivos, operacoes);

    return gerenteArquivos;
}