#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <corecrt_math_defines.h>
#include "Methods.h"

using namespace std;

double F(double x) {

	return sin(3 * x);

}


int main()
{

	double e = 0.001, x0 = M_PI / 4, M1 = 27, M2 = 243, h = 0.01;
	double (*pF)(double x) = F;

	double D1 = (M1 / 6) * h * h;
	double D2 = (M2 / 30) * pow(h, 4);
	
	
	//cout << setprecision(4) << setw(14) << NumDif1(x0, h, pF) << "\n";
	//cout << setprecision(4) << setw(14) << NumDif2(x0, h, pF) << "\n";




	vector<double> x = { 6.8, 7.2, 7.6, 8, 8.4, 8.8, 9.2 };
	vector<double> y = { -0.44194, -0.60356, -0.75676, -0.90237, -1.04108, -1.17352, -1.20021 };
	h = 0.4;
	double D;
	vector<vector<double>> z = CalcFinDiffFun(x, y);
	
	//ShowVector(z);

	//CalcProiz(x, y, h, z);

}