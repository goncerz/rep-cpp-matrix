#include <iostream>
#include <ctime>
#include "header.h"
using namespace std;

int main(void) {
	int n = 0;
	int m = 0;
	int** A = NULL;
	int w1 = 0;
	int w2 = 0;
	time_t t;

	srand(time(&t));

	do {
		cout << "Podaj liczbe wierszy macierzy A: ";
		cin >> n;
	} while (n < 1);

	do {
		cout << "Podaj liczbe kolumn macierzy A: ";
		cin >> m;
	} while (m < 1);
	cout << endl;

	A = createMatrix(n, m);
	cout << "Macierz A:" << endl;
	printMatrix(A, n, m);
	cout << endl;

	cout << "Program moze zamienic miejscami 2 wiersze macierzy A." << endl;
	cout << "Podaj numer wiersza w1: ";
	cin >> w1;
	cout << "Podaj numer wiersza w2: ";
	cin >> w2;
	cout << endl;

	if (substRows(A, n, m, w1, w2)) {
		cout << "Macierz A po zamianie wiersza w1=" << w1 << " z wierszem w2=" << w2 << ":" << endl;
		printMatrix(A, n, m);
	}
	else {
		cout << "W macierzy A zamiana wierszy w1=" << w1 << " i w2=" << w2 << " jest niemozliwa." << endl;
	}
	cout << endl;

	deleteMatrix(A, n);

	return 0;
}