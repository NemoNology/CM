#include <iostream>
#include <iomanip>
#include <vector>
#include "Methods.h"

using namespace std;

int main()
{
    // Given:
    vector<double> x = { -1.5, -0.8, 0.2, 0.8, 1.6, 3.2 };
    vector<double> y = { 7.59375, -2.77248, 4.13952, 19.51488, 29.35296, 2.79552 };

    double x0 = -0.6;

    ShowVector(CalcFinDiffFun(x, y));

    cout << "Langrange:\t" << L_n(x0, x, y) << "\n";
    
    // Ошибка: Смотреть todo в функциях ниже
    cout << "NewtonNF:\t" << NF(x0, x, y, CalcFinDiffFun(x, y)) << "\n";
    cout << "NewtonNB:\t" << NB(x0, x, y, CalcFinDiffFun(x, y)) << "\n";

    system("pause");
    return 0;
}