#ifndef Q_MATRIX_H
#define Q_MATRIX_H

#include <math.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

#define STANDARD_SIZE 1024
#define MEDIUM_SIZE 4096
#define HUGE_SIZE 16384
#define ABSURD_SIZE 65536

typedef struct{
	int rows;
	int cols;
	double complex values[HUGE_SIZE];
}q_matrix;

extern q_matrix new_q_matrix(int rows, int cols); 
extern void input_value(q_matrix *qm, int row, int col, double complex val);
extern void fill_matrix(q_matrix *qm);
extern double complex get_value_at(q_matrix *qm, int col, int row);
extern void print_matrix(q_matrix *qm);
extern void delete_matrix(q_matrix *qm);
//extern q_matrix kroenecker_product(q_matrix qm1, q_matrix qm2);
#endif

