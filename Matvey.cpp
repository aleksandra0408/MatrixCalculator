#include "prototype.h"
using namespace std;

void calculator::multiply()
{
	matrix matrix1;
	matrix matrix2;
	matrix matrix3;
	filling(matrix1, 1);
	filling(matrix2, 1);
	//deleting_Zeros(matrix1);
	//deleting_Zeros(matrix2);
	multiplication(matrix1, matrix2, matrix3);
	show(matrix3);
}
void calculator::multiplication(matrix& x, matrix& y, matrix& z) {
	if (x.columns != y.lines) {
		cout << "multiplication is not possible";
		return;
	}
	z.lines = x.lines;
	z.columns = y.columns;
	z.table.resize(z.lines);
	for (int i = 0; i < z.lines; i++) {
		for (int j = 0; j < z.columns; j++) {
			z.table[i].push_back(0);
			for (int k = 0; k < x.columns; k++) {
				z.table[i][j] += x.table[i][k] * y.table[k][j];
			}
		}
	}
}