#include <iostream>
#include <vector>
#include <iomanip>
#include "CM_Lab5_BAS.h"


using namespace std;


// todo: Delete
unsigned int pause;


// Функции для вывода:



// Функция для вывода 2D матрицы;
void Show_2D_Matrix(const vector<vector<double>>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {
        cout << "\t";
        for (unsigned short j = 0; j < a[i].size(); j++) {

            cout << setw(14) << setprecision(8) << a[i][j];

        }
        cout << endl;
    }
    cout << "\n\n";
}


// Функция для вывода 1D матрицы
void Show_1D_Matrix(const vector<double>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {

        cout << setprecision(8) << "\t" << setw(10) << a[i] << "\n";

    }
    cout << "\n\n";
}



//##################################################################################################################

// Различные методы:


// Функция суммрования элементов массива - нахождения b[i][k]
float Lab5_Sigma1(const vector<vector<double>> b, const vector<vector<double>> t, const unsigned short k, const unsigned short i) {

    float res = 0.0; // Result;

    
    for (unsigned short m = 0; m < k; m++) {

        res += b[i][m] * t[m][k];

    }


    return res;

}


// Функция суммрования элементов массива - нахождения t[k][j]
float Lab5_Sigma2(const vector<vector<double>> b, const vector<vector<double>> t, const unsigned short k, const unsigned short j) {

    float res = 0; // Result;


    for (unsigned short m = 0; m < k; m++) {

        res += b[k][m] * t[m][j];

    }


    return res;

}


// Функция суммирования элементов массива - нахождение y[i]
float Lab5_Sigma3(const vector<vector<double>> b, const vector<double> y, const unsigned short i) {

    float res = 0; // Result

    for (unsigned short m = 0; m < i; m++) {

        res += b[i][m] * y[m];

    }

    return res;

}


// Функция суммирования элементов массива - нахождение x[i]
float Lab5_Sigma4(const vector<vector<double>> t, const vector<double> x, const unsigned short i, const unsigned short n) {

    float res = 0; // Result

    for (unsigned short m = i + 1; m < n; m++) {

        res += t[i][m] * x[m];

    }

    return res;

}

// Функция для разделения изначальной матрицы на матрицу а и вектор с
// todo: доделай
vector<double> Arr_Cut(vector<vector<double>>& a) {

    vector<double> c(a.size());


    for (unsigned short i = 0; i < a.size(); i++) {

        c[i] = a[i][a.size()];

        a[i].resize(a.size());

    }

    return c;

}




// Функция для обнуления 2D матрицы
void Zeroing_2D_Matrix(vector<vector<double>>& a) {

    for (unsigned short i = 0; i < a.size(); i++) {
        for (unsigned short j = 0; j < a[i].size(); j++) {

            a[i][j] = 0;

        }
    }

}


// Функция для проверки 0 в a[i][i]
short int Zero_Check_aii(const vector<vector<double>>& a) {

    for (unsigned short i = 0; i < a.size(); i++) {

        if (a[i][i] == 0) {

            return i;

        }
    }

    return -1;
}


// Функция для проверки 0 в a[0][0]
bool Zero_Check_a00(const vector<vector<double>>& a) {

    if (a[0][0] == 0) {

        return 1;

    }

    return 0;
}


// todo: think
// Функция для перестановки строк, при условии, что a[i][i] (На которое мы делим) = 0 
void Swith_Lines_aii(vector<vector<double>>& a, const short int sign) {



}


// Функция для перестановки строк, при условии, что a[0][0] (На которое мы делим) = 0 
void Swith_Lines_a00(vector<vector<double>>& a, bool sign) {


    if (sign == 1) {

        for (unsigned short i = 0; i < a.size(); i++) {

            if (a[i][0] != 0) {

                vector<double> temp(a[0].size());

                temp = a[0];
                a[0] = a[i];
                a[i] = temp;

            }
        }
    }

}

//################################################################################################################## 



//################################################################################################################## 

// Метод Халецкого;

//
void Method(const vector<vector<double>>& a, const vector<double> c) {






    // Создание 1Д\2Д матриц для записи B & T; Y матриц, а также для записи результатов (х)
    vector<double> x(a.size());
    vector<double> y(a.size());
    vector<vector<double>> b = a;
    vector<vector<double>> t = a;



    // Обнуляем матрицы B & T;
    Zeroing_2D_Matrix(b); 
    Zeroing_2D_Matrix(t);
    

    // Вычисляем элементы матриц B & T

    // Вычисление b[i][0] & t[0]["j"]
    for (unsigned short i = 0; i < b.size(); i++) {

        b[i][0] = a[i][0];

        if (i >= 1) {

            t[0][i] = a[0][i] / b[0][0];

        }

        t[i][i] = 1;

    }


    // Вычисление [i][k] & t[k][j]
    for (unsigned short k = 1; k < a.size(); k++) {

        if (k == 4) {

            pause = 0.2;

        }

        for (unsigned short i = k; i < a.size(); i++) {

            for (unsigned short j = k + 1; j < a.size(); j++) {

                b[i][k] = a[i][k] - Lab5_Sigma1(b, t, k, i);

                t[k][j] = (1 / b[k][k]) * (a[k][j] - Lab5_Sigma2(b, t, k, j));

            }   
        }

    }


    cout << "\nB Matrix:";
    Show_2D_Matrix(b);
    cout << "T Matrix:";
    Show_2D_Matrix(t);



    // Вычисляем BY = C:

    // Вычисление Y i-нное

    y[0] = c[0] / b[0][0];

    for (unsigned short i = 1; i < a.size(); i++) {

        y[i] = (1 / b[i][i]) * (c[i] - Lab5_Sigma3(b, y, i));

    }



    // Вычисляем TX = Y:

    // Вычисление X i-нное

    x[a.size() - 1] = y[a.size() - 1];

    for (short i = a.size() - 2; i >= 0; i--) {

        x[i] = y[i] - Lab5_Sigma4(t, x, i, a.size());

    }



    
    cout << "\nC vector:";
    Show_1D_Matrix(c);
    cout << "\nY vector:";
    Show_1D_Matrix(y);
    cout << "\nX vector:";
    Show_1D_Matrix(x);

    

}

//################################################################################################################## 



int main()
{
    
    



    // Мой массив
    // ##############################################################

    vector<vector<double>> mat = {
    {0.42, -0.72, 0.02, -0.28, 0.2, 0.66},
    {-0.67, 0.17, -0.86, 0.88, -0.88, 0.53},
    {0.14, -0.11, 0.86, -0.61, 0.61, 0.32},
    {0.83, -0.97, -0.29, -0.66, 0.7, -0.88},
    {0.91, -0.04, -0.41, -0.24, 0.09, 0.66} };  
    
    // ##############################################################

    vector<double> c;


    // Вызов метода
    cout << "\nInitial matrix:";


    c = Arr_Cut(mat);                           // Обрезаем последний столбец изначальной матрицы для дальнейшего удобства работы с вектором С


    Show_2D_Matrix(mat);

    // Проверка на a[0][0] = 0
    Swith_Lines_a00(mat, Zero_Check_a00(mat)); 

                     
    // Вывод результатов решения
    cout << "\nFinal response matrix";   
    Method(mat, c);
    

    system("pause"); // Окончание программы
    return 0;
}