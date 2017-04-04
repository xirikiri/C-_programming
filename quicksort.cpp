// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void show_mass(short *ptr, short n);
void quicksort(short *ptr, short n, short wall);
void swap(short *ptr, short i, short j);

int main()
{
	//create massive
	cout << "Enter size of massive:";
	short n; cin >> n;
	short *ptrarray = new short[n];
	for (short i = 0; i <= n; i++)
	{
		ptrarray[i] = rand() % 30;
	}
	cout << "Start massive:";
	show_mass(ptrarray, n);
	quicksort(ptrarray, 0, n);
	cout << endl << "After sort:";
	show_mass(ptrarray, n);
	return 0;
}

void show_mass(short *ptr, short n)
{
	cout << '[' << ' ';
	for (short i = 0; i <= n; i++)
	{
		cout << ptr[i] << ' ';
	};
	cout << ']' << endl;
}

void quicksort(short *ptr, short start, short end)
{
	if (start < end)
	{
		short p = end/2;
		swap(ptr, p, end);
		short wall = start;
		for (short i = start; i < end; i++)
		{
			if (ptr[i] < ptr[p]) { swap(ptr, wall, i); wall++; };
		};
		swap(ptr, wall, p);
		quicksort(ptr, start, wall - 1);
		quicksort(ptr, wall + 1, end);
	};
}

void swap(short *ptr, short i, short j)
{
	short temp = ptr[i];
	ptr[i] = ptr[j];
	ptr[j] = temp;
}
