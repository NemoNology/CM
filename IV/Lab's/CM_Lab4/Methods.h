#pragma once
#include <vector>
#include <iomanip>
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



// 1-ая формула
double NumDif1(double x, double h, double (*F)(double x)) {

	return (F(x + h) - F(x - h)) / (2 * h);

}


// 2-ая формула
double NumDif2(double x, double h, double (*F)(double x)) {

	return (F(x - 2 * h) - 8 * F(x - h) + 8 * F(x + h) - F(x + 2 * h)) / (12 * h);

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



double CalcD(double h, double y, double m) {
	
	return (1 / h) * ((y) / (m + 1));

}


void CalcProiz(vector<double> x, vector<double> y, double h, vector<vector<double>> Dif) {

	cout << "\n";
	double sum;

	for (int i = 1; i < x.size() - 1; i++) {

		sum = 0;

		for (int j = 0; j < i; j++) {

			sum += pow(-1, j) * (Dif[1][j] / (j + 1));

		}

		cout << "m: " << i <<  "\t" << "y'(x0):" 
			<< setprecision(4) << setw(8) << (1 / h) * sum 
			<< "\t" << "D: " << setprecision(4) << setw(8)
			<< CalcD(h, Dif[1][i], i) << "\n";

	}

	cout << "\n";

}