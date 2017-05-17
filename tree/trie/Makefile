all: compile

compile:
	gcc -o test test.c trie.c trie.h
	./test

test.o: test.c trie.h
	gcc -c test.c

trie.o: trie.c trie.h
	gcc -c trie.c

build: test.o trie.o
	gcc test.o trie.o -o test
	./test

test: build cleanup

cleanup:
	rm *.o
	rm test
