#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "customPointer.h"
using namespace std;

//default constructor
customPointer::customPointer()
{
	ref_count = 1;
	rows = 0;
	matrix = new int*[rows];
}

//constructor with aruguments
customPointer::customPointer(int r)
{
	ref_count = 1;
	rows = r;
	matrix = new int*[rows];
}

//copy constructor
customPointer::customPointer(customPointer& m)
{
	ref_count = 1;
	this->smartCopy(&m);
}

customPointer::customPointer(int** m, int r)
{
	ref_count = 1;
	this->smartCopy(m,r);

}
//smart copy
void customPointer::smartCopy(customPointer* m)
{
	this->rows = m->rows;

	for (int i = 0; i < m->rows; i++)
	{
		matrix[i] = new int[m->rows];
		for (int j = 0; j < m->rows; j++)
		{
			matrix[i][j] = m->matrix[i][j];
		}
	}

}
void customPointer::smartCopy(int** m, int r)
{
	this->rows = r;	
	
	for (int i = 0; i < r; i++) 
	{
		matrix[i] = new int[r];
		for (int j = 0; j < r; j++) 
		{
			matrix[i][j] = m[i][j];
		}
	}
	
}

void customPointer::change(int** m,int r)
{
	this->smartCopy(m,r);
}

//destructor
customPointer::~customPointer()
{
	delete[] matrix;
}

