#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argq, char *argv[])
{
	if (argq != 3)
	{
		cerr << "\a Para o programa executar eh necessario passar exatamente 2 arquivos por parametro" << endl;
		cerr << "\a Exemplo: ./pseudo-so processes.txt files.txt" << endl;
		return -1;
	}

	std::string processes = argv[1];
	std::string files = argv[2];

	ifstream inFile;
	inFile.open(processes);
	int v1, v2, v3, v4, v5, v6, v7, v8;
	inFile >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7 >> v8;

	
	std::cout << "1: " << v1 << std::endl;
	std::cout << "2: " << v2 << std::endl;
	std::cout << "3: " << v3 << std::endl;
	std::cout << "4: " << v4 << std::endl;
	std::cout << "5: " << v5 << std::endl;
	std::cout << "6: " << v6 << std::endl;
	std::cout << "7: " << v7 << std::endl;
	std::cout << "8: " << v8 << std::endl;

	return 0;
}
