// Ch_met_2_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void fill_matrix(double **matrix, int n);
void show_matrix(double **matrix, int n);
void progonka(double **matrix, int n);

int main()
{
	int n = 5;
	//create matrix
	double **matrix = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n + 1];
	}
	fill_matrix(matrix, n);
	show_matrix(matrix, n);
	//Clear memory
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
    return 0;
}

void fill_matrix(double **matrix, int n)
{
	cout << "Enter the matrix" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (j < n)
			{
				cout << "X" << '[' << i + 1 << ']' << '[' << j + 1 << ']' << '=' << ' ';
				cin >> matrix[i][j];
			}
			else
			{
				cout << "F" << '[' << i + 1 << ']' << '=' << ' ';
				cin >> matrix[i][j];
			}
		}
	}
}

void show_matrix(double **matrix, int n)
{
	cout << "Your matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (j < n)
			{
				if (matrix[i][j] >= 0) { cout << '+' << matrix[i][j] << 'x' << j+1 << ' ' ; }
				else { cout << '-' << matrix[i][j] << 'x' << j + 1 << ' '; }
			}
			else { cout << '=' << matrix[i][j]; }
		}
		cout << endl;
	}
}

void progonka(double **matrix, int n)
{

}
