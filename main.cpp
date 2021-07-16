#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <math.h>


#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct matrix
{
	vector<vector<double>> table;
	int lines = 0, columns = 0;
};

class calculator
{
private:

	void filling(matrix& x, int turn)//if turn == 2 then the enter of lines and colomns is skipping.
	{
		while (true)
		{
			try
			{
				if (turn == 3) {
					cout << "Enter number of lines and colomns: ";
					if (!(cin >> x.lines)) throw 1;
					x.columns = x.lines;
					if (x.lines <= 0)  throw 2;
					x.table.resize(x.lines);
				}
				if (turn != 2 && turn != 3) {
					cout << "Enter number of lines: ";
					if (!(cin >> x.lines)) throw 1;
					cout << "Enter number of colomns: ";
					if (!(cin >> x.columns)) throw 1;
					if ((x.lines <= 0) || (x.columns <= 0)) throw 2;
					x.table.resize(x.lines);
				}

				for (int i = 0; i < x.lines; i++)
				{
					for (int j = 0; j < x.columns; j++)
					{
						x.table[i].push_back(0);
					}
				}

				cout << "Enter elements:" << endl;
				for (int i = 0; i < x.lines; i++)
				{
					for (int j = 0; j < x.columns; j++)
					{
						if (!(cin >> x.table[i][j])) throw 3;
					}
				}
				break;
			}
			catch (int i)
			{
				if (i == 1)
				{
					cerr << "Error 1: Wrong type of input data. 'int'.";
					cin.clear();
					while (cin.get() != '\n');

				}
				else if (i == 2)
				{
					cerr << "Error 2: Wrong value of variables. Value of lines or colomns can't be <= 0.";
					cin.clear();
					while (cin.get() != '\n');

				}
				else
				{
					cerr << "Error 3: Wrong type of input data. 'int' , 'float' , 'double' expected.";
					cin.clear();
					while (cin.get() != '\n');

				}
			}
		}
	}

	void show(matrix& x)
	{
		for (int i = 0; i < x.lines; i++)
		{
			for (int j = 0; j < x.columns; j++)
			{
				cout << x.table[i][j] << "\t";
			}
			cout << endl;
		}
	}

	void summa(matrix& a, matrix& b, matrix& c) {
		//Summ of matrixs
		c.columns = a.columns; //The finall matrix has the same size
		c.lines = a.lines;
		c.table.resize(a.lines);

		for (int i = 0; i < c.lines; i++) //add the memory to finall matrix
		{
			for (int j = 0; j < c.columns; j++)
			{
				c.table[i].push_back(0);
			}
		}

		for (int i = 0; i < c.lines; i++) //count the elements of finall matrix
		{
			for (int j = 0; j < c.columns; j++)
			{
				c.table[i][j] = a.table[i][j] + b.table[i][j];
			}
		}
	}

	void subtraction(matrix& a, matrix& b, matrix& c) {
		//subtraction of matrixs
		c.columns = a.columns; //The finall matrix has the same size
		c.lines = a.lines;
		c.table.resize(a.lines);

		for (int i = 0; i < c.lines; i++) //add the memory to finall matrix
		{
			for (int j = 0; j < c.columns; j++)
			{
				c.table[i].push_back(0);
			}
		}

		for (int i = 0; i < c.lines; i++) //count the elements of finall matrix
		{
			for (int j = 0; j < c.columns; j++)
			{
				c.table[i][j] = a.table[i][j] - b.table[i][j];
			}
		}
	}
	void multiply_on_number(matrix& a, matrix& c, double k) {
		c.columns = a.columns;
		c.lines = a.lines;
		c.table.resize(a.lines);

		for (int i = 0; i < c.lines; i++)
		{
			for (int j = 0; j < c.columns; j++)
			{
				c.table[i].push_back(0);
			}
		}
		for (int i = 0; i < c.lines; i++)
		{
			for (int j = 0; j < c.columns; j++)
			{
				c.table[i][j] = a.table[i][j] * k;
			}
		}
	}

	void deleting_Zeros(matrix& x) // If you matrix have zeros lines or columns this function will delete it.
	{
		vector<int> delLines;

		// deleting zeros lines.
		for (int i = 0; i < x.lines; i++)
		{
			double k = 0;
			for (int j = 0; j < x.columns; j++)
			{
				k = k + x.table[i][j];
			}
			if (abs(k) < pow(10, -5)) delLines.push_back(i);
		}
		for (int i = 0; i < delLines.size(); i++)
		{
			x.table.erase(x.table.begin() + delLines[delLines.size() - i - 1]);
			x.lines--;
		}

		// deleting zeros columns.
		if (x.lines == 0)
		{
			x.columns = 0;
		}
		else
		{
			delLines.resize(0);
			for (int j = 0; j < x.columns; j++)
			{
				double k = 0;
				for (int i = 0; i < x.lines; i++)
				{
					k = k + x.table[i][j];
				}
				if (k == 0) delLines.push_back(j);
			}
			if (delLines.size() == 0) {}
			else
			{
				for (int i = 0; i < delLines.size() - 1; i++)
				{
					x.table[i].erase(x.table[i].begin() + delLines[delLines.size() - i - 1]);
					x.columns--;
				}
			}
		}
	}

	void gauss_Method(matrix& x)
	{
		deleting_Zeros(x);

		// Matrix rank can't be more than minimum count of lines\columns.
		int maxRank;
		if (x.lines >= x.columns)
		{
			maxRank = x.columns;
		}
		else
		{
			maxRank = x.lines;
		}


		if (maxRank == 0) {}
		else if (maxRank == 1) {}
		else
		{
			// Checking and fixing the situation when you matrix have zeros in main diagonal.
			for (int i = 0; i < maxRank; i++)
			{
				if (x.table[i][i] == 0)
				{
					int lineNum = 0;
					for (int j = i + 1; j < x.lines; j++)
					{
						if (x.table[j][i] != 0)
						{
							lineNum = j;
							break;
						}
					}
					for (int j = 0; j < x.columns; j++)
					{
						x.table[i][j] = x.table[i][j] + x.table[lineNum][j];
					}
				}
				// Gauss Method.
				double tempMultiplier1 = (1 / x.table[i][i]);
				for (int j = 0; j < x.columns; j++)
				{
					x.table[i][j] = x.table[i][j] * tempMultiplier1;
				}
				for (int n = i + 1; n < x.lines; n++)
				{
					double tempMultiplier2 = x.table[n][i];
					for (int m = 0; m < x.columns; m++)
					{
						x.table[n][m] = (x.table[n][m]) - x.table[i][m] * tempMultiplier2;
					}
				}
				// Deleting zoros lines after gauss method.
				deleting_Zeros(x);
				maxRank = x.lines;
			}
		}
		cout << endl;
		show(x);
		cout << endl;
		cout << "Your matrix rank is: " << maxRank << endl;
	}

	void multiplication(matrix& x, matrix& y, matrix& z) {
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


	void deleteLinAndCol(matrix x, int size, int lin, int col, matrix& newmatrix) {
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
		for (int i = 0; i < size - 1; i++) {
			if (i == lin) {
				offsetLin = 1;
			}
			offsetCol = 0;
			for (int j = 0; j < size - 1; j++) {
				if ((j == col) && (j != (size - 1))) {
					offsetCol = 1;
				}
				newmatrix.table[i][j] = x.table[i + offsetLin][j + offsetCol];
			}
		}
	}
	
	int matrixDet(matrix x, int size) {

		int det = 0;
		int degree = 1;

		if (size == 1) {
			return x.table[0][0];
		}
		if (size == 2) {
			return x.table[0][0] * x.table[1][1] - x.table[0][1] * x.table[1][0];
		}

		matrix newmatrix;
		for (int j = 0; j < size; j++) {
			deleteLinAndCol(x, size, 0, j, newmatrix);
			det = det + (degree * x.table[0][j] * matrixDet(newmatrix, size - 1));
			degree = degree * (-1);
		}
		
		return det;
	}

	int InverseMatrix(matrix& x, int size) {
		double p = matrixDet(x, x.columns);
		if (p == 0) {
			cout << "Error.The determinant is zero." << endl;
			return 0;
		}
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
		newmatrix.columns = x.columns - 1;
		newmatrix.lines = x.lines - 1;
		for (int i = 0;i < x.columns; i++) {
			for (int j = 0; j < x.columns; j++) {
				deleteLinAndCol(x, x.columns, i, j, newmatrix);
				int st = (i+j);
				int result = -1;
				for (int m = 0; m <= st;m++) {
					result = result * (-1);
				}
				double d = matrixDet(newmatrix, newmatrix.columns);
				a.table[i][j] = result * d;
			}
		}
		show(a);
		cout << endl;
		matrix c;
		c.columns = x.columns;
		c.lines = x.lines;
		multiply_on_number(a, c, (1 / p));
		show(c);
		return 1;
	}


	//-------------------------------------------------------------
	void rank()
	{
		matrix a;
		int maxRank;
		if (a.lines >= a.columns)
		{
			maxRank = a.columns;
		}
		else
		{
			maxRank = a.lines;
		}
		filling(a, 1);
		gauss_Method(a);
		system("pause");
	}

	void sum() {
		matrix a;
		matrix b;
		matrix c;
		cout << "--- 1 matrix --- " << endl;
		filling(a, 1); //Enter the first one
		cout << "Your matrix: " << endl;

		while (true) {

			show(a);//show the 1 one

			b.columns = a.columns; //The 2 matrix has the same size
			b.lines = a.lines;
			b.table.resize(a.lines);
			cout << endl << "--- 2 matrix --- " << endl;
			filling(b, 2);
			cout << "Your matrix: " << endl;
			show(b);//show the 2 one

			summa(a, b, c);
			cout << endl << "Your matrix sum: " << endl;
			show(c); //show the finall one

			cout << endl << "--------------------------------------------";
			cout << endl << "Do you want to add one more matrix? Yes/No: ";

			char str[4];
			while ((strcmp(str, "No") != 0) or (strcmp(str, "Yes") != 0)) {//Wait for answer to continue or not
				cin >> str;
				if (strcmp(str, "No") == 0) {
					break;
				}
				else if (strcmp(str, "Yes") == 0) {
					break;
				}
				else {
					cout << "Try again: ";
				}
			}
			if (strcmp(str, "No") == 0) {
				break;
			}
			else {
				for (int i = 0; i < c.lines; i++) //1 matrix = finall matrix
				{
					for (int j = 0; j < c.columns; j++)
					{
						a.table[i][j] = c.table[i][j];
					}
				}
				b.table.resize(0);//Make 2 and finall matrixs clean
				c.table.resize(0);
				cout << "--- 1 matrix --- " << endl;
			}
		}
	}
	void sub() {
		matrix a;
		matrix b;
		matrix c;

		cout << "--- 1 matrix --- " << endl;
		filling(a, 1); //Enter the first one
		cout << "Your matrix: " << endl;

		while (true) {
			show(a);//show the 1 one

			b.columns = a.columns; //The 2 matrix has the same size
			b.lines = a.lines;
			b.table.resize(a.lines);
			cout << endl << "--- 2 matrix --- " << endl;
			filling(b, 2);
			cout << "Your matrix: " << endl;
			show(b);//show the 2 one

			subtraction(a, b, c);
			cout << endl << "Your matrix subtraction: " << endl;
			show(c); //show the finall one

			cout << endl << "--------------------------------------------";
			cout << endl << "Do you want to subtract one more matrix? Yes/No: ";

			char str[4];
			while ((strcmp(str, "No") != 0) or (strcmp(str, "Yes") != 0)) {//Wait for answer to continue or not
				cin >> str;
				if (strcmp(str, "No") == 0) {
					break;
				}
				else if (strcmp(str, "Yes") == 0) {
					break;
				}
				else {
					cout << "Try again: ";
				}
			}
			if (strcmp(str, "No") == 0) {
				break;
			}
			else {
				for (int i = 0; i < c.lines; i++) //1 matrix = finall matrix
				{
					for (int j = 0; j < c.columns; j++)
					{
						a.table[i][j] = c.table[i][j];
					}
				}
				b.table.resize(0);//Make 2 and finall matrixs clean
				c.table.resize(0);
				cout << "--- 1 matrix --- " << endl;
			}
		}
	}

	void multi_number() {
		matrix a;
		cout << "--- 1 matrix --- " << endl;
		filling(a, 1);
		cout << "Your matrix: " << endl;

		while (true) {
			show(a);

			double k;
			cout << endl << "Enter the number to multiply: ";
			cin >> k;

			matrix c;
			multiply_on_number(a, c, k);
			cout << endl << "Your multiplied matrix: " << endl;
			show(c);

			cout << endl << "--------------------------------------------";
			cout << endl << "Do you want to miltiply one more matrix? Yes/No: ";

			char str[4];
			while ((strcmp(str, "No") != 0) or (strcmp(str, "Yes") != 0)) {//Wait for answer to continue or not
				cin >> str;
				if (strcmp(str, "No") == 0) {
					break;
				}
				else if (strcmp(str, "Yes") == 0) {
					break;
				}
				else {
					cout << "Try again: ";
				}
			}
			if (strcmp(str, "No") == 0) {
				break;
			}
			else {
				for (int i = 0; i < c.lines; i++) //1 matrix = finall matrix
				{
					for (int j = 0; j < c.columns; j++)
					{
						a.table[i][j] = c.table[i][j];
					}
				}
				c.table.resize(0);//Make finall matrixs clean
				cout << "--- 1 matrix --- " << endl;
			}
		}
	}

	void multiply()
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

	int Det() {
		matrix x;
		cout << "--- 1 matrix --- " << endl;
		filling(x, 3);
		cout << "Your matrix: " << endl;
		show(x);
		cin.ignore();
		return matrixDet(x, x.columns);
	}



	void Inverse() {
		matrix x;
		cout << "--- 1 matrix --- " << endl;
		filling(x, 3);
		cout << "Your matrix: " << endl;
		show(x);
		InverseMatrix(x, x.columns);

	}
	//-------------------------------------------------------------
	int keys() {
		int key = 0;
		int code;
		do {
			system("cls");
			key = (key + 8) % 8;
			if (key == 0) cout << "-> Summa matrixs" << endl;
			else  cout << "   Summa matrixs" << endl;

			if (key == 1) cout << "-> Subtration matrixs" << endl;
			else  cout << "   Subtration matrixs" << endl;

			if (key == 2) cout << "-> Multiply on number" << endl;
			else  cout << "   Multiply on number" << endl;

			if (key == 3) cout << "-> Multiply matrixs" << endl;
			else  cout << "   Multiply matrixs" << endl;

			if (key == 4) cout << "-> Calculate the determinant of a matrix" << endl;
			else  cout << "   Calculate the determinant of a matrix" << endl;

			if (key == 5) cout << "-> Determine Inverse Matrix" << endl;
			else  cout << "   Determine Inverse Matrix" << endl;

			if (key == 6) cout << "-> Determine the rank of the matrix" << endl;
			else  cout << "   Determine the rank of the matrix" << endl;

			if (key == 7) cout << "-> Exit" << endl;
			else  cout << "   Exit" << endl;

			code = _getch();
			if (code == 224)
			{
				code = _getch();
				if (code == 80) key++;
				if (code == 72) key--;
			}
		} while (code != 13);
		system("cls");
		return key;
	}

public:
	void menu() {
		int answer = keys();
		while (answer != 7) {
			switch (answer)
			{
			case 0: {
				cout << "    Summa    " << endl;
				sum();
				break;
			}
			case 1: {
				cout << "    Subtration    " << endl;
				sub();
				break;
			}
			case 2: {
				cout << "    Multipling on number    " << endl;
				multi_number();
				break;
			}
			case 3: {
				cout << "    Multipling matrixs    " << endl;
				multiply();
				break;
			}
			case 4: {
				cout << "    Determinant of a matrix    " << endl;
				cout << "Determinant of a matrix="<<Det() << endl;
				system("pause");
				
				break;
			}
			case 5: {
				cout << "    Inverse Matrix    " << endl;
				Inverse();
				system("pause");
				break;
			}
			case 6: {
				cout << "    Rank of the matrix    " << endl;
				rank();
				break;
			}
			case 7: {
				cout << "    You left the program    " << endl;
				break;
			}
			}
			int answer = keys();
		}
	}
};

int main()
{
	calculator calcV1;
	calcV1.menu();
	return 0;
}
