#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;





// Функция для вывода 2D матрицы;
void Show_Matrix(const vector<vector<double>>& a) {

	cout << "\n\n";

	for (unsigned short i = 0; i < a.size(); i++) {

		cout << "\t";

		for (unsigned short j = 0; j < a[i].size(); j++) {

			cout << setw(8) << setprecision(4) << a[i][j];

		}

		cout << endl;
	}

	cout << "\n\n";
}




// Функция для вывода 1D матрицы
void Show_Matrix(const vector<double>& a) {
	cout << "\n\n";
	for (unsigned short i = 0; i < a.size(); i++) {

		cout << setprecision(8) << "\t" << setw(10) << a[i] << "\n";

	}
	cout << "\n\n";
}



int main()
{



	//###################################################################################################

				//		8 4 3 9
				//		6 5 2 5
				//		7 5 3 5
				//		8 9 3 3


	vector<vector<double>> A = {

		{	8, 4, 3, 9, 1, 0, 0, 0	},		

		{	6, 5, 2, 5, 0, 1, 0, 0	},

		{	7, 5, 3, 5, 0, 0, 1, 0	},

		{	8, 9, 3, 3, 0, 0, 0, 1	}

	};


	//###################################################################################################


	std::cout << "Matrix in begin:";
	Show_Matrix(A);

	int n = 4;


	int e = 0.00001;

	int m;


	for (int k = 0; k < n; k++) {


		if (fabs(A[k][k]) < e) {

			m = k + 1;

			while (fabs(A[k][k]) < e) {

				if ((fabs(A[m][k]) > e) || (m > n)) {

					break;

				}

				m++;

			}

			for (int j = 0; j < 2 * n; j++) {

				A[k][j] = A[k][j] + A[m][j];

			}


		}
			for (int i = 0; i < n; i++) {

				for (int j = k + 1; j < n * 2; j++) {

					if (i != k) {

						A[i][j] = (A[i][j] * A[k][k] - A[k][j] * A[i][k]) / A[k][k];

					}

				}

			}


			for (int i = 0; i < n; i++) {

				if (i != k) {

					A[i][k] = 0;

				}

			}

			for (int j = 2 * n - 1; j >= k; j--) {

				A[k][j] = A[k][j] / A[k][k];

			}


		}


	cout << "Final Matrix:";
	Show_Matrix(A);


	system("pause");
	return 0;

}