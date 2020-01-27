all: bodmas

bodmas: main.o stack.o expression.o
	gcc -Wall -o bodmas main.o stack.o expression.o

main.o: main.c
	gcc -Wall -c main.c

stack.o: stack.c
	gcc -Wall -c stack.c

expression.o: expression.c
	gcc -Wall -c expression.c

clean: 
	rm main.o
	rm stack.o
	rm expression.o
