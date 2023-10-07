#include <iostream>
#include <stdlib.h>
using namespace std;

class Dreptunghi {
protected:
	double lungimea, latimea;
public:
	Dreptunghi() {
		lungimea = 0;
		latimea = 0;
	}
	virtual ~Dreptunghi() {
		cout << "Dreptunghiul a fost sters!" << endl;
	}
	virtual void citire() {
		cout << "Lungimea: "; cin >> lungimea;
		cout << "Latimea: "; cin >> latimea;
	}
	virtual double suprafata() {
		return lungimea * latimea;
	}
	virtual double volum() {
		return 0;
	}
	virtual void afisare() {
		cout << "Lungimea = " << lungimea << endl;
		cout << "Latimea = " << latimea << endl;
	}
	virtual int tip() {
		return 0;
	}
};

class Piramida : public Dreptunghi {
protected:
	double h, apotema;
public:
	Piramida() {
		h = 0;
		apotema = 0;
	}
	~Piramida() {
		cout << "Piramida a fost stearsa!" << endl;
	}
	void citire() {
		Dreptunghi::citire();
		cout << "Apotema: "; cin >> apotema;
		cout << "Inaltimea: "; cin >> h;
	}
	double aria_laterala() {
		return ((2 * (lungimea + latimea)) * apotema) / 2;
	}
	double suprafata() {
		return Dreptunghi::suprafata() + aria_laterala();
	}
	double volum() {
		return (Dreptunghi::suprafata() * h) / 3;
	}
	void afisare() {
		Dreptunghi::afisare();
		cout << "Apotema = " << apotema << endl;
		cout << "Inaltimea = " << h << endl;
		cout << "Suprafata = " << suprafata() << endl;
		cout << "Volumul = " << volum() << endl;
	}
	int tip() {
		return 1;
	}
};

class Prisma : public Piramida {
public:
	~Prisma() {
		cout << "Prisma a fost stearsa!";
	}
	void citire() {
		Dreptunghi::citire();
		cout << "Inaltimea: "; cin >> h;
	}
	double aria_laterala() {
		return (2 * (lungimea + latimea)) * h;
	}
	double suprafata() {
		return aria_laterala() + (2 * Dreptunghi::suprafata());
	}
	double volum() {
		return Dreptunghi::suprafata() * h;
	}
	void afisare() {
		Dreptunghi::afisare();
		cout << "Inaltimea = " << h << endl;
		cout << "Aria laterala = " << aria_laterala() << endl;
		cout << "Suprafata = " << suprafata() << endl;
		cout << "Volumul = " << volum() << endl;
	}
	int tip() {
		return 2;
	}
};

int main() {
	Dreptunghi* figura[100];
	int n, q;
	cout << "Numarul de figuri: "; cin >> n;
	for (int i = 0; i < n; i++) {
		q = rand() % 3;
		switch (q) {
			case 1: {
				figura[i] = new Piramida;
				break;
			}
			case 2: {
				figura[i] = new Prisma;
				break;
			}
			default: {
				figura[i] = new Dreptunghi;
				break;
			}
		}
		figura[i]->citire();
		cout << endl;
	}
	double amax = 0, vmax = 0;
	int arie = 0, volum = 0;
	cout << "\n\n------------- Afisarea figurilor:" << endl;
	for (int i = 0; i < n; i++) {
		figura[i]->afisare();
		cout << endl;
		if (amax < figura[i]->suprafata()) {
			amax = figura[i]->suprafata();
			arie = i;
		}
		if (vmax < figura[i]->volum()) {
			vmax = figura[i]->volum();
			volum = i;
		}
	}
	cout << "\n\n------------- Toate piramidele:" << endl;
	for (int i = 0; i < n; i++) {
		if (figura[i]->tip() == 1) {
			figura[i]->afisare();
			cout << endl;
		}
	}
	cout << "\n\n------------- Toate prismele:" << endl;
	for (int i = 0; i < n; i++) {
		if (figura[i]->tip() == 2){
			figura[i]->afisare();
			cout << endl;
		}
	}
	cout << "\n\n------------- Figura cu aria maxima:" << endl;
	figura[arie]->afisare();
	cout << endl;
	cout << "\n\n------------- Figura cu volumul maxima:" << endl;
	figura[volum]->afisare();
	cout << endl;
	double vtotal = 0, atotal = 0;
	for (int i = 0; i < n; i++)
		vtotal += figura[i]->volum();
	for (int i = 0; i < n; i++)
		atotal += figura[i]->suprafata();
	cout << "\n\n------------- Total:" << endl;
	cout << "Suprafata totala = " << atotal << endl;
	cout << "Volumul total = " << vtotal << endl;
	Dreptunghi* temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (figura[i]->suprafata() > figura[j]->suprafata()) {
				temp = figura[i];
				figura[i] = figura[j];
				figura[j] = temp;
			}
	cout << "\n\n------------- Sortarea descrescator a suprafetei:" << endl;
	for (int i = 0; i < n; i++){
		figura[i]->afisare();
		cout << endl;
	}
	system("pause");
	for (int i = 0; i < 100; i++)
		delete figura[i];
	return 0;
}