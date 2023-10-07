#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int muchii, n = 0, it1, it2;

int** Creeaza_Array(int n, double tip) {
	muchii = 0;
	int** Array = new int* [250];
	for (int i = 0; i < 250; i++)
		Array[i] = new int[250];
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

void afisare_dikstra(int dist[], int par[]) {
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		if (dist[i] != 0) {
			int temp = par[i];
			cout << i << " <- ";
			while (temp != -1)
			{
				cout << temp << " <- ";
				temp = par[temp];
			}
			cout << endl;
			cout << "Ponderea = " << dist[i];
			cout << endl << endl;
		}
	}
}

void afisare_floyd(int** dist) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] != 9999)
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}

void floydWarshall(int** graph) {
	it1 = 0;
	int i, j, k;
	int** dist = new int* [250];
	for (int i = 0; i < 250; i++)
		dist[i] = new int[250];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					it1++;
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	afisare_floyd(dist);
}

int getMin(int dist[], bool visited[]) {
	int index = 0;
	int min = 9999;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && dist[i] < min) {
			it2++;
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int** cost, int start) {
	it2 = 0;
	int par[250], dist[250];
	bool visited[250] = { 0 };
	fill(dist, dist + n, 9999);
	dist[start] = 0;
	par[start] = -1;
	for (int i = 0; i < n - 1; i++) {
		int u = getMin(dist, visited);
		visited[u] = true;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && (dist[u] + cost[u][j]) < dist[j] && cost[u][j] != 9999) {
				it2++;
				par[j] = u;
				dist[j] = dist[u] + cost[u][j];
			}
		}
	}
	afisare_dikstra(dist, par);
}

int main() {
	clock_t start1, start2, end1, end2;
	int nr, t, src;
az:
	cout << "Nr. de noduri:\n";
	cout << "1. 10." << endl;
	cout << "2. 100." << endl;
	cout << "3. 250." << endl;
	cout << "Optiunea: ";
	cin >> t;
	if (t == 1)
		n = 10;
	if (t == 2)
		n = 100;
	if (t == 3)
		n = 250;
	if (t != 1 && t != 2 && t != 3) {
		cout << "Nu exista asa optiune!" << endl;
		system("pause");
		goto az;
	}
	while (true) {
		system("cls");
		cout << "1. Cazul favorabil." << endl;
		cout << "2. Cazul mediu." << endl;
		cout << "3. Cazul nefavorabil." << endl;
		cout << "4. Schimba nr. de noduri." << endl;
		cout << "5. Exit." << endl;
		cout << "Optiunea: "; cin >> t;
		switch (t) {
		case 1: {
			int** Array = Creeaza_Array(n, 0.35);
			start1 = clock();
			floydWarshall(Array);
			end1 = clock();
			cout << endl << endl;
			cout << "Dati src: "; cin >> src;
			start2 = clock();
			dijkstra(Array, src);
			end2 = clock();
			break;
		}
		case 2: {
			int** Array = Creeaza_Array(n, 0.55);
			start1 = clock();
			floydWarshall(Array);
			end1 = clock();
			cout << endl << endl;
			cout << "Dati src: "; cin >> src;
			start2 = clock();
			dijkstra(Array, src);
			end2 = clock();
			break;
		}
		case 3: {
			int** Array = Creeaza_Array(n, 0.95);
			start1 = clock();
			floydWarshall(Array);
			end1 = clock();
			cout << endl << endl;
			cout << "Dati src: "; cin >> src;
			start2 = clock();
			dijkstra(Array, src);
			end2 = clock();
			break;
		}
		case 4: {
			cout << endl;
			goto az;
		}
		case 5: {
			return 0;
		}
		default: {
			cout << "\nNu exista asa optiune!" << endl;
			system("pause");
			break;
		}
		}
		cout << endl << endl;
		cout << "Nr. de muchii: " << muchii << endl;
		cout << "Iteratii pentru Algoritmul Floyd-Warshall: " << it1 << endl;
		printf("Timpul pentru Algoritmul Floyd-Warshall: %.8f secunde\n", ((double)(end1 - start1)) / CLOCKS_PER_SEC);
		cout << "Iteratii pentru Algoritmul Dijkstra: " << it2 << endl;
		printf("Timpul pentru Algoritmul Dijkstra: %.8f secunde\n", ((double)(end2 - start2)) / CLOCKS_PER_SEC);
		cout << endl;
		system("pause");
	}
	return 0;
}
