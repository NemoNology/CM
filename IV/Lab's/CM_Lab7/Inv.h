#pragma once

#include <iostream>

using namespace std;

void fill_matrixBT(double** t, double** b, double** a, const int n)			// заполнение матриц BT 
{
	double s1 = 0;
	double s2 = 0;

	for (int i = 0; i < n; i++)
	{
		b[i][0] = a[i][0];
	}

	for (int j = 0; j < n; j++)
	{
		t[0][j] = a[0][j] / b[0][0];
	}

	for (int k = 1; k < n; k++)
	{
		for (int i = k; i < n; i++)
		{
			for (int m = 0; m < k; m++)
			{
				s1 += b[i][m] * t[m][k];
			}
			b[i][k] = a[i][k] - s1;
			s1 = 0;
		}

		for (int j = k + 1; j < n; j++)						// t[k][j] = 1/b[k][k] * (a[k][j] - summ(m=0, k-1)(b[k][m]*t[m][j])) (j= k + 1 , ... , n - 1 )
		{
			{
				for (int m = 0; m < k; m++)
				{
					s2 += b[k][m] * t[m][j];
				}
				t[k][j] = 1 / b[k][k] * (a[k][j] - s2);
				s2 = 0;
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (i < k)
				b[i][k] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (i > k)
				t[i][k] = 0;
			if (i == k)
			{
				t[i][k] = 1;
			}
		}
	}
}


void fill_matrixBneg(double** b, double** y, int n)  		// заполнение обратной матрицы B (y - обратная матрица)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i)
				y[i][j] = 0;
			else if (j == i)
				y[i][j] = 1 / b[i][i];
			else if (j < i)
			{
				sum = 0;
				for (int m = j; m < i; m++)
					sum = sum + b[i][m] * y[m][j];
				y[i][j] = -1 / b[i][i] * sum;
			}
		}
	}
}


void fill_matrixTneg(double** t, double** x, int n)  		// заполнение обратной матрицы T (x - обратная матрица)
{
	double sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (j < i)
				x[i][j] = 0;
			else if (j == i)
				x[i][j] = 1;
			else if (j > i)
			{
				x[i][j] = 0;
				for (int m = i + 1; m <= j; m++)
					x[i][j] = x[i][j] - t[i][m] * x[m][j];
			}
		}
	}
}


void fill_matrixAneg(double** a, double** x, double** y, int n)  // заполнение обратной матрицы A (x,y - обратные матрицы)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int m = 0; m < n; m++)
				sum += x[i][m] * y[m][j];
			a[i][j] = sum;
			sum = 0;
		}
	}
}


double** minV(double** A) {
	int n = 5;

	double** B = new double* [n];
	for (int i = 0; i < n; i++)
	{
		B[i] = new double[n];
	}

	double** T = new double* [n];
	for (int i = 0; i < n; i++)
	{
		T[i] = new double[n];
	}

	double** X = new double* [n];
	for (int i = 0; i < n; i++)
	{
		X[i] = new double[n];
	}

	double** Y = new double* [n];
	for (int i = 0; i < n; i++)
	{
		Y[i] = new double[n];
	}

	double** Aneg = new double* [n];
	for (int i = 0; i < n; i++)
	{
		Aneg[i] = new double[n];
	}

	fill_matrixBT(T, B, A, n);
	fill_matrixBneg(B, Y, n);
	fill_matrixTneg(T, X, n);
	fill_matrixAneg(Aneg, X, Y, n);

	for (int i = 0; i < n; i++)
		delete B[i];
	delete[] B;

	for (int i = 0; i < n; i++)
		delete T[i];
	delete[] T;

	for (int i = 0; i < n; i++)
		delete X[i];
	delete[] X;

	for (int i = 0; i < n; i++)
		delete Y[i];
	delete[] Y;

	return Aneg;
}