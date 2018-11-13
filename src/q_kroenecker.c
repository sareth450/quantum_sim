#include "headers/q_kroenecker.h"

void kroenecker_product(q_matrix* kr, q_matrix qm1, q_matrix qm2){
	
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

