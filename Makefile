simulation: main.o processo.o memoria.o gerente_processos.o
	@echo " Ligando os objetos para criar o arquivo 'pseudo-so'."
	@g++ main.o processo.o memoria.o gerente_processos.o gerente_arquivos.o -g -std=c++11 -o pseudo-so
	@echo " Pronto!"
	@echo " Para rodar basta usar a seguinte linha de comando: ./pseudo-so arquivo_processes.txt  arquivo_files.txt"

main.o: main.cpp
	@echo " Criando main.o"
	@g++ main.cpp -g -std=c++11 -c

processo.o: processo.cpp processo.hpp
	@echo " Criando processo.o"
	@g++ processo.cpp -g -std=c++11 -c

memoria.o: memoria.cpp memoria.hpp
	@echo " Criando memoria.o"
	@g++ memoria.cpp -g -std=c++11 -c

gerente_processos.o: gerente_processos.cpp gerente_processos.hpp
	@echo " Criando gerente_processos.o"
	@g++ gerente_processos.cpp -g -std=c++11 -c

gerente_arquivos:
	@echo " Criando gerente_arquivos.o"
	@g++ gerente_arquivos.cpp -g -std=c++11 -c

clean:
	rm pseudo-so
	rm *.o

