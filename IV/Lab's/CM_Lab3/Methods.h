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

	for (int m = 1; m < x.size(); m++) {

		for (int k = 0; k < x.size() - m; k++) {

			y[m].resize(x.size() - m);

			if (m == 1) {

				y[m][k] = f[k + 1] - f[k];

			}
			else {

				y[m][k] = y[m - 1][k + 1] - y[m - 1][k];

			}

		}

	}

	return y;

}


// Вычисление значения полинома Лагранжа в точке х
// double L_n(double x, vector<vector<double>> y)
double L_n(double x, vector<double> y, vector<double> f) {

	double up, down, res = 0;

	for (int k = 0; k < y.size(); k++) {

		up = 1;

		for (int i = 0; i < y.size(); i++) {

			if (i != k) {

				up *= x - y[i];

			}

		}

		down = 1;
		
		for (int j = 0; j < y.size(); j++) {

			if (j != k) {

				down *= y[k] - y[j];

			}

		}

		res += f[k] * up / down;

	}

	return res;

}



// Вычисление значения полинома Лагранжа NF в точке х
double NF(double x, vector<double> y, vector<double> f, vector<vector<double>> Dif) {

	double prod = 1, res = f[0];

	for (int k = 1; k < y.size(); k++) {

		prod *= x - y[k - 1];

		// todo: Ошибка в том, что размерность Dif слишком маленькая для цикла k
		if (k < y.size() - 1) {

			res += Dif[1][k] * prod;

		}

	}

	return res;

}


// Вычисление значения полинома Лагранжа NB в точке х
double NB(double x, vector<double> y, vector<double> f, vector<vector<double>> Dif) {

	double prod = 1, res = f[y.size() - 1];

	for (int k = 1; k < y.size(); k++) {

		prod *= x - y[y.size() - k + 1 - 1];

		// todo: Ошибка в том, что размерность Dif слишком маленькая для цикла k
		if (k < y.size() - 1) {

			res += Dif[y.size() - k - 1][k] * prod;

		}

	}

	return res;

}