// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//Bogatyrev Ilia Sergeevich KMBO-03-14 Quicksort_c++_and_asm

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
/*
void quicksort(int *ar, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = ar[(left + right) / 2];
	//rtition 
	while (i <= j) {
		while (ar[i] < pivot)
			i++;
		while (ar[j] > pivot)
			j--;
		if (i <= j) {
			tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp;
			i++;
			j--;
		}
	};

	
	if (left < j)
		quicksort(ar, left, j);
	if (i < right)
		quicksort(ar, i, right);
}
*/
void show_mass(int *ptr, int n);
void quicksort(int *ptr, int l, int r);
int partition(int *ptr, int l, int r);
void asm_qsort(int *ar, int l, int r);
void asm_bubble(int *ar, int l, int r);
void bubble(int *ar, int l, int r);
void quicksort_asm(int* pole, unsigned short delka_pole);

int main()
{
	//create massive
	//cout << "Enter size of massive:";
	int n; //cin >> n; 
	n = 100;
	unsigned short k = n;
	int *ptrarray_rand1 = new int[n];
	/////////////////////////////
	//4 copy of random array
	for (int i = 0; i < n; i++)
	{
		ptrarray_rand1[i] = rand() % 100;
	}
	int *ptrarray_rand2 = new int[n];
	int *ptrarray_rand3 = new int[n];
	int *ptrarray_rand4 = new int[n];
	for (int i = 0; i < n; i++)
	{
		ptrarray_rand2[i] = ptrarray_rand1[i];
		ptrarray_rand3[i] = ptrarray_rand1[i];
		ptrarray_rand4[i] = ptrarray_rand1[i];
	}
	//////////////////////////////
	//4 good array
	int *ptrarray_good1 = new int[n];
	int *ptrarray_good2 = new int[n];
	int *ptrarray_good3 = new int[n];
	int *ptrarray_good4 = new int[n];
	for (int i = 0; i < n; i++)
	{
		ptrarray_good1[i] = i;
		ptrarray_good2[i] = i;
		ptrarray_good3[i] = i;
		ptrarray_good4[i] = i;
	}
	/////////////////////////////
	//4 bad array
	int *ptrarray_bad1 = new int[n];
	int *ptrarray_bad2 = new int[n];
	int *ptrarray_bad3 = new int[n];
	int *ptrarray_bad4 = new int[n];
	for (int i = 0; i < n; i++)
	{
		ptrarray_bad1[i] = n - i;
		ptrarray_bad2[i] = n - i;
		ptrarray_bad3[i] = n - i;
		ptrarray_bad4[i] = n - i;
	}
	cout << "good_array" << endl;
	//show_mass(ptrarray_bad1, n);
	int time_start = clock();
	
	quicksort(ptrarray_good1, 0, n-1);
	int time_qsort_c_good = clock() - time_start;
	cout << "c_qsort_good = " << time_qsort_c_good << endl;
	show_mass(ptrarray_good1, n);

	quicksort_asm(ptrarray_good2, k);
	int time_qsort_asm_good = clock() - time_qsort_c_good;
	cout << "asm_qsort_good = " << time_qsort_asm_good << endl;
	show_mass(ptrarray_good2, n);

	bubble(ptrarray_good3, 0, n);
	int time_bubble_c_good = clock() - time_qsort_asm_good;
	cout << "c_bubble_good = " << time_bubble_c_good << endl;
	show_mass(ptrarray_good3, n);

	asm_bubble(ptrarray_good4, 0, n - 1);
	int time_bubble_asm_good = clock() - time_bubble_c_good;
	cout << "asm_bubble_good = " << time_bubble_asm_good << endl;
	show_mass(ptrarray_good4, n);

	quicksort(ptrarray_bad1, 0, n - 1);
	int time_qsort_c_bad = clock() - time_bubble_asm_good;
	cout << "c_qsort_bad = " << time_qsort_c_bad << endl;
	show_mass(ptrarray_bad1, n);

	quicksort_asm(ptrarray_bad2, k);
	int time_qsort_asm_bad = clock() - time_qsort_c_bad;
	cout << "asm_qsort_bad = " << time_qsort_asm_bad << endl;
	show_mass(ptrarray_bad2, n);

	bubble(ptrarray_bad3, 0, n);
	int time_bubble_c_bad = clock() - time_qsort_asm_bad;
	cout << "c_bubble_bad = " << time_bubble_c_bad << endl;
	show_mass(ptrarray_bad3, n);

	asm_bubble(ptrarray_bad4, 0, n - 1);
	int time_bubble_asm_bad = clock() - time_bubble_c_bad;
	cout << "asm_bubble_bad = " << time_bubble_asm_bad << endl;
	show_mass(ptrarray_bad4, n);

	quicksort(ptrarray_rand1, 0, n - 1);
	int time_qsort_c_rand = clock() - time_bubble_asm_bad;
	cout << "c_qsort_rand = " << time_qsort_c_rand << endl;
	show_mass(ptrarray_rand1, n);

	quicksort_asm(ptrarray_rand2, k);
	int time_qsort_asm_rand = clock() - time_qsort_c_rand;
	cout << "asm_qsort_rand = " << time_qsort_asm_rand << endl;
	show_mass(ptrarray_rand2, n);

	bubble(ptrarray_rand3, 0, n);
	int time_bubble_c_rand = clock() - time_qsort_asm_rand;
	cout << "c_bubble_rand = " << time_bubble_c_rand << endl;
	show_mass(ptrarray_rand3, n);

	asm_bubble(ptrarray_rand4, 0, n - 1);
	int time_bubble_asm_rand = clock() - time_bubble_c_rand;
	cout << " asm_bubble_rand = " << time_bubble_asm_rand << endl;
	show_mass(ptrarray_rand4, n);
	
	//asm_bubble(bad, 0, n-1);
	//bubble(bad, 0, n);
	//cout << endl << "After sort:";
	//show_mass(ptrarray_bad1, n);
	//cout << clock() << endl;
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
	for (int j = wall + 1; j < pivot; j++)
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

void quicksort_asm(int* pole, unsigned short delka_pole)
{
	_asm
	{
		movzx eax, delka_pole
		test eax, eax
		jz Exit

		mov esi, pole
		lea edi, dword ptr[esi + eax * 4 - 4]
		mov ebx, edi

		Start :
		lea eax, dword ptr[esi + edi]
			shr eax, 1
			and eax, ~0x03
			mov ecx, dword ptr[eax]

			Left :
			cmp ecx, dword ptr[esi]
			jng Right
			lea esi, dword ptr[esi + 4]
			jmp Left

			Right :
		cmp ecx, dword ptr[edi]
			jnl Swap
			lea edi, dword ptr[edi - 4]
			jmp Right

			Swap :
		cmp esi, edi
			ja NestingLeft

			mov eax, dword ptr[esi]
			mov edx, dword ptr[edi]
			mov dword ptr[esi], edx
			mov dword ptr[edi], eax
			lea esi, dword ptr[esi + 4]
			lea edi, dword ptr[edi - 4]
			cmp esi, edi
			jb Left

			NestingLeft :
		sub edi, pole
			jbe NestingRight
			shr edi, 2
			lea edi, dword ptr[edi + 1]
			push edi
			mov eax, pole
			push eax
			call quicksort_asm
			add esp, 8

			NestingRight:
		mov eax, ebx
			sub eax, esi
			jbe Exit

			shr eax, 2
			lea eax, dword ptr[eax + 1]

			mov pole, esi
			mov delka_pole, ax
			mov edi, ebx
			jmp Start

			Exit :
	}
}
