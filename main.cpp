// Lab_7_2_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 0
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void ChangeMaxElemEveryPairRowWithMinElemOddRow(int** &a, const int k, const int n);
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int SearchMax(int* a, const int n);
int SearchMin(int* a, const int n);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n, k;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High);
	
	if (k == 1)
		cout << "There won't pair and odd rows.Try again" << endl;
	Print(a, k, n);
	cout << "After modification: " << endl;
	ChangeMaxElemEveryPairRowWithMinElemOddRow(a, k, n);
	Print(a, k, n);
	
	for (int i = 0; i < k; i++)
		delete [] a[i];
	delete [] a;
	return 0;
}
void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int SearchMin(int* a, const int n)
{
	int index_min = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[index_min] > a[j])
		{
			index_min = j;
		}
	}
	return index_min;
}
int SearchMax(int *a, const int n)
{
	int index_max = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[index_max] < a[j])
		{
			index_max = j ;
		}
	}
	return index_max;
}
void ChangeMaxElemEveryPairRowWithMinElemOddRow(int** &a, const int k, const int n)
{
	for (int i = 1; i < k; i+=2)
	{
		int index_min = SearchMin(a[i - 1], n);
		int index_max = SearchMax(a[i], n);
		int temp = a[i - 1][index_min];
		a[i - 1][index_min] = a[i][index_max];
		a[i][index_max] = temp;
		
	}
}
