#pragma once
#include <vector>
#include <iostream>

using namespace std;


vector<double> Eyler(int k, double h, vector<double> x, vector<double> y, double (*F)(double x, double y)) {

	x.resize(k + 1);
	y.resize(k + 1);

	for (int i = 0; i < k; i++) {

		x[i + 1] = x[0] + k * h;

		y[i + 1] = y[i] + h * F(x[i], y[i]);

	}

	/*for (int i = 1; i < k; i++) {
		y[i] = y[i - 1] + h * f(x[i - 1], y[i - 1]);
	}*/

	return y;

}


vector<double> EylerMod(int k, double h, vector<double> x, vector<double> y, double (*F)(double x, double y)) {

	x.resize(k + 1);
	y.resize(k + 1);
	
	for (int i = 0; i < k; i++) {
		
		x[i + 1] = x[0] + k * h;

		y[i + 1] = y[i] + h * F(x[i] + h/2, y[i] + h/2 * F(x[i], y[i]));

	}

	/*for (int i = 1; i < k; i++) {
		y[i] = y[i - 1] + h * f(x[i - 1] + h / 2, y[i - 1] + h / 2 * f(x[i - 1], y[i - 1]));
	}*/

	return y;

}


vector<double> Runge_Cute(int k, double h, vector<double> x, vector<double> y, double (*F)(double x, double y)) {

	vector<double> z;
	z.resize(4);

	y.resize(k + 1);
	x.resize(k + 1);

	for (int i = 0; i < k; i++) {

		x[i + 1] = x[0] + k * h;

		z[0] = h * F(x[i], y[i]);
		z[1] = h * F(x[i] + h/2, y[i] + (z[0] / 2));
		z[2] = h * F(x[i] + h/2, y[i] + (z[1] / 2));
		z[3] = h * F(x[i] + h, y[i] + z[2]);

		y[i + 1] = y[i] + (z[0] + z[1] + z[2] + z[3]) / 6;

	}

	//double[][] z = new double[3][4];

	/*for (int i = 0; i < 3; i++) {
		z[i][0] = h * f(x[i], y[i]);
		z[i][1] = h * f(x[i] + h / 2, y[i] + z[i][0] / 2);
		z[i][2] = h * f(x[i] + h / 2, y[i] + z[i][1] / 2);
		z[i][3] = h * f(x[i] + h, y[i] + z[i][2]);

		y[i + 1] = y[i] + (z[i][0] + 2 * z[i][1] + 2 * z[i][2] + z[i][3]) / 6;
	}*/

	return y;

}


vector<double> Adams(int k, double h, vector<double> x, vector<double> y, double (*F)(double x, double y)) {

	double t;

	y.resize(k + 1);
	x.resize(k + 1);

	for (int i = 3; i < k; i++) {

		x[i + 1] = x[0] + k * h;

		t = 55 * F(x[i], y[i]) - 59 * F(x[i - 1], y[i - 1]) + 37 * F(x[i - 2], y[i - 2]) - 9 * F(x[i - 3], y[i - 3]);

		y[i + 1] = y[i] + (h/24) * t;

	}

	//double[] t = new double[k - 1];

	/*for (int i = 3; i < k - 1; i++) {
		t[i] = 55 * f(x[i], y[i]) - 59 * f(x[i - 1], y[i - 1]) + 37 * f(x[i - 2], y[i - 2]) - 9 * f(x[i - 3], y[i - 3]);
		y[i + 1] = y[i] + h / 24 * t[i];
	}*/

	return y;

}



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