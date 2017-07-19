#ifndef SMARTMATRIX_H
#define	SMARTMATRIX_H
#include "customPointer.h"

class smartMatrix
{
public:
	smartMatrix();
	~smartMatrix();
	smartMatrix(smartMatrix&);
	smartMatrix(int**,int);

	void change(int**,int r);

	customPointer* cusPtr;


};

#endif