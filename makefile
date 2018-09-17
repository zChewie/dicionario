all:
	gcc -c trabalho.c
	gcc -o main main.c trabalho.o
	./main