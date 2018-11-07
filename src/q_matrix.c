#include <stdio.h>
#include <stdlib.h>
#include "q_matrix.h"

q_matrix new_q_matrix(int rows, int cols){

	q_matrix qm;

	qm.rows = rows;
	qm.cols = cols;
	for(int i=0; i< HUGE_SIZE; i++){
		qm.values[i]=0.0+0.0*I;
	}

	return qm;
}

void delete_matrix(q_matrix *qm){
	qm->rows=0;
	qm->cols=0;
	free(qm->values);
}

void input_value(q_matrix *qm, int row, int col, double complex val){
	qm->values[(row*qm->rows)+col]=val; //tablica jednowymiarowa do przechowywania wartosci
	//dostęp do pozycji (x,y) jako index (x*liczba_wierszy)+y
}

void fill_matrix(q_matrix *qm){
	for(int i=0; i<qm->rows; i++){
		for(int j=0; j<qm->cols; j++){
			double real,imag;
			printf("Input real value for M[%d,%d]: ", i,j);
			scanf("%lf", &real);
			printf("Input imaginary value for M[%d,%d]: ", i,j);
			scanf("%lf", &imag);
			input_value(qm, i, j, real + imag * I ); 
		}
	}
}

double complex get_value_at(q_matrix *qm, int row, int col){
	return qm->values[ (row*qm->rows) + col];
}

void print_matrix(q_matrix *qm){
	printf("\nMatrix %d x %d\n", qm->rows, qm->cols);
	for(int i=0; i<qm->rows; i++){
		printf("[ ");
		for(int j=0; j<qm->cols; j++){
			printf("%lf+%lfi, ", creal(get_value_at(qm,i,j)), cimag(get_value_at(qm,i,j)));
		}
		printf(" ]\n");
	}
}

/*
int main(int args, char* argv[]){
	q_matrix nqm = new_q_matrix(3,1);
	fill_matrix(&nqm);
	print_matrix(&nqm);
	q_matrix nqm2 = new_q_matrix(2,1);
	fill_matrix(&nqm2);
	print_matrix(&nqm2);
	delete_matrix(&nqm2);
	delete_matrix(&nqm);
	return 0;
}
*/
