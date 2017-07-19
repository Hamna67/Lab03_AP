#ifndef CUSTOMPOINTER_H
#define	CUSTOMPOINTER_H

class customPointer
{
public:
	customPointer();
	~customPointer();
	customPointer(int);
	customPointer(customPointer&);
	customPointer(int**, int);

	void smartCopy(customPointer*);
	void smartCopy(int**,int);
	void change(int**,int);

	int ref_count;

	int **matrix;
	int rows;
};

#endif