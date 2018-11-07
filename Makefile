
all: kro basic bloch

kro:
	gcc -Wall -c src/q_matrix.c
	gcc -Wall -c src/q_kroenecker.c
	gcc -Wall -o q_kroenecker q_kroenecker.o q_matrix.o 
basic:
	gcc -Wall -c src/q_basic.c
	gcc -Wall -o q_basic q_basic.o q_matrix.o -lm

bloch:
	gcc -Wall -c src/q_bloch.c
	gcc -Wall -o q_bloch q_bloch.o -lm

clean:
	rm q_*
