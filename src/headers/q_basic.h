#ifndef QUANTUM_BASIC_H
#define QUANTUM_BASIC_H

#include "q_matrix.h"

typedef struct{
	int size; //liczba kubitów
	int *state; //tablica z wektorem, stanem (może reprezntować to jako liczbę?) 
	double complex value; // wartość alfa/v
}q_state;


typedef struct{
	int size; //liczba kubitów
	int reg_size; //2^n - liczba stanów, gdzie n=size;
	q_state* states; //tablica przechowywania stanów i odpowiadających im alf(prawdopodobieństw)
}q_register;

q_state new_q_state(int size, int state, complex double value);
q_register new_q_register_basic(int size);
void delte_q_state(q_state* qs);
void delete_q_register(q_register* qreg);
void print_q_register(q_register qreg);
q_matrix qreg_to_matrix(q_register qreg);
#endif
