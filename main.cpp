#include <iostream>

using namespace std;

int main(int argq, char *argv[])
{
	if (argq != 3)
	{
		cerr << "\a Para o programa executar é necessário passar exatamente 2 arquivos por parâmetro" << endl;
		cerr << "\a Exemplo: ./pseudo-so processes.txt files.txt" << endl;
		return -1;
	}

	char *input;
	input = argv[1];

	return 0;
}
