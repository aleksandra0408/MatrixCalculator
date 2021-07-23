#include "prototype.h"
using namespace std;
void calculator::filling(matrix& x, int turn)//if turn == 2 then the enter of lines and colomns is skipping.
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
void calculator::show(matrix& x)
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
void calculator::deleting_Zeros(matrix& x) // If you matrix have zeros lines or columns this function will delete it.
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
	for (int unsigned(i) = 0; i < unsigned(delLines.size()); i++)
	{
		x.table.erase(x.table.begin() + delLines[delLines.size() - i - 1]);
		x.lines--;
	}

	// deleting zeros columns.
	if (x.lines == 0) x.columns = 0;
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
			for (int unsigned(i) = 0; i < unsigned(delLines.size() - 1); i++)
			{
				x.table[i].erase(x.table[i].begin() + delLines[delLines.size() - i - 1]);
				x.columns--;
			}
		}
	}
}