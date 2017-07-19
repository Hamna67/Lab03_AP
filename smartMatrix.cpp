#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "customPointer.h"
#include "smartMatrix.h"
using namespace std;

//default constructor
smartMatrix::smartMatrix()
{
	this->cusPtr = new customPointer();
}

smartMatrix::~smartMatrix()
{
	if (--(this->cusPtr->ref_count) < 1)
	{
		delete[] this->cusPtr;
	}
}

smartMatrix::smartMatrix(smartMatrix& newMatrix)
{
	this->cusPtr = newMatrix.cusPtr;

	++(this->cusPtr->ref_count);
}

void smartMatrix::change(int** m,int r)
{
	if (this->cusPtr->ref_count > 1)
	{
		auto_ptr<customPointer> newMatrix(new customPointer);
		newMatrix->smartCopy(this->cusPtr);

		--(this->cusPtr->ref_count);

		this->cusPtr = newMatrix.release();
	}
	this->cusPtr->change(m,r);
}
