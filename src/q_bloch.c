#include <stdio.h>
#include <stdlib.h>
#include "headers/q_bloch.h"


struct q_bit_bloch new_qbit(int _initval, double _lattitude, double _longtitude){
	struct q_bit_bloch qbit;
	//to do: 
	// czy wartosci sa w zakresie
	//lattitude [0;M_PI)
	//longtitude [0;2*M_PI)
	
	qbit.lattitude = _lattitude;
	qbit.longtitude = _longtitude;
	
	return qbit;
}

struct q_bit_bloch new_basic_qbit(){
	struct q_bit_bloch qbit;
	
	qbit.lattitude = 0;
	qbit.longtitude = M_PI;
	
	return qbit;
};

void measure_qbit_bloch(struct q_bit_bloch *qbit){
	
	double complex val_0 = cos(qbit->lattitude/2); //cosinus(FI/2), wartosc przy wektorze |0>
	
	double complex p_val = cexp( I * (qbit->longtitude)); //e^(i*PSI)
	double complex sin_val = sin(qbit->lattitude/2); //sinus(FI/2); 
	
	double complex val_1 = sin_val * p_val; // wartosc przy wktorze |1>
	
	printf("%lf+%lfi |0>\n", creal(val_0), cimag(val_0));
	printf("%lf+%lfi |1>\n", creal(val_1), cimag(val_1));
}

int main(int args, char* argv[]){
	
	struct q_bit_bloch qb = new_basic_qbit();
	
	//bloch sphere representation
	printf("Init vals: FI: %lf - PSI: %lf\n", qb.lattitude, qb.longtitude);
	measure_qbit_bloch(&qb);
	return 0;
}

