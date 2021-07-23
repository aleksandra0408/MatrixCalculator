#include "prototype.h"
using namespace std; 

matrix calculator::del_Line_Column(matrix x, int i, int j)
{
	x.table.erase(x.table.begin() + i);
	x.lines = x.table.size();
	for (int n = 0; n < x.lines; n++)
	{
		x.table[n].erase(x.table[n].begin() + j);
	}
	x.columns = x.table[0].size();
	return x;
}
void calculator::minor_Enum(matrix x)
{
	matrix nMinor = x;
	if (nMinor.lines == 2)
	{
		if (x.table[0][0] * x.table[1][1] - x.table[0][1] * x.table[1][0] == 0)
		{
			if ((x.table[0][0] == 0) && (x.table[1][1] == 0) && (x.table[0][1] == 0) && (x.table[1][0] == 0));
			else rankList[1] = 1;
		}
		else rankList[2] = 1;
	}
	else
	{
		if (matrixDet(nMinor, nMinor.lines) != 0) rankList[nMinor.lines] = 1;
		for (int i = 0; i < x.lines; i++)
		{
			for (int j = 0; j < x.columns; j++)
			{
				nMinor = del_Line_Column(x, i, j);
				if (matrixDet(nMinor, nMinor.table.size()) != 0) rankList[nMinor.lines] = 1;
				minor_Enum(nMinor);
			}
		}
	}

}
void calculator::matrix_Rank()
{
	double rank = 0;
	matrix x;
	filling(x,1);
	
	for (int i = 0; i <= x.lines; i++)
	{
		rankList.push_back(0);
	}
	

	
	if (x.lines == x.columns)
	{
		if (x.lines == 0)           rank = 0;
		else if (x.lines == 1)
		{
			if (x.table[0][0] == 0) rank = 0;
			else                    rank = 1;
		}
		else if (x.lines == 2)
		{
			rank = x.table[0][0] * x.table[1][1] - x.table[0][1] * x.table[1][0];
			if ((rank == 0) && (x.table[0][0] == 0) && (x.table[1][1] == 0) && (x.table[0][1] == 0) && (x.table[1][0] == 0)) {}
			else if (rank == 0)     rank = 1;
			else                    rank = 2;
		}
		else
		{
			minor_Enum(x);
			for (int i = 0; i < rankList.size(); i++)
			{
				cout << rankList[i];
			}
			cout << endl;
			for (int i = rankList.size()-1; i >= 0; i--)
			{
				if (rankList[i] != 0)
				{
					rank = i;
					break;
				}
			}
		}
	}
	else
	{

	}
	cout << "Your Matrix Rank is: " << rank << endl;
	system("pause");
	rankList.resize(0);
}