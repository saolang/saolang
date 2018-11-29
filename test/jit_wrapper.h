#ifndef JIT_WRAPPER_H
#define JIT_WRAPPER_H

#include "scc_dl.h"
#include "sljitLir.h"
#include "sljitLir.c"

struct JIT {
	double re, im;
	double (*abs)(struct JIT *this);
};

const struct JITClass {
	struct JIT (*new)(double real, double imag);
} JIT;


static double abs(struct JIT *this) {
	//printf("sqrt=%f\n", (this->re * this->re) +  (this->im*this->im ));
	//	double rt = SCC(sqrt,double)(this->re*this->re + this->im*this->im);
	//	printf("rt=%f",rt);
	//	return rt;
	//return (double) sqrt(this->re*this->re + this->im*this->im);
	return SCC(sqrt,double)(this->re*this->re + this->im*this->im);
}
static struct JIT jit_new(double real, double imag) {
	printf("debug:%f,%f\n",real,imag);
	return (struct JIT){.re=real, .im=imag, .abs=&abs};
}
const struct JITClass JIT={.new=&jit_new};
#endif
