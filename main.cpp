#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

void ReadProcessos(string);
void ReadArquivos(string);

int main(int argq, char *argv[])
{
	if (argq != 3)
	{
		cerr << "\a Para o programa executar eh necessario passar exatamente 2 arquivos por parametro" << endl;
		cerr << "\a Exemplo: ./pseudo-so processes.txt files.txt" << endl;
		return -1;
	}

	ReadProcessos(argv[1]);
	ReadArquivos(argv[2]);

	return 0;
}

void ReadProcessos(string processes)
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
	}
	inFile.close();
}
void ReadArquivos(string files)
{
	ifstream inFile;
	inFile.open(files);

	if (!inFile)
	{
		cout << "\nErro ao abrir arquivo " << files << endl;
	}

	int v1, v2, v3, v4;
	char c;
	int i = 0;
	string line;
	int blocos, seg_ocup=0;
	while (getline(inFile, line))
	{	
		if(i<1){
			blocos = atoi(line.c_str()); //quantidade de blocos no disco
			v1 = blocos;
		}
		else if(i<2){
			seg_ocup = atoi(line.c_str()); //quantidade de segmentos ocupados no disco
			v1 = seg_ocup;
		}
		else if(i < (seg_ocup+2)){
			replace(line.begin(), line.end(), ',', ' ');
			istringstream value_str_stream(line);
			value_str_stream >> c >> v2 >> v3;
			//////falta colocar um construtor aqui pra cada linha dessa
		}
		else {
			replace(line.begin(), line.end(), ',', ' ');
			istringstream value_str_stream(line);
			value_str_stream >> v1 >> v2 >> c >> v3 >> v4;
			//////falta colocar um construtor aqui pra cada linha dessa
		}
		i++;
	}
	inFile.close();
}