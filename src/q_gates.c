#include "headers/q_gates.h"
#include "headers/q_kroenecker.h"

q_gate new_hadamard_gate(){
	q_gate hg;
	hg.matrix = new_q_matrix(2,2);
	hg.value = (double) 1 / sqrt(2);
	input_value(&hg.matrix,0,0,1);
	input_value(&hg.matrix,0,1,1);
	input_value(&hg.matrix,1,0,1);
	input_value(&hg.matrix,1,1,-1);
	return hg;
}
q_gate new_x_pauli_gate(){
	q_gate xpg;
	xpg.matrix = new_q_matrix(2,2);
	xpg.value = (double) 1 / sqrt(2);
	input_value(&xpg.matrix,0,0,0);
	input_value(&xpg.matrix,0,1,1);
	input_value(&xpg.matrix,1,0,1);
	input_value(&xpg.matrix,1,1,0);
	return xpg;
}
q_gate new_z_pauli_gate(){
	q_gate zpg;
	zpg.matrix = new_q_matrix(2,2);
	zpg.value = (double) 1 / sqrt(2);
	input_value(&zpg.matrix,0,0,1);
	input_value(&zpg.matrix,0,1,0);
	input_value(&zpg.matrix,1,0,0);
	input_value(&zpg.matrix,1,1,-1);
	return zpg;
}

q_gate new_q_gate(q_matrix qm, double complex value){
	q_gate res_gate;
	res_gate.matrix = qm;
	res_gate.value = value;
	return res_gate;
}

void print_gate(q_gate *g){
	printf("%.2lf + %.2lfi * ", creal(g->value), cimag(g->value));
	print_matrix(&g->matrix);
	
}

int main(){
	q_gate hg = new_x_pauli_gate();
	
	q_gate hg2 = new_x_pauli_gate();

	q_matrix km = new_q_matrix(4,4);
	kroenecker_product(&km, hg.matrix, hg.matrix);
	q_gate dh = new_q_gate(km, hg.value * hg2.value);
	
	q_matrix km2 = new_q_matrix(8,8);
	kroenecker_product(&km2, hg.matrix, dh.matrix);
	q_gate th = new_q_gate(km2, hg.value * dh.value);

	print_gate(&th);

	return 0;
}
