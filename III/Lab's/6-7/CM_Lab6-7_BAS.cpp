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

			cout << setw(14) << setprecision(8) << a[i][j];

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



void Add_Adjacent_matrix(vector<vector<double>>& a) {

	
	a.resize(a.size() * 2);

	for (unsigned short i = 0; i < a.size(); i++) {

		//a[i] = new vector<double> av(a[i].size);

	}



}





int main()
{


	
	//###################################################################################################


	vector<vector<double>> A = {
						
		{	19, 4, -1, 4, 6		},								//		19		4		-1		4		6		=		32	
																//
		{	2, 18, 0, 3, -5		},								//		2		18		0		3		-5		=		36
																//
		{	-7, -8, 31, 5, 1	},								//		-7		-8		31		5		1		=		66
																//
		{	4, 4, 3, 29, -7		},								//		4		4		3		29		-7		=		66
																//
		{	9, 8, 0, -4, 28		}								//		9		8		0		-4		28		=		41
	
	};

	
	vector<double> C = { 

		32, 36, 66, 66, 41 

	};


	//###################################################################################################


	vector<double> X(A.size());

	vector<double> XX(A.size());



	cout << "Matrix in begin:\n";
	Show_Matrix(A);
	cout << "\t\t\t\t===";
	Show_Matrix(C);


	int k = 0;


	for (int i = 0; i < X.size(); i++) {

		X[i] = 0;

	}



	float e = 0.000001;


	unsigned short int how_many = 0;
	

	while (how_many < A.size()) {

		k++;

		for (int i = 0; i < A.size(); i++) {

			XX[i] = C[i];

			for (int j = 0; j < A.size(); j++) {

				if (j != i) {

					XX[i] = XX[i] - A[i][j] * X[j];

				}

			}

			XX[i] = XX[i] / A[i][i];

		}

		for (int i = 0; i < A.size(); i++) {

			if ((fabs(X[i] - XX[i]) < e) || (fabs(X[i] - XX[i]) == 0)) {

				how_many++;

			}

			X[i] = XX[i];

		}


	}



	cout << "Final Matrix:\n";
	Show_Matrix(A);

	cout << "Vector X:\n";
	Show_Matrix(X);








	//###################################################################################################



	system("pause");
	return 0;

}