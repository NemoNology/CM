#include <iostream>
#include "matr.h"
#include "inv.h"
#include <vector>
int main()
{
	setlocale(0, "ru");

	double** a = new double* [5];			// исходная матрицы
	for (int i = 0; i < 5; i++)
		a[i] = new double[5];

	double** bx;
	double** ax;
	double** b;
	double** vec = mNull(5);			// матрица содерж. нули

	/*-----заполнение исходной матрицы-----*/
	a[0][0] = 2;
	a[0][1] = 0;
	a[0][2] = 2;
	a[0][3] = 2;
	a[0][4] = 5;
	a[1][0] = -1;
	a[1][1] = 2;
	a[1][2] = -1;
	a[1][3] = -3;
	a[1][4] = 0;
	a[2][0] = -2;
	a[2][1] = -4;
	a[2][2] = 0;
	a[2][3] = 4;
	a[2][4] = 5;
	a[3][0] = -3;
	a[3][1] = -4;
	a[3][2] = -1;
	a[3][3] = -1;
	a[3][4] = 0;
	a[4][0] = -3;
	a[4][1] = 3;
	a[4][2] = -2;
	a[4][3] = -1;
	a[4][4] = -5;

	const int n = 5;				// размер матриц
	cout << "изначалальная матрица A" << endl;
	show(a);
	cout << endl;

	vector<double**> data;

	/*-----метод Фробениуса-----*/
	ax = a;

	for (int k = 2; k <= n; k++) {
		b = E(n);
		for (int j = 0; j < n; j++) {
			if (j != n - k)
				b[n - k][j] = -ax[n - (k - 1)][j] / ax[n - (k - 1)][n - k];
			else
				b[n - k][j] = 1 / ax[n - (k - 1)][n - k];
		}

		cout << "Пересчёт матрицы B" << k << endl;
		show(b);
		cout << endl;

		bx = minV(b);
		cout << "Обратная матрица B" << k << endl;
		show(bx);
		cout << endl;

		ax = mMull(mMull(bx, ax), b);
		cout << "Новая матрица A" << k << endl;
		show(ax);
		cout << endl;
		data.push_back(b);
	}


	/*-----нахожд. собстевенных векторов-----*/
	double** tmp;
	double s;
	double lambda = 7.79216;

	vector<double**> lambdavectors;			// вектор, содерж. матрицы типа double
	double** lambdavec = mNull(5);			// матрица из нулей

	for (int i = 0; i < 5; i++)			// заполнение маириицы
	{
		lambdavec[i][0] = pow(lambda, 4 - i);
	}

	lambdavectors.push_back(lambdavec);		// добавляем полученное значение в конец

	cout << "lambdavec1" << endl;			// выводим всё это дело
	show(lambdavec);
	cout << endl;

	for (int m = 2; m <= 5; m++)
	{
		tmp = data.back();
		data.pop_back();
		lambdavec = lambdavectors.back();

		cout << "matr" << endl;
		show(tmp);
		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			s = 0;
			for (int k = 0; k < 5; k++)
			{
				s = s + tmp[i][k] * lambdavec[k][0];
			}

			vec[i][0] = s;
		}

		lambdavectors.push_back(vec);
		cout << "Lambda vec" << m << endl;
		show(vec);
		cout << endl;
	}

	cout << "Ответ:" << endl;
	show(vec);

	/*-----очистка памяти-----*/
	for (int i = 0; i < 5; i++)
		delete[] a[i];
	delete[] a;

	for (int i = 0; i < 5; i++)
		delete[] b[i];
	delete[] b;

	for (int i = 0; i < 5; i++)
		delete[] bx[i];
	delete[] bx;

	for (int i = 0; i < 5; i++)
		delete[] ax[i];
	delete[] ax;

	for (int i = 0; i < 5; i++)
		delete[] vec[i];
	delete[] vec;

	for (int i = 0; i < 5; i++)
		delete[] tmp[i];
	delete[] tmp;
}