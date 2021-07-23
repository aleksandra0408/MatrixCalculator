#include "prototype.h"
using namespace std;

void calculator::summa(matrix& a, matrix& b, matrix& c) 
{
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
void calculator::subtraction(matrix& a, matrix& b, matrix& c) 
{
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
void calculator::sum()
{
	matrix a;
	matrix b;
	matrix c;
	cout << "--- 1 matrix --- " << endl;
	filling(a, 1); //Enter the first one
	cout << "Your matrix: " << endl;

	while (true)
	{

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
			if (strcmp(str, "No") == 0) break;
			else if (strcmp(str, "Yes") == 0) break;
			else cout << "Try again: ";
		}
		if (strcmp(str, "No") == 0) break;
		else
		{
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
void calculator::sub()
{
	matrix a;
	matrix b;
	matrix c;

	cout << "--- 1 matrix --- " << endl;
	filling(a, 1); //Enter the first one
	cout << "Your matrix: " << endl;

	while (true) 
	{
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
			if (strcmp(str, "No") == 0)	break;
			else if (strcmp(str, "Yes") == 0) break;
			else cout << "Try again: ";
		}
		if (strcmp(str, "No") == 0)	break;
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
void calculator::multiply_on_number(matrix& a, matrix& c, double k)
{
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
void calculator::multi_number()
{
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
		while ((strcmp(str, "No") != 0) or (strcmp(str, "Yes") != 0)) //Wait for answer to continue or not
		{
			cin >> str;
			if (strcmp(str, "No") == 0)  break;
			else if (strcmp(str, "Yes") == 0) break;
			else cout << "Try again: ";
		}
		if (strcmp(str, "No") == 0) break;
		else 
		{
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
int  calculator::keys() 
{
	int key = 0;
	int code;
	do 
	{
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
void calculator::menu() 
{
	int answer = keys();
	while (answer != 7) 
	{
		switch (answer)
		{
		case 0: 
		{
			cout << "    Summa    " << endl;
			sum();
			break;
		}
		case 1: 
		{
			cout << "    Subtration    " << endl;
			sub();
			break;
		}
		case 2: {
			cout << "    Multipling on number    " << endl;
			multi_number();
			break;
		}
		case 3: 
		{
			cout << "    Multipling matrixs    " << endl;
			multiply();
			break;
		}
		case 4:
		{
			cout << "    Determinant of a matrix    " << endl;
			cout << Det();
			break;
		}
		case 5: 
		{
			cout << "    Inverse Matrix    " << endl;
			Inverse();
			break;
		}
		case 6:
		{
			cout << "    Rank of the matrix    " << endl;
			matrix_Rank();
			break;
		}
		case 7: 
		{
			cout << "    You left the program    " << endl;
			break;
		}
		}
		int answer = keys();
	}
}