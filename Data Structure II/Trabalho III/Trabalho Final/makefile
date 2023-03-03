all: _Huffman

_Huffman: main.o Huffman.o
	gcc -o _Huffman main.o Huffman.o

main.o: main.c Huffman.h
	gcc -c main.c -Wall

Huffman.o: Huffman.c Huffman.h
	gcc -c Huffman.c -Wall

clean:
	rm main.o Huffman.o _Huffman