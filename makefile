
all: 
	gcc main.c ./src/lerArquivo.c ./src/matriz.c -o main.exe -Wall -lm 
	./main.exe
	
clean:
	rm ./bin/* ./obj/*