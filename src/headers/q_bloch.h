#ifndef QUANTUM_BLOCH_H
#define QUANTUM_BLOCH_H

#include <math.h>
#include <complex.h>

struct q_bit_bloch{
	double lattitude; //FI
	double longtitude; //PSI
};

struct q_bit_bloch new_qbit(int _initval, double _lattitude, double _longtitude);
struct q_bit_bloch new_basic_qbit();
void measure_qbit_bloch(struct q_bit_bloch *);

#endif

