#include <iostream>
using namespace std;

int** createMatrix(int n, int m) {
	int** A = NULL;
	A = new int*[n];

	for (int i = 0; i < n; i++) {
		*(A + i) = new int[m];

		for (int j = 0; j < m; j++) {
			*(*(A + i) + j) = -9 + rand() % 19;
		}
	}

	return A;
}


void printMatrix(int** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout.width(4);
			cout << *(*(A + i) + j) << " ";
		}
		cout << endl;
	}
}


void deleteMatrix(int** A, int n) {
	for (int i = 0; i < n; i++) {
		delete[] * (A + i);
	}

	delete[] A;
	A = NULL;
}


int substRows(int** A, int n, int m, int w1, int w2) {
	if (w1 < 1 || w1 > n || w2 < 1 || w2 > n) {
		return 0;
	}
	else {
		if (w1 != w2) {
			int* tmp = NULL;

			tmp = *(A + w1 - 1);
			*(A + w1 - 1) = *(A + w2 - 1);
			*(A + w2 - 1) = tmp;

			tmp = NULL;
		}

		return 1;
	}
}