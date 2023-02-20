#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;


// Функция для вывода 2D матрицы
void Show_2D_Arr(const vector<vector<double>>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {
        cout << "\t";
        for (unsigned short j = 0; j < a[i].size(); j++) {
            cout << setw(8) << setprecision(7) << a[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
}

// Функция для вывода 1D матрицы
void Show_1D_Arr(const vector<double>& a) {
    cout << "\n";
    for (unsigned short i = 0; i < a.size(); i++) {
        cout << setprecision(8) << "\t" << a[i] << "\n";
    }
    cout << "\n";
}


// Генерируем изначальную матрицу для 4-ой лаб.
void Generate_Random_2D_Arr(vector<vector<double>>& a) {
    srand(time(NULL));
    for (unsigned short i = 0; i < a.size(); i++) {
        a[i][a.size()] = (rand() % 200 - 100.0) / 100; // создание f элементов
        a[i][i] = (rand() % 200 - 100.0) / 100; // c - диагональ
        if (i + 1.0 < a.size()) {
            a[i + 1][i] = (rand() % 200 - 100.0) / 100; // a
            a[i][i + 1] = (rand() % 200 - 100.0) / 100; // b
        }
    }
}

// ###################################################################################################################################

// 1-ый шаг метода прогонки решения трёхдиагональных СЛАУ (МПР) - Вычисление коэффицентов
vector <double> CM_Method_Lab4(const vector<vector<double>>& a) {
    // Инициальзация вектора для сохранения значения коэф-ов
    vector <double> alpha(a.size()); // Коэф-ци альфа
    vector <double>  beta(a.size()); // Коэф-ци бета
    // Вычисление коэф-ов альфа & бета:
    alpha[1] = -a[0][1] / a[0][0];
     beta[1] =  a[0][a.size()] / a[0][0];
    for (unsigned short i = 1; i <= a.size() - 2; i++) {
        alpha[i + 1] = -a[i][i + 1] / (a[i][i] + alpha[i] * a[i][i-1]);
         beta[i + 1] = (a[i][a.size()] - a[i][i-1] * beta[i]) / (a[i][i] + alpha[i] * a[i][i-1]);
    }

    // Инициальзация вектора для сохранения значения x - результатов метода\решения
    vector <double> x(a.size());
    // Обратный ход алгоритма
    // Вычисление x[n]
    // Разделяю числитель и знаменатель формулы x[n] для своего удобства
    x[a.size() - 1] = a[a.size() - 1][a.size()] - a[a.size() - 1][a.size() - 2] * beta[a.size() - 1];
    x[a.size() - 1] = x[a.size() - 1] / (a[a.size() - 1][a.size() - 1] + a[a.size() - 1][a.size() - 2] * alpha[a.size() - 1]);
    // Вычисление x[i] (i < n)
    for (short i = a.size() - 2; i >= 0; i--) {
       x[i] = alpha[i + 1] * x[i + 1] + beta[i + 1];
    };
    return x; // Возвращаем 1D матрицу х - матрицу результатов решения
}

// ###################################################################################################################################

int main()
{
    setlocale(LC_ALL, "Russian");

    // Мой массив
    // ##############################################################

    vector<vector<double>> mat = {
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0} };


    // ##############################################################


    // Вызов метода
    cout << "Изначальная матрица:";
    Generate_Random_2D_Arr(mat);
    Show_2D_Arr(mat);
    cout << "Итоговая матрица ответов:\n";
    Show_1D_Arr(CM_Method_Lab4(mat));
    system("pause"); // Окончание программы
    return 0;
}
