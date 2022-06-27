#include <iostream>
#include <vector>
#include <iomanip>
#include "Methods.h"

using namespace std;


double Fun(double x, double y) {

    return (6 * x * x - 2) * cos(y);

}


int main()
{

    vector<double> y = {1}, x = {1};
    double h = 0.1, E = 0.001;
    double (*F)(double x, double y) = &Fun;
    int k = 10;

    
    cout << "\n" << setw(60) << "Eyler:\n";
    ShowVector(Eyler(k, h, x, y, F));
    
    cout << "\n\n" << setw(60) << "Eyler Mod:\n";
    ShowVector(EylerMod(k, h, x, y, F));

    cout << "\n\n" << setw(60) << "Runge_Cute:\n";
    ShowVector(Runge_Cute(k, h, x, y, F));

    cout << "\n\n" << setw(60) << "Adams:\n";
    ShowVector(Adams(k, h, x, Runge_Cute(3, h, x, y, F), F));


    system("pause");
    return 0;

}