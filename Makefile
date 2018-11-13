
all: gates bloch

gates:
	gcc -Wall -c src/q_matrix.c
	gcc -Wall -c src/q_kroenecker.c
	gcc -Wall -c src/q_basic.c
	gcc -Wall -c src/q_gates.c
	gcc -Wall -o q_gates q_gates.o q_basic.o q_matrix.o q_kroenecker.o -lm

bloch:
	gcc -Wall -c src/q_bloch.c
	gcc -Wall -o q_bloch q_bloch.o -lm

clean:
	rm q_*
