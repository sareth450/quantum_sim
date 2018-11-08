#include <stdio.h>
#include "headers/q_kroenecker.h"

void kroenecker_product(q_matrix* kr, q_matrix qm1, q_matrix qm2){
	printf("xd");
	
	int cur_row=0;
	int cur_col=0;
	
	for(int i=0; i<qm1.rows; i++){
	  for(int j=0; j<qm1.cols; j++){ //going over first matrix
		cur_row = i*qm2.rows;
		cur_col = j*qm2.cols;
		for(int k=0; k<qm2.rows; k++){
		  for(int l=0; l<qm2.cols; l++){ //going over second matrix
			double complex val;
			val = get_value_at(&qm1, i, j)*get_value_at(&qm2, k, l);
			input_value(kr, cur_row+k, cur_col+l, val); 	
		  }
		}
		
	  }
	}	
}

int main(){
	q_matrix nqm = new_q_matrix(2,1);
	fill_matrix(&nqm);
	print_matrix(&nqm);
	q_matrix nqm2 = new_q_matrix(3,1);
	fill_matrix(&nqm2);
	print_matrix(&nqm2);
	q_matrix nqm3 = new_q_matrix(nqm.rows*nqm2.rows,nqm.cols*nqm2.cols);
 	kroenecker_product(&nqm3,nqm, nqm2);
	print_matrix(&nqm3);
	return 0;
}
