#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <math.h>

struct matrix
{
	std::vector<std::vector<double>> table;
	int lines = 0, columns = 0;
};
class calculator
{
private:
	std::vector<double> rankList;
	void filling(matrix& x, int turn);
	void show(matrix& x);
	matrix del_Line_Column(matrix x, int i, int j);
	void minor_Enum(matrix x);
	void matrix_Rank();
	void summa(matrix& a, matrix& b, matrix& c);
	void subtraction(matrix& a, matrix& b, matrix& c);
	void multiply_on_number(matrix& a, matrix& c, double k);
	void deleting_Zeros(matrix& x);
	void multiplication(matrix& x, matrix& y, matrix& z);
	void deleteLinAndCol(matrix x, int size, int lin, int col, matrix& newmatrix);
	double  matrixDet(matrix x, int size);
	void InverseMatrix(matrix& x, int size);
	void sum();
	void sub();
	void multi_number();
	void multiply();
	double  Det();
	void Inverse();
	int  keys();
public:
	void menu();
};