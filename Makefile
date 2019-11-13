simulation: main.o processo.o memoria.o
	@echo " Ligando os objetos para criar o arquivo 'pseudo-so'."
	@g++ main.o processo.o memoria.o -g -std=c++11 -o pseudo-so
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

clean:
	rm pseudo-so
	rm *.o

