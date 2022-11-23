#include <iostream>
#include <vector>
#include "Methods.h"


//  Найти собственные значения и собственные векторы 
//  линейного преобразования, задаваемого некоторой матрицей.



using namespace std;

int main()
{
    vector<vector<double>> A = {
        { -1, 4, -2, 3, 1 },
        { 5, 3, -4, 0, 2 },
        { -3, -4, 2, -1, 3 },
        { 2, -4, 4, -3, 2 },
        { 5, -2, -2, 0, 1 }
    };

    vector<vector<double>> t1 = {
        { 3, -1, 2 },
        { 4, 2, 7 },
        { -5, 6, 9 }
    };

    vector<vector<double>> t2 = {
        { 2, 1, 1, 2, 1 },
        { 1, 2, 1, 2, 2 },
        { 2, 2, 2, 1, 1 },
        { 2, 1, 2, 2, 1 },
        { 1, 2, 2, 1, 2 }
    };
    
    
    
    ShowVector(Frobenius(t2));

    system("pause");
    return 0;
}