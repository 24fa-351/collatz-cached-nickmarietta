collatz: main.o cache.o collatz.o
	gcc -o collatz main.o cache.o collatz.o

main.o: main.c
	gcc -c main.c

cache.o: cache.c
	gcc -c cache.c

collatz.o: collatz.c
	gcc -c collatz.c

clean:
	rm -f *.o collatz
