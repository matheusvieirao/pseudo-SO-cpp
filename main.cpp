#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argq, char *argv[])
{
	if (argq != 3)
	{
		cerr << "\a Para o programa executar eh necessario passar exatamente 2 arquivos por parametro" << endl;
		cerr << "\a Exemplo: ./pseudo-so processes.txt files.txt" << endl;
		return -1;
	}

	string processes = argv[1];
	string files = argv[2];

	ifstream inFile;
	inFile.open(processes);

	if (!inFile)
	{
		cout << "\nErro ao abrir arquivo " << processes << endl;
	}

	int v1, v2, v3, v4, v5, v6, v7, v8;
	string line;
	while(getline(inFile, line)){
		replace( line.begin(), line.end(), ',', ' '); // remove as ',' para poder a leitura em stream
		istringstream value_str_stream (line);
		value_str_stream >> v1>>v2>>v3>>v4>>v5>>v6>>v7>>v8;
		//cout <<v1<<v2<<v3<<v4<<v5<<v6<<v7<<v8<<endl; ////inserir aqui o construtor de processo!
	}
	inFile.close();

	return 0;
}
