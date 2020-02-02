all: bodmas

bodmas: main.o stack.o expression.o toinfix.o limit.o
	gcc -Wall -o bodmas main.o stack.o expression.o toinfix.o limit.o

main.o: src/main.c
	gcc -Wall -c -I include/ src/main.c

stack.o: src/stack.c
	gcc -Wall -c -I include/ src/stack.c

expression.o: src/expression.c
	gcc -Wall -c -I include/ src/expression.c

toinfix.o: src/toinfix.c
	gcc -Wall -c -I include/ src/toinfix.c

limit.o: src/limit.c
	gcc -Wall -c -I include/ src/limit.c

clean: 
	rm main.o
	rm stack.o
	rm expression.o
	rm toinfix.o
	rm limit.o
