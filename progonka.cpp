// Chisl_met_6sem_2_2.cpp: определяет точку входа для консольного приложения.
//Bogatyrev Ilia Sergeevich KMBO-03-14
////////////////////////////////////////////////////////////////////////////
//16x1-9x2=-27
//8x1-13x2-5x3=-84
//-3x2-21x3+9x4=-225
//-9x3+16x4-5x5=-89
//x4-9x5=69

#include "stdafx.h"
#include <iostream>

using namespace std;

void progonka(double **matrix, double *d, double *roots, int n);
void show_matrix(double **matrix, double *d, int n);
void enter_matrix(double **matrix, double *d, int n);
void check(double **matrix, double *d, double *roots, int n);

int main()
{
	int n = 5;
	double **matrix = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 16; matrix[0][1] = -9;
	matrix[1][0] = 8; matrix[1][1] = -13; matrix[1][2] = -5;
	matrix[2][1] = -3; matrix[2][2] = -21; matrix[2][3] = 9;
	matrix[3][2] = -9; matrix[3][3] = 16; matrix[3][4] = -5;
	matrix[4][3] = 1; matrix[4][4] = -9;
	double *d = new double[n];
	d[0] = -27; d[1] = -84; d[2] = -225; d[3] = -89; d[4] = 69;
	double *roots = new double[n];
	//enter_matrix(matrix, d, n);
	show_matrix(matrix, d, n);
	cout << endl;
	progonka(matrix, d, roots, n);
	cout << "Korni:" << endl;
	for (int i = 0; i < n; i++)
	{
		int temp = roots[i];
		cout << temp << " ";
	}
	check(matrix, d, roots, n);
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	};
    return 0;
}

void progonka(double **matrix, double *d, double *roots, int n)
{
	double *a = new double[n];
	double *b = new double[n];
	double *c = new double[n];
	double *P = new double[n];
	double *Q = new double[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = c[i] = 0;
		b[i] = matrix[i][i];
		P[i] = Q[i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		a[i] = matrix[i][i-1];
	}
	for (int i = 0; i < n - 1; i++)
	{
		c[i] = matrix[i][i + 1];
	}
	P[0] = -c[0] / b[0];
	Q[0] = d[0] / b[0];
	for (int i = 1; i < (n-1); i++)
	{
		P[i] = -c[i] / (b[i] + a[i] * P[i - 1]);
		Q[i] = (d[i] - a[i] * Q[i - 1]) / (b[i] + a[i] * P[i - 1]);
	}
	P[n-1] = 0;
	Q[n-1] = (d[n-1] - a[n-1] * Q[n - 2]) / (b[n-1] + a[n-1] * P[n - 2]);

	cout << endl;
	cout << "Progonochnye Koeffizienty" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "P[" << i + 1 << "] = " << P[i] << "; " << "Q[" << i + 1 << "] = " << Q[i] << "; " << endl;
	}
	cout << endl;

	for (int i = n-1 ; i >= 0 ; i--)
	{
		roots[i] = P[i] * roots[i + 1] + Q[i];
	}

	cout << endl << "Proverka iteracionnyh sootnosheniy" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << roots[i] << " | " << roots[i + 1] * P[i] + Q[i] << endl;
	}
	cout << endl;
}

void enter_matrix(double **matrix, double *d, int n)
{
	cout << "enter matrix" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << 'x' << '[' << i+1 << ']' << '[' << j+1  << ']' << '=' << ' ';
			cin >> matrix[i][j];
		}
		cout << 'd' << '[' << i + 1 << ']' << '=';
		cin >> d[i];
	}
	cout << endl << endl;
}

void show_matrix(double **matrix, double *d, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << 'x' << j + 1 << '+' << ' ';
		}
		cout << '=' << ' ' << d[i] << endl;
	}
}

void check(double **matrix, double *d, double *roots, int n)
{
	cout << endl << endl;
	cout << "Check" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = matrix[i][j] * roots[j];
			cout << temp << '+' << ' ';
		}
		cout << '=' << ' ' << d[i] << endl;
	}
}
