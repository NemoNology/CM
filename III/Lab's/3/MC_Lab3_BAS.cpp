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
            cout << setw(12) << setprecision(8) << p[i][j] << "|";
        }
        cout << endl;
    }
    cout << "\n\n";
}


// 1-ый шаг метода Жаргана-Гаусса - проверка на a[k][k] == 0
void step1(double** p, unsigned k) {

    double* temp[n];

    for (unsigned j = k; j < n; j++) {
        if (p[k][k] == 0) {
            for (unsigned i = k + 1; i < n; i++) {
                if (p[i][k] != 0) {

                    temp[i] = p[k];
                    p[k] = p[i];
                    p[i] = temp[i];
                    break;

                }
            }
            break;
        }
        break;
    }
}


// 2-ой шаг метода Жаргана-Гаусса - вычисление a[i][j], при i != k & j > k & "Обнуление" элементов под a[k][k] 
void step2(double** p, unsigned k) {

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = k + 1; j < m; j++) {
            if (i != k) {

                p[i][j] = (p[i][j] * p[k][k] - p[i][k] * p[k][j]) / p[k][k];

            }
        }
    }

}


// 3-ий шаг метода Жаргана-Гаусса - "Обнуление" элементов в столбце k
void step3(double** p, unsigned k) {

    for (unsigned i = 0; i < n; i++) {
        if (i != k) {

            p[i][k] = 0;

        }
    }

}

// 4-ый шаг метода Жаргана-Гаусса - Вычисление a[k][j]
void step4(double** p, unsigned k) {

    for (unsigned j = m - 1; j + 1 > k; j--) {

        p[k][j] /= p[k][k];

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
        step3(aop, k);
        step4(aop, k);

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

    double mat[n][m] = {
    {0.42, -0.72, 0.02, -0.28, 0.2, 0.66},
    {-0.67, 0.17, -0.86, 0.88, -0.88, 0.53},
    {0.14, -0.11, 0.86, -0.61, 0.61, 0.32},
    {0.83, -0.97, -0.29, -0.66, 0.7, -0.88},
    {0.91, -0.04, -0.41, -0.24, 0.09, 0.66} };

    // ##############################################################

    double* aop[n];
    for (int i = 0; i < n; i++) {
        aop[i] = mat[i];
    }


    // Вызов метода
    Method(aop, n, m);


    system("pause"); // Окончание программы
    return 0;
}