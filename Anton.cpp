#include "prototype.h"
using namespace std;

int  calculator::check_Lines(matrix& x)
{
	int dependLine = -1;
	vector<double> tempLine;
	tempLine.resize(x.columns);
	for (int i = 0; i < x.lines - 1; i++)
	{
		tempLine.clear();
		tempLine.resize(x.columns);
		for (int n = 0; n <= i; n++)
		{
			for (int m = 0; m < x.columns; m++)
			{
				tempLine[m] = tempLine[m] + x.table[n][m];
			}
		}

		int cnt = 0;
		cnt = i + 1;
		for (int s = cnt; s < x.lines; s++)
		{
			int zeros;
			vector<double> tempLine1;
			tempLine1.clear();
			tempLine1.resize(x.columns);
			double tempMultipler = 0;
			tempMultipler = x.table[s][0] / tempLine[0];
			for (int n = 0; n < x.columns; n++)
			{
				tempLine1[n] = x.table[s][n] - tempLine[n] * tempMultipler;
			}
			zeros = 0;
			for (int n = 0; n < x.columns; n++)
			{
				zeros = zeros + tempLine1[n];
			}
			if (zeros == 0)
			{
				x.table.erase(x.table.begin() + s);
				x.lines--;
				s--;
				dependLine = 1;
			}
		}
	}
	return dependLine;
}
void calculator::shift(matrix& x)
{
	check_Lines(x);
	matrix tempM;
	tempM.table.resize(x.lines);
	for (int i = 0; i < x.lines; i++)
	{
		tempM.table[i].resize(x.columns);
	}
	tempM.lines = x.lines;
	tempM.columns = x.columns;

	for (int i = 0; i < x.columns; i++)
	{
		tempM.table[0][i] = x.table[x.lines - 1][i];
	}

	for (int i = 0; i < x.lines - 1; i++)
	{
		for (int j = 0; j < x.columns; j++)
		{
			tempM.table[i + 1][j] = x.table[i][j];
		}
	}

	for (int i = 0; i < x.lines; i++)
	{
		for (int j = 0; j < x.columns; j++)
		{
			x.table[i][j] = tempM.table[i][j];
		}
	}
}
void calculator::resort(matrix& x)
{
	matrix tempM;
	tempM.table.resize(x.lines);
	for (int i = 0; i < x.lines; i++)
	{
		tempM.table[i].resize(x.columns);
	}
	tempM.lines = x.lines;
	tempM.columns = x.columns;
	tempM.table = x.table;

	for (int i = 0; i < x.lines - 1; i++)
	{
		for (int j = i; j < x.lines - 1; j++)
		{
			vector<double> tempLine;
			tempLine.clear();
			tempLine.resize(x.columns);

			tempLine = x.table[j + 1];
			x.table[j + 1] = x.table[i];
			x.table[i] = tempLine;

			show(x);
			x.table = tempM.table;
		}
		x.table = tempM.table;
	}
}
int  calculator::rank()
{
	return 0;
}