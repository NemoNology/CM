#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <exception>

using namespace std;

void ShowVector(vector<double> x) {

	cout << "\n";

	for (int i = 0; i < x.size(); i++) {

		cout << setprecision(4) << setw(10) << x[i];

	}

	cout << "\n";

}

void ShowVector(vector<vector<double>> x) {

	for (int i = 0; i < x.size(); i++) {

		cout << "\n";

		for (int j = 0; j < x[i].size(); j++) {

			cout << setprecision(4) << setw(10) << x[i][j];

		}

	}

	cout << "\n";

}


// Функция перемножения матриц
vector<vector<double>> MMul(vector<vector<double>> a, vector<vector<double>> b) {

	vector<vector<double>> c;
	c.resize(a.size());

	for (int i = 0; i < a.size(); i++) {

		c[i].resize(b[0].size());

		for (int j = 0; j < b[0].size(); j++) {

			c[i][j] = 0;

			for (int k = 0; k < b.size(); k++) {

				c[i][j] += a[i][k] * b[k][j];

			}

		}

	}

	return c;

}


// Функция присоединения единичной матрицы к матрице a
vector<vector<double>> AddSingleMtoM(vector<vector<double>> a) {

	int k;

	for (int i = 0; i < a.size(); i++) {

		k = a[i].size();

		a[i].resize(a[i].size() * 2);

		for (int j = 0; j < a[i].size(); j++) {

			if (j >= k) {

				a[i][j] = 0;

			}

			if (j == i + k) {

				a[i][j] = 1;

			}

		}

	}

	return a;

}



// Функция создания единичной матрицы порядка n
vector<vector<double>> E(int n) {

	if (n < 1) {

		throw invalid_argument("Invalid size for matrix (size < 1)");

	}

	vector<vector<double>> a;
	a.resize(n);

	for (int i = 0; i < n; i++) {

		a[i].resize(n);

		for (int j = 0; j < n; j++) {

			if (j == i) {

				a[i][j] = 1;

			}
			else {

				a[i][j] = 0;

			}

		}

	}

	return a;

}



// Функция нахождения обратной матрицы, путём присоединения единичной
vector<vector<double>> MInv(vector<vector<double>> A) {

	// E ~ 0; n - кол-во столбцов в первоначальной матрице
	double e = 0.00001;
	int n = A[0].size(), m;

	// Добавляем единичную матрицу
	A = AddSingleMtoM(A);

	// Считаем
	for (int k = 0; k < n; k++) {

		if (fabs(A[k][k]) < e) {

			m = k + 1;

			while (fabs(A[k][k]) < e) {

				if ((fabs(A[m][k]) > e) || (m > n)) {

					break;

				}

				m++;

			}

			for (int j = 0; j < 2 * n; j++) {

				A[k][j] = A[k][j] + A[m][j];

			}

		}
		for (int i = 0; i < n; i++) {

			for (int j = k + 1; j < n * 2; j++) {

				if (i != k) {

					A[i][j] = (A[i][j] * A[k][k] - A[k][j] * A[i][k]) / A[k][k];

				}

			}

		}

		for (int i = 0; i < n; i++) {

			if (i != k) {

				A[i][k] = 0;

			}

		}

		for (int j = 2 * n - 1; j >= k; j--) {

			A[k][j] = A[k][j] / A[k][k];

		}

	}

	// Удаляем добавленную единичную матрицу
	for (int i = 0; i < A.size(); i++) {

		for (int j = 0; j < n; j++) {

			A[i][j] = A[i][j + n];

		}

		A[i].resize(n);

	}

	return A;

}


// todo: Исправь ошибку
// Функция получения канонической формы Фробениуса матрицы A
vector<vector<double>> Frobenius(vector<vector<double>> A) {

	// Слабая (для галочки) обработка исключительной ситуации
	if (A.size() != A[0].size()) {

		throw invalid_argument("Invalid matrix size: number rows != lines");

	}

	vector<vector<double>> res, e;
	int n = A.size();

	//for (int i = 1; i < n - 1; i++) {
	for (int i = 2; i < n; i++) {

		e = E(n);

		/*for (int j = 1; j < n; j++) {*/
		for (int j = 0; j < n; j++) {
			
			//if (j == n - i) {
			if (j != n - i) {

				//e[(n - i) - 1][j - 1] = 1 / A[(n - (i - 1)) - 1][(n - i) - 1];
				e[n - i][j] = -A[n - (i - 1)][j] / A[n - (i - 1)][n - i];

			}
			else {

				//e[(n - i) - 1][j - 1] = -A[(n - 1) - i][j - 1] / A[(n - 1) - i][(n - i) - 1];
				e[n - i][j] = 1 / A[n - (i - 1)][n - i];

			}

		}

		//A = MMul(MMul(MInv(e), A), e);


		cout << "Recalculating matrix e" << i << endl;
		ShowVector(e);

		cout << "Matrix e (Inv)" << i << endl;
		ShowVector(MInv(e));

		//A = MMul(MMul(bx, A), e);
		cout << "New matrix A" << i << endl;
		ShowVector(MMul(MMul(MInv(e), A), e));
		//data.push_back(e);


	}

	return A;

}


///*-----нахожд. собстевенных векторов-----*/
//	double** tmp;
//	double s;
//	double lambda = 7.79216;
//
//	vector<double**> lambdavectors;			// вектор, содерж. матрицы типа double
//	double** lambdavec = mNull(5);			// матрица из нулей
//
//	for (int i = 0; i < 5; i++)			// заполнение маириицы
//	{
//		lambdavec[i][0] = pow(lambda, 4 - i);
//	}
//
//	lambdavectors.push_back(lambdavec);		// добавляем полученное значение в конец
//
//	cout << "lambdavec1" << endl;			// выводим всё это дело
//	show(lambdavec);
//	cout << endl;
//
//	for (int m = 2; m <= 5; m++)
//	{
//		tmp = data.back();
//		data.pop_back();
//		lambdavec = lambdavectors.back();
//
//		cout << "matr" << endl;
//		show(tmp);
//		cout << endl;
//
//		for (int i = 0; i < 5; i++)
//		{
//			s = 0;
//			for (int k = 0; k < 5; k++)
//			{
//				s = s + tmp[i][k] * lambdavec[k][0];
//			}
//
//			vec[i][0] = s;
//		}
//
//		lambdavectors.push_back(vec);
//		cout << "Lambda vec" << m << endl;
//		show(vec);
//		cout << endl;
//	}
//
//	cout << "Ответ:" << endl;
//	show(vec);


// todo: доделай 7-ую лабу