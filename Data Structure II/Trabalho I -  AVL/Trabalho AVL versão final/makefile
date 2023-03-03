all: _AVL

_AVL: main.o AVL.o
	gcc -o _AVL main.o AVL.o

main.o: main.c AVL.h
	gcc -c main.c -Wall

AVL.o: AVL.c AVL.h
	gcc -c AVL.c -Wall

clean:
	rm main.o AVL.o _AVL
