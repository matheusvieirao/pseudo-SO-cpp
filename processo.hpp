#ifndef PROCESSO_HPP
#define PROCESSO_HPP

class Processo
{
public:
	Processo() {}

	int getPID();
	void setPID(const int pid);

private:
	int pid; //id do processo
};

#endif // PROCESSO_HPP
