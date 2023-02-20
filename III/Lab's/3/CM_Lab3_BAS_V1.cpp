#include <iostream>
#include <iomanip>

using namespace std;


// Константы размрности массива
const unsigned n = 5, m = 6;


// Функция для вывода матрицы
void Show_matr(double** p) {
    cout << "\n\n";
    for (unsigned i = 0; i < n; i++) {
        cout << "\t" << "|";
        for (unsigned j = 0; j < m; j++) {
            cout << setw(12) << p[i][j] << "|";
        }
        cout << endl;
    }
    cout << "\n\n";
}


// 1-ый шаг метода Жаргана-Гаусса 
void step1(double** p, unsigned k) {

    double* fh[n];

    for (unsigned i = k; i < n; i++) {
        for (unsigned j = i + 1; j < m; j++) {
            if (p[i][i] == 0) {


            }
        }
    }
}

// 2-ой шаг метода Жаргана-Гаусса
void step2(double** p, unsigned k) {

    float z; // Пока тест...

    for (unsigned i = 0; i < n - 1; i++) {
        for (unsigned j = 0; j < m; j++) {
            if ((p[i][i] != 1) & (i != k) & (j > k)) {
                z = (p[i][j] * p[k][k] - p[i][k] * p[k][j]) / (p[k][k]);
                p[i][j] = z;
            }
        }
    }
}

// 3-ий шаг метода Жаргана-Гаусса
void step3(double** p, unsigned k) {
    for (unsigned i = k + 1; i < n; i++) {
        p[i][k] *= 0;
    }
}

// 4-ый шаг метода Жаргана-Гаусса
void step4(double** p, unsigned k) {
    for (unsigned j = 0; j < k; j++) {
        p[k][m - j] /= p[k][k];
    }
}


// Метод Жордана-Гаусса в виде модуля, состоящего из множества функций (Шагов)
void Method(double** aop, unsigned n, unsigned m) {

    // Вывод изначальной матрицы
    cout << "Изначальная матрица:";
    Show_matr(aop);

    // Сообственно сам метод:
    for (unsigned k = 0; k < n; k++) {
        step1(aop, k);
        step2(aop, k);
        //step3(aop, k);
        //step4(aop, k);
    }

    
    // Вывод итоговой матрицы
    cout << "Итоговая матрица:";
    Show_matr(aop);
}


int main()
{
    setlocale(LC_ALL, "Russian");

// Мой массив
// ##############################################################
    const unsigned n = 5, m = 6;
    const unsigned * pn = &n, * pm = &m;

    double my_mat[n][m] = { {0.42, -0.72, 0.02, -0.28, 0.2, 0.66},
    {-0.67, 0.17, -0.86, 0.88, -0.88, 0.53},
    {0.14, -0.11, 0.86, -0.61, 0.61, 0.32},
    {0.83, -0.97, -0.29, -0.66, 0.7, -0.88},
    {0.91, -0.04, -0.41, -0.24, 0.09, 0.66} };

// Тестовый массив
// ##############################################################

    double tmat[n][m] = { {0.42, -0.72, 0.02, -0.28, 0.2, 0.66},
    {-0.67, 0.17, -0.86, 0.88, -0.88, 0.53},
    {0.14, -0.11, 0.86, -0.61, 0.61, 0.32},
    {0.83, -0.97, -0.29, -0.66, 0.7, -0.88},
    {0.91, -0.04, -0.41, -0.24, 0.09, 0.66} };

// ##############################################################

    // Не забудь поменять потом на свой массив
    double* aop[n];
    for (int i = 0; i < n; i++) {
        aop[i] = tmat[i];
    }


    // Тест 
    Method(aop, n, m);


    system("pause"); // Окончание программы
    return 0;
}