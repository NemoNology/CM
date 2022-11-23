#pragma once
#include <vector>
#include <iostream>

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



// Вычисление конечных разностей функции y = f(x)
vector<vector<double>> CalcFinDiffFun(vector<double> x, vector<double> f) {

	vector<vector<double>> y;
	y.resize(x.size());

	int n = x.size();

	for (int m = 1; m < n; m++) {

		for (int k = 0; k < n - m; k++) {

			y[m].resize(n - m);

			if (m == 1) {

				//y[k][m] = (f[k + 1] - f[k]) / (x[k + 1] - x[k]);
				//y[m][k] = f[k + 1] - f[k];
				y[m][k] = (f[k + 1] - f[k]) / (x[k + 1] - x[k]);

			}
			else {

				//y[k][m] = (y[k + 1][m - 1] - y[k][m - 1]) / (x[k + m] - x[k]);
				//y[m][k] = y[m - 1][k + 1] - y[m - 1][k];
				y[m][k] = (y[m - 1][k + 1] - y[m - 1][k]) / (x[k + m] - x[k]);

			}

		}

	}

	return y;

}


// Вычисление значения полинома Лагранжа в точке х
// double L_n(double x, vector<vector<double>> y)
double L_n(double x, vector<double> y, vector<double> f) {

	double up = 1, down = 1, res = 0;
	int n = y.size();

	for (int k = 0; k < n; k++) {

		up = 1;

		for (int i = 0; i < n; i++) {

			if (i != k) {

				up *= x - y[i];

			}

		}

		down = 1;
		
		for (int j = 0; j < n; j++) {

			if (j != k) {

				down *= y[k] - y[j];

			}

		}

		res += f[k] * up / down;

	}

	return res;

}



// Вычисление значения полинома Ньютона NF в точке х
double NF(double x, vector<double> y, vector<double> f, vector<vector<double>> Dif) {

	double prod = 1, res = f[0];
	int n = y.size();

	for (int k = 1; k < n; k++) {

		prod *= x - y[k - 1];

		// todo: Ошибка в том, что размерность Dif слишком маленькая для цикла k
		//if (k < y.size() - 1) {

			res += Dif[k][0] * prod;

		//}

	}

	return res;

}


// Вычисление значения полинома Ньютона NB в точке х
double NB(double x, vector<double> y, vector<double> f, vector<vector<double>> Dif) {

	double prod = 1, res = f[y.size() - 1];
	int n = y.size();

	for (int k = 1; k < n; k++) {

		prod *= x - y[n - k + 1 - 1];

		// todo: Ошибка в том, что размерность Dif слишком маленькая для цикла k
		if (k < n - 1) {

			res += Dif[k][n - k - 1] * prod;

		}

	}

	return res;

}