#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int muchii, it, nodTotal;

bool* reset(void) {
	bool* selectat = new bool[1000];
	for (int i = 0; i < 1000; i++)
		selectat[i] = false;
	return selectat;
}

void afisare_MST(int** Array) {
	cout << "________________________________" << endl;
	cout << setw(4) << "Nr." << setw(8) << "i" << setw(8) << "j" << setw(12) << "Ponderea" << endl;
	cout << "________________________________" << endl;
	for (int i = 0; i < nodTotal; i++) {
		cout << setw(3) << i + 1 << ".";
		for (int j = 0; j < 3; j++) {
			if (j < 2)
				cout << setw(8) << Array[i][j];
			else
				cout << setw(12) << Array[i][j];
		}
		cout << endl;
	}
	cout << "________________________________" << endl;
}

void afisare_Array(int** ar, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}

void sort_Kruskal(int** A, int n, int k, int**& MST , bool*& selectat) {
	int g = 0;
	bool check = false;
	if (k < n) {
		int min = 9999;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (A[j][2] < min && selectat[j] == false) {
					min = A[j][2];
					g = j;
					check = true;
				}
			}
		}
		if (check) {
			MST[k][0] = A[g][0];
			MST[k][1] = A[g][1];
			MST[k][2] = min;
			selectat[g] = true;
			++k;
			sort_Kruskal(A, n, k, MST, selectat);
		}
	}
}

int** Creeaza_Array(int n, double tip) {
	muchii = 0;
	int** Array = new int* [1000];
	for (int i = 0; i < 1000; i++)
		Array[i] = new int[1000];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Array[i][j] = 9999;
		}
	}
	for (int i = 0; i < n; i++) {
		Array[i][i] = 0;
		for (int j = i + 1; j < n; j++) {
			if (((float)rand() / RAND_MAX) <= tip && i != j) {
				Array[i][j] = (rand() % 100) + 1;
				Array[j][i] = Array[i][j];
				muchii++;
			}
		}
	}
	return Array;
}

int** Prim_Kruskal(int** Array, int n, int nr) {
	nodTotal = 0;
	it = 0;
	int nod1, nod2, min;
	int** MST = new int* [1000];
	for (int i = 0; i < 1000; i++)
		MST[i] = new int[3];
	bool* selectat = new bool[1000];
	for (int i = 0; i < n; i++)
		selectat[i] = false;
	selectat[nr] = true;
	while (nodTotal < n - 1) {
		nod1 = 0;
		nod2 = 0;
		min = 9999;
		for (int i = 0; i < n; i++) {
			if (selectat[i] == true) {
				for (int j = 0; j < n; j++) {
					++it;
					if (i != j && selectat[j] == false && Array[i][j] < min) {
						min = Array[i][j];
						nod1 = i;
						nod2 = j;
					}
				}
			}
		}
		selectat[nod2] = true;
		MST[nodTotal][0] = nod1;
		MST[nodTotal][1] = nod2;
		MST[nodTotal][2] = min;
		++nodTotal;
	}
	delete[] selectat;
	return MST;
}


int main(void) {
	int n = 0, g = 1, t, nr = 0;
	int** MST = new int* [1000], ** Array = new int* [1000];
	int** Kruskal = new int*[1000];
	for (int i = 0; i < 1000; i++)
		Kruskal[i] = new int[3];
	bool* selectat = new bool[1000];
az:
	cout << "Nr. de noduri:\n";
	cout << "1. 10." << endl;
	cout << "2. 100." << endl;
	cout << "3. 1000." << endl;
	cout << "Optiunea: ";
	cin >> t;
	if (t == 1)
		n = 10;
	if (t == 2)
		n = 100;
	if (t == 3)
		n = 1000;
	if (t != 1 && t != 2 && t != 3) {
		cout << "Nu exista asa optiune!" << endl;
		system("pause");
		goto az;
	}
	cout << "\nDati muchia initiala: ";
	cin >> nr;
	while (g == 1) {
		system("cls");
		cout << "1. Cazul favorabil." << endl;
		cout << "2. Cazul mediu." << endl;
		cout << "3. Cazul nefavorabil." << endl;
		cout << "4. Schimba nr. de noduri." << endl;
		cout << "5. Exit." << endl;
		cout << "Optiunea: "; cin >> t;
		switch (t) {
		case 1: {
			Array = Creeaza_Array(n, 0.35);
			MST = Prim_Kruskal(Array, n, nr);
			selectat = reset();
			sort_Kruskal(MST, n, 0, Kruskal, selectat);
			break;
		}
		case 2: {
			Array = Creeaza_Array(n, 0.55);
			MST = Prim_Kruskal(Array, n, nr);
			selectat = reset();
			sort_Kruskal(MST, n, 0, Kruskal, selectat);
			break;
		}
		case 3: {
			Array = Creeaza_Array(n, 0.95);
			MST = Prim_Kruskal(Array, n, nr);
			selectat = reset();
			sort_Kruskal(MST, n, 0, Kruskal, selectat);
			break;
		}
		case 4: {
			cout << endl;
			goto az;
		}
		case 5: {
			for (int i = 0; i < 1000; i++) {
				delete[] MST[i];
				delete[] Array[i];
				delete[] Kruskal[i];
			}
			delete[] MST;
			delete[] Array;
			delete[] Kruskal;
			delete[] selectat;
			return 0;
		}
		default: {
			cout << "\nNu exista asa optiune!" << endl;
			system("pause");
			break;
		}
		}
		/*cout << endl;
		afisare_Array(Array,n);*/
		cout << endl;
		cout << "Metoda <<Prim>>:" << endl;
		afisare_MST(MST);
		cout << endl;
		cout << "Metoda <<Kruskal>>:" << endl;
		afisare_MST(Kruskal);
		cout << "\n\nNr. de noduri: " << n << endl;
		cout << "Nr. de muchii: " << muchii << endl;
		cout << "Iteratii: " << it << endl << endl;
		system("pause");
	}
}