// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//Bogatyrev Ilia Sergeevich KMBO-03-14 Quicksort_c++_and_asm

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

void show_mass(int *ptr, int n);
void quicksort(int *ptr, int l, int r);
int partition(int *ptr, int l, int r);
void asm_qsort(int *ar, int l, int r);
void asm_bubble(int *ar, int l, int r);
void bubble(int *ar, int l, int r);

int main()
{
	//create massive
	cout << "Enter size of massive:";
	int n; //cin >> n; 
	n = 20;
	int *ptrarray = new int[n];
	for (int i = 0; i < n; i++)
	{
		ptrarray[i] = rand() % 20;
	}
	int good[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
	int bad[] = { 19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };

	cout << "Start massive:";
	show_mass(ptrarray, n);
	//quicksort(bad, 0, n - 1);
	asm_qsort(ptrarray, 0, n);
	//asm_bubble(bad, 0, n-1);
	//bubble(bad, 0, n);
	cout << endl << "After sort:";
	show_mass(ptrarray, n);
	cout << clock() << endl;
	return 0;
}

void show_mass(int *ptr, int n)
{
	cout << '[' << ' ';
	for (int i = 0; i < n; i++)
	{
		cout << ptr[i] << ' ';
	};
	cout << ']' << endl;
}

void quicksort(int *ptr, int l, int r)
{
	if (l < r)
	{
		int q = partition(ptr, l, r);
		quicksort(ptr, l, q - 1);
		quicksort(ptr, q + 1, r);
	}
}

int partition(int *ptr, int l, int r)
{
	int wall = l - 1;
	int pivot = r;
	for (int j = wall + 1; j<pivot; j++)
	{
		if (ptr[j] < ptr[pivot])
		{
			wall++;
			int temp = ptr[wall];
			ptr[wall] = ptr[j];
			ptr[j] = temp;
		}
	};
	wall++;
	int temp = ptr[wall];
	ptr[wall] = ptr[pivot];
	ptr[pivot] = temp;
	return wall;
}


void asm_qsort(int *ar, int l, int r)
{
	int p;
	_asm
	{
		pushad;
		mov esi, ar;
		popad;
	}
	cout << p << endl;
}


void asm_bubble(int *ar, int l, int r)
{
	_asm
	{
		pushad;
		//move count of iterations in ecx
		//number of iteration into stack
		xor edx, edx;
		mov edx, r;
		//move pointer of array to esi
		mov esi, ar;
	start:
		xor ecx, ecx;
		cmp edx, 0
		je endofall;
	cycle:
		mov eax, [esi + ecx * 4]; //previous 
		mov ebx, [esi + ecx * 4 + 4]; //next
		cmp eax, ebx;
		jG swapper;

	end_swapper:
		inc ecx;
		cmp ecx, edx;
		jne cycle;
		dec edx;
		jmp start;

	swapper:
		mov [esi + ecx * 4 + 4], eax; //previous 
		mov [esi + ecx * 4], ebx; //next
		jmp end_swapper;

	endofall:
		popad;
	}
	//cout << first << ' ' << last << endl;
}
void bubble(int *ar, int l, int r)
{
	for (int i = 0; i < r+1; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if (ar[j - 1] > ar[j])
			{
				int temp = ar[j - 1];
				ar[j - 1] = ar[j];
				ar[j] = temp;
			}
		}
	}
}
