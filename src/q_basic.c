#include <stdio.h>
#include <stdlib.h>
#include "q_basic.h"

q_state new_q_state(int size, int state, double complex value){
	q_state qs;
	qs.size = size; //ilosc kubitów - n
	
	int vec_size = (int) pow(2,(double) size); //rozmiar wektora - 2^n 

	qs.state = calloc(vec_size, sizeof(int)); //miejsce dla wektora
	for(int i=0; i<vec_size; i++){ //zapis odpowieniego stanu
		if(i==state){		//np dla |110> - stan to (00000010)
			qs.state[i]=1;	//czyli 1 na 6 pozycję (indeskowna od 0)
		}
		else{
			qs.state[i]=0;	//reszta pozycji równa 0
		}
	}
	
	qs.value = value; //alfa,v 
	return qs;
}

void delete_q_state(q_state *qs){
	free(qs->state);
}

q_register new_q_register_basic(int size){
	q_register qreg;
	
	qreg.size = size; //kubity w rejestrze - n
	
	qreg.reg_size = (int) pow(2,(double) size); //rozmiar wektorów - 2^n 
	
	double complex alpha = 2.0 / (double) qreg.reg_size; //alfa jakieś z góry równe 1/n
	
	qreg.states = calloc(qreg.reg_size, sizeof(q_state));
	
	for(int l=0; l<qreg.reg_size; l++){
		qreg.states[l] = new_q_state(size, l, alpha); //inicjalizacja kazdego stanu
	}

	return qreg;
}

void delete_q_register(q_register* qreg){
	for(int i=0; i<qreg->reg_size; i++){
		delete_q_state(&qreg->states[i]);
	}
	free(qreg->states);
}

void print_q_register(q_register qreg){
	for(int k=0; k<qreg.reg_size; k++){
		q_state qs = qreg.states[k];
		printf("%lf+%lfi * [ ", creal(qs.value), cimag(qs.value));
		for(int j=0; j<qreg.reg_size; j++){
			printf("%d, ", qs.state[j]);
		}
		printf("]\n");
	}
}

q_matrix qreg_to_matrix(q_register qr){
	q_matrix qrm = new_q_matrix(qr.reg_size,1);
	
	for(int i=0; i<qr.reg_size; i++){
		input_value(&qrm, i,0,qr.states[i].value);
	}

	return qrm;
}

int main(int args, char* argv[]){
	
	q_register qreg = new_q_register_basic(5);

	print_q_register(qreg);
	
	q_matrix qrm = qreg_to_matrix(qreg);

	print_matrix(&qrm);

	delete_q_register(&qreg);
	
	return 0;
}
