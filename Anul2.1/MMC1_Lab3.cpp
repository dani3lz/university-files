#include<conio.h>
#include<iostream>
using namespace std;

double lagrange(int N, double X[], double Y[], float x1) {
	double L = 0, b;

	for (int i = 0; i < N; i++) {
		b = 1;
		for (int j = 0; j < N; j++)
			if (j != i)
				b *= (x1 - X[j]) / (X[i] - X[j]);
		L += Y[i] * b;
	}
	return L;
}

int main() {
	double a[] = { 4.675, 5.987, 7.453, 8.769, 9.801, 11.762, 13.097 };
	double b[] = { -2.4567, 8.8776, -4.0765, 0.00543, -3.6579, 13.097, -7.0108 };
	double x = 5.143;
	cout << "-> Valoarea functiei f(5.143) este: " << lagrange(7, a, b, x) << endl;
	int y = 5;
	cout << "-> Valoarea functiei f(5) este: " << lagrange(7, a, b, y) << endl;

	return 0;
}