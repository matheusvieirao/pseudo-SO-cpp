#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "processo.hpp"
#include "gerente_processos.hpp"
using namespace std;

void leProcessos(string);
void leArquivos(string);

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
	leArquivos(argv[2]);

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
	while (getline(inFile, line))
	{
		replace(line.begin(), line.end(), ',', ' '); // remove as ',' para poder fazer a leitura em stream
		istringstream value_str_stream(line);
		value_str_stream >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7 >> v8;
		//cout <<v1<<v2<<v3<<v4<<v5<<v6<<v7<<v8<<endl; ////inserir aqui o construtor de processo!
		//criaArrayProcessos(value_str_stream);
		Processo instancia(v1, v2, v3, v4, v5, v6, v7, v8, 0, 0, 0);
		vet_processos.push_back(instancia);
		

	}
	cout <<vet_processos[0].getTempo_init()<<endl;
	GerenteProcessos fila;
	fila.setFilaPrincipal(vet_processos);
	//for (vector<Processo>::iterator i = vet_processos.begin(); i != vet_processos.end(); ++i)
    //	std::cout << *i._tempo_init << ' ';
	inFile.close();
}

void leArquivos(string files)
{
	ifstream inFile;
	inFile.open(files);

	if (!inFile)
	{
		cout << "\nErro ao abrir arquivo " << files << endl;
	}

	int v1, v2, v3, v4;
	char c;
	string line;
	int i = 0;
	int blocosDisco;
	int segmentosOcupados = 0;
	char nomeArquivo;
	int primeiroBloco, blocosOcupados;
	int idProcesso, opCode, operacaoProcesso;

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
			//////falta colocar um construtor aqui pra cada linha dessa
		}
		else
		{
			replace(line.begin(), line.end(), ',', ' ');
			istringstream value_str_stream(line);
			value_str_stream >> idProcesso >> opCode >> nomeArquivo >> blocosOcupados >> operacaoProcesso;
			//////falta colocar um construtor aqui pra cada linha dessa
		}

		i++;
	}

	inFile.close();
}