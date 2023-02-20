#pragma once


// Функция для вывода 2D матрицы;
void Show_Matrix(const vector<vector<double>>& a);


// Функция для вывода 1D матрицы
void Show_Matrix(const vector<double>& a);


// Функция изменения размерности матрицы: new_LSize - новое кол-во строк
void Resize_Matrix(vector<vector<double>>& a, const unsigned new_LSize);


// Функция изменения размерности матрицы: new_LSize - новое кол-во строк, new_RSize - новое кол-во столбцов
void Resize_Matrix(vector<vector<double>>& a, const unsigned new_LSize, const unsigned new_RSize);


// Функция изменения размерности матрицы: new_Size - новое кол-во массива
void Resize_Matrix(vector<double>& a, const unsigned new_Size);


// Функция генерации случайных значений массива
void Random_Array(vector<vector<double>>& a);