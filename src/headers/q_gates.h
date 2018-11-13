#ifndef Q_GATES_H
#define Q_GATES_H

#include "q_basic.h"
#include "q_matrix.h"

typedef struct{
	q_matrix matrix;
	double complex value;
}q_gate;

//typedef struct{
//	q_matrix matrix;
//	double complex value;
//}hadamard_gate;

extern q_gate new_q_gate(q_matrix qm, double complex value);
extern q_gate new_hadamard_gate();
extern q_gate new_x_pauli_gate();
extern q_gate new_z_pauli_gate();
extern void print_gate(q_gate *g);
#endif
