#include "prototype.h"
using namespace std;

void calculator::deleteLinAndCol(matrix x, int size, int lin, int col, matrix& newmatrix)
{
	int offsetLin = 0;
	int offsetCol = 0;
	newmatrix.table.resize(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			newmatrix.table[i].push_back(0);
		}
	}
	for (int i = 0; i < size - 1; i++) 
	{
		if (i == lin) offsetLin = 1;
		offsetCol = 0;
		for (int j = 0; j < size - 1; j++) 
		{
			if ((j == col) && (j != (size - 1))) offsetCol = 1;
			newmatrix.table[i][j] = x.table[i + offsetLin][j + offsetCol];
		}
	}
}
double  calculator::matrixDet(matrix x, int size) 
{
	double det = 0;
	int degree = 1;

	if (size == 1)	return x.table[0][0];
	if (size == 2)	return x.table[0][0] * x.table[1][1] - x.table[0][1] * x.table[1][0];

	matrix newmatrix;
	for (int j = 0; j < size; j++)
	{
		deleteLinAndCol(x, size, 0, j, newmatrix);
		det = det + (degree * x.table[0][j] * matrixDet(newmatrix, size - 1));
		degree = degree * (-1);
	}
	return det;
}
void calculator::InverseMatrix(matrix& x, int size)
{
	double p = matrixDet(x, x.columns);
	cout << p << endl;
	matrix a;
	a.table.resize(x.columns);
	for (int i = 0; i < x.columns; i++)
	{
		for (int j = 0; j < x.columns; j++)
		{
			a.table[i].push_back(0);
		}
	}
	a.columns = x.columns;
	a.lines = x.lines;

	matrix newmatrix;
	for (int i = 0; i < x.columns; i++)
	{
		newmatrix.columns = x.columns - 1;
		newmatrix.lines = x.lines - 1;
		for (int j = 0; j < x.columns; j++)
		{
			deleteLinAndCol(x, x.columns, i, j, newmatrix);
			a.table[i][j] = pow(-1, (i + 1) * (j + 1)) * fabs(matrixDet(newmatrix, newmatrix.columns));
		}
	}
	show(a);
	cout << endl;

	matrix c;
	c.columns = x.columns;
	c.lines = x.lines;
	multiply_on_number(a, c, 1 / p);
}
double  calculator::Det()
{
	matrix x;
	cout << "--- 1 matrix --- " << endl;
	filling(x, 3);
	cout << "Your matrix: " << endl;
	show(x);
	return matrixDet(x, x.columns);
}
void calculator::Inverse() 
{
	matrix x;
	cout << "--- 1 matrix --- " << endl;
	filling(x, 3);
	cout << "Your matrix: " << endl;
	show(x);
	InverseMatrix(x, x.columns);
}
