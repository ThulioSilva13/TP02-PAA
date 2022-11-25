
all: 
	gcc main.c ./src/lerArquivo.c ./src/matriz.c ./src/progDinamica.c ./src/pilha.c -o main.exe -Wall -lm 
	./main.exe
	
clean:
	rm ./bin/* ./obj/*