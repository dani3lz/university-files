#include <iostream>
#include <math.h>
#include <iomanip>
#include <string.h>
#define max 15
using namespace std;

double* Gauss(int n, double A[][4], double B[4], int& it){
	int iteratii = 0;
    double s;
	double a[max + 1][max + 1][max + 1], b[max + 1][max + 1], x[max + 1]; 
	int i, j, k;
    for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			a[i][j][1] = A[i-1][j-1];
	for (i = 1; i <= n; i++)
		b[i][1] = B[i-1];
	for (k = 1; k <= n - 1; k++){
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++){
				iteratii++;
				if (i <= k)
					a[i][j][k + 1] = a[i][j][k];
				else 
					if (j <= k)
						a[i][j][k + 1] = 0;
					else 
						a[i][j][k + 1] = a[i][j][k] - a[i][k][k] * a[k][j][k] / a[k][k][k];
			}
		for (i = 1; i <= n; i++)
			if (i <= k)
				b[i][k + 1] = b[i][k];
			else 
			b[i][k + 1] = b[i][k] - a[i][k][k] * b[k][k] / a[k][k][k];
	}
	x[n] = b[n][n] / a[n][n][n];
	for (i = n - 1; i >= 1; i--){
		iteratii++;
		s = 0;
		for (j = i + 1; j <= n; j++)
			s = s + a[i][j][i] * x[j];
		x[i] = (b[i][i] - s) / a[i][i][i];
	}
	double *sol = 0;
	sol = new double[n];
	for(int i=0;i<n;i++)
		sol[i]=x[i+1];
	it+= iteratii;
	return sol;
}

  
double** Cholesky(double matrix[][4],int n, int& it){ 
	int iteratii = 0;
    double lower[4][4]; 
    memset(lower, 0, sizeof(lower)); 
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j <= i; j++){ 
            int sum = 0; 
            if (j == i){ 
                for (int k = 0; k < j; k++){
					iteratii++; 
                    sum += pow(lower[j][k], 2);
				} 
                lower[j][j] = sqrt(matrix[j][j] - sum); 
            } 
			else { 
                for (int k = 0; k < j; k++){ 
                    sum += (lower[i][k] * lower[j][k]);
					iteratii++;
				} 
                lower[i][j] = (matrix[i][j] - sum) / lower[j][j]; 
            } 
        } 
    }
	double **LL = 0;
	LL = new double*[4];
	for(int i=0;i<4;i++)
		LL[i] = new double[4];
	for(int i = 0; i < 4; i++)
    	for(int j = 0; j < 4; j++) 
        LL[i][j] = lower[i][j]; 
	for(int i = 0; i < 4; i++) 
    	for(int j = 0; j < 4; j++) 
        LL[j][i] = lower[j][i]; 
	it+= iteratii;
	return LL;
} 

double* Jacobi(double A[][4], double b[4], int& it){
	int iteratii = 0;
	double *x1 = new double[4];
	double *x0 = new double[4];
	for(int i = 0; i < 4; i++)
		x0[i] = 0;
	double ez[4];
	double e = pow(10,-3);
	do{
		iteratii++;
		x1[0] = (b[0]-A[0][1]*x0[1]-A[0][2]*x0[2]-A[0][3]*x0[3])/A[0][0];
		x1[1] = (b[1]-A[1][0]*x0[0]-A[1][2]*x0[2]-A[1][3]*x0[3])/A[1][1];
		x1[2] = (b[2]-A[2][0]*x0[0]-A[2][1]*x0[1]-A[2][3]*x0[3])/A[2][2];
		x1[3] = (b[3]-A[3][0]*x0[0]-A[3][1]*x0[1]-A[3][2]*x0[2])/A[3][3];

		for(int i = 0; i < 4; i++)
			ez[i] = fabs(x0[i]-x1[i]);

		for(int i = 0; i < 4; i++)
			x0[i] = x1[i];

	}while(ez[0]>e && ez[1]>e && ez[2]>e && ez[3]>e);
	it+= iteratii;
	delete [] x0;
	return x1;
}

double* Gauss_Seidel(int n,double a[][4], double b[4], double e, int& it){
	int iteratii = 0;
	int m,i,j;
	double *x = new double[4]; 
	for(i=0;i<n;i++)
		x[i]=0;
	double ez[4],y[4];
    do{
        for (i = 0; i < n; i++){
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++){
				iteratii++;
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
				ez[i] = fabs(x[i]-y[i]);
                x[i] = y[i];
            }
        }
    }while (ez[0]>e && ez[1]>e && ez[2]>e && ez[3]>e);
	it+= iteratii;
	return x;
}

int main(){
double A[4][4] ={{14.4,-0.9,1.2,0.4},
				 {-0.9,20.6,0.8,0.9},
				 {1.2,0.8,19.6,1.3},
				 {0.4,0.4,1.3,17.6}};
double b[4] = {11.2,-20.1,13.9,10.7};
int iteratii1, iteratii2, iteratii3, iteratii4, iteratii5;
iteratii1 = iteratii2 = iteratii3 = iteratii4 = iteratii5 = 0;

double *sol1 = Gauss(4,A,b,iteratii1);
cout << "Solutia aproximativa prin Metoda eliminarii lui Gauss este:" << endl;
for (int i = 0; i < 4; i++)
	cout << setw(8) << sol1[i] << "\t";
cout << "\nIteratii = " << iteratii1 << endl;
cout << endl;
system("pause");

double **Lz;
Lz = new double*[4];
for(int i=0;i<4;i++)
	Lz[i] = new double[4];
double LT[4][4], L[4][4];
Lz = Cholesky(A,4,iteratii2);
for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) 
        L[i][j] = Lz[i][j]; 
for(int i = 0; i < 4; i++) 
    for(int j = 0; j < 4; j++) 
        LT[j][i] = Lz[j][i];
 cout << "\nL:" << endl; 
 int n = 4;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            cout << setw(8) << L[i][j] << "\t"; 
			cout << endl;
	}
        cout << endl;
		cout << "L^T:" << endl; 
		for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            cout << setw(8) << LT[j][i] << "\t"; 
        cout << endl; 
    }
double *y = Gauss(4,LT,b,iteratii2);
// ----------------------------------------------------------------
double x[4];
x[0] = y[0] / L[0][0];
x[1] = (y[1] - (L[1][0]*x[0]))/L[1][1];
x[2] = (y[2] - (L[2][0]*x[0]) - (L[2][1]*x[1]))/L[2][2];
x[3] = (y[3] - (L[3][0]*x[0]) - (L[3][1]*x[1]) - (L[3][2]*x[2]))/L[3][3];
// -----------------------------------------------------------------
cout << "\nSolutia aproximativa prin Metoda lui Cholesky este:" << endl;
for (int i = 0; i < n; i++)
	cout << setw(8) << x[i] << "\t";
cout << "\nIteratii = " << iteratii2 << endl;
cout << endl;
system("pause");

double *sol2 = Jacobi(A,b,iteratii3);
cout << "\nSolutia aproximativa prin Metoda iterativa a lui Jacobi este:" << endl;
for (int i = 0; i < n; i++)
	cout << setw(8) << sol2[i] << "\t";
cout << "\nIteratii = " << iteratii3 << endl;
cout << endl;
system("pause");

double e3 = pow(10,-3) ,e5 = pow(10,-5);
cout << "\nSolutia aproximativa prin Metoda iterativa a lui Gauss-Seidel cu o eroare 10^-3 este:" << endl;
double *sol3 = Gauss_Seidel(4,A,b,e3,iteratii4);
for (int i = 0; i < n; i++)
	cout << setw(15) << sol3[i] << "\t";
cout << "\nIteratii = " << iteratii4 << endl;
cout << endl;
cout << "\nSolutia aproximativa prin Metoda iterativa a lui Gauss-Seidel cu o eroare 10^-5 este:" << endl;
double *sol4 = Gauss_Seidel(4,A,b,e5,iteratii5);
for (int i = 0; i < n; i++)
	cout << setw(15) << sol4[i] << "\t";
cout << "\nIteratii = " << iteratii5 << endl;
cout << endl;
system("pause");

for(int i = 0; i < 4; i++)
    delete [] Lz[i];
delete [] sol1;
delete [] sol2;
delete [] sol3;
delete [] sol4;
delete [] Lz;
delete [] y;

    return 0;
}