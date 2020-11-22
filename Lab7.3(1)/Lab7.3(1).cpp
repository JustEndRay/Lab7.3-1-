#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, int rowcount, int colcount, const int Low, const int High);
void Print(int** a, int rowcount, int colcount);
int k(int** a, int rowcount, int colcount);
void max(int** a, int rowcount, int colcount, const int Low, const int High);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -8;
	int High = 14;
	int rowcount, colcount;
	cout << "rowcount = "; cin >> rowcount;
	cout << "colcount = "; cin >> colcount;
	int** a = new int * [rowcount];
	for (int i = 0; i < rowcount; i++) a[i] = new int[colcount];
	Create(a, rowcount, colcount, Low, High);
	Print(a, rowcount, colcount);
	cout << "rows without 0 = " << k(a, rowcount, colcount);
	max(a, rowcount, colcount, Low, High);
	return 0;
}
void Create(int** a,  int rowcount, int colcount, const int Low, const int High)
{
	for (int i = 0; i < rowcount; i++)
		for (int j = 0; j < colcount; j++)a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, int rowcount, int colcount)
{
	cout << endl;
	for (int i = 0; i < rowcount; i++)
	{
		for (int j = 0; j < colcount; j++)cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int k(int** a, int rowcount, int colcount)
{
	int f = 0 , d = 0;
	for (int i = 0; i < rowcount; i++) {
		for (int j = 0; j < colcount; j++)
		{
			if (a[i][j] != 0) { f++; }
		}
		if (f == colcount) { d++; }
		f = 0;
	}
	return d;
}
void max(int** a, int rowcount, int colcount, const int Low, const int High)
{
	int c = 0;
	for (int i = 0; i < rowcount; i++)
		for (int j = 0; j < colcount; j++)if (a[i][j] == High) { c++; };
	cout <<endl<<"count of max elements in the matrix = "<< c;
}