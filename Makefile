all: bodmas

bodmas: main.o stack.o expression.o
	gcc -Wall -o bodmas main.o stack.o expression.o

main.o: src/main.c
	gcc -Wall -c -I include/ src/main.c

stack.o: src/stack.c
	gcc -Wall -c -I include/ src/stack.c

expression.o: src/expression.c
	gcc -Wall -c -I include/ src/expression.c

clean: 
	rm main.o
	rm stack.o
	rm expression.o
