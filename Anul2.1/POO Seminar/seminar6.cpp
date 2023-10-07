#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Film {
public:
	string denumirea, actorul, regizorul;
	int anul, editia, ora, min;
	double bugetul;
	Film* next;
	Film() {
		denumirea = "";
		actorul = "";
		regizorul = "";
		anul = 0; editia = 0; ora = 0; min = 0;
		next = NULL;
	}
	friend istream& operator>>(istream& input, Film*& f) {
		cout << "Denumirea filmului: "; input >> f->denumirea;
		cout << "Anul: "; input >> f->anul;
		cout << "Editia: "; input >> f->editia;
		cout << "Regizorul: "; input >> f->regizorul;
		cout << "Actorul: "; input >> f->actorul;
		cout << "Bugetul: "; input >> f->bugetul;
		cout << "La ce ora va fi difuzat: "; input >> f->ora >> f->min;
		return input;
	}
	friend ostream& operator<<(ostream& output, Film*& f) {
		output << f->denumirea << setw(6) << "(" << f->anul << ")" << endl;
		output << "Editia: " << f->editia << endl;
		output << "Regizorul: " << f->regizorul << endl;
		output << "Actorul principal: " << f->actorul << endl;
		output << "Bugetul: " << f->bugetul << endl;
		output << "Ora: " << f->ora << ":" << f->min;
		return output;
	}
	friend class Lista;
	friend void schimba(Film* f1, Film* f2) {
		Film *f1n, *f2n, temp;
		f1n = f1->next;
		f2n = f2->next;
		temp = *f1;
		*f1 = *f2;
		*f2 = temp;
		f1->next = f1n;
		f2->next = f2n;
	}
};

class Lista {
	Film* prim;
	int nr;
	int counter;
public:
	Lista() {
		prim = NULL;
		nr = 0;
		counter = 0;
	}
	void creeaza() {
		Film* p;
		ifstream f("lista.txt"); f >> nr;
		for (int i = 0; i < nr; i++) {
			p = new Film;
			f >> p->denumirea >> p->anul >> p->editia >> p->regizorul >> p->actorul >> p->bugetul >> p->ora >> p->min;
			p->next = prim;
			prim = p;
			counter++;
		}
		f.close();
	}
	void afisare() {
		Film* p;
		p = prim;
		cout << "\n\nLista filmelor:\n\n";
		for (int i = 0; i < counter; i++) {
			cout << p;
			cout << endl << endl;
			p = p->next;
		}
	}
	void adauga() {
		Film* p = new Film;
		cin >> p;
		p->next = prim;
		prim = p;
		counter++;
	}
	void sterge() {
		Film* p, * q;
		string d;
		cout << "Denumirea filmului care va fi sters din lista: ";
		cin >> d;
		p = prim;
		if (p->denumirea == d) {
			prim = p->next;
			delete p;
			counter--;
		}
		else {
			for (int i = 0; i < counter; i++) {
				q = p->next;
				if (q != NULL) {
					if (q->denumirea == d) {
						p->next = q->next;
						delete q;
						counter--;
						break;
					}
					p = p->next;
				}
			}
		}
	}
	void cauta(string name) {
		Film* p;
		p = prim;
		while (p != NULL) {
			if ((p->denumirea).find(name) != string::npos) {
				cout << p;
				cout << endl << endl;
			}
			p = p->next;
		}
	}
	void cauta(double bug) {
		Film* p;
		p = prim;
		while (p != NULL) {
			if (p->bugetul == bug) {
				cout << p;
				cout << endl << endl;
			}
			p = p->next;
		}
	}
	void cauta(int an) {
		Film* p;
		p = prim;
		while (p != NULL) {
			if (p->anul == an) {
				cout << p;
				cout << endl << endl;
			}
			p = p->next;
		}
	}
	void sort_an() {
		Film* a, * b;
		a = prim;
		for (int i = 0; i < counter - 1; i++) {
			b = a->next;
			for (int j = i + 1; j < counter; j++){
				if ((a->anul) < (b->anul))
					schimba(a, b);
				b = b->next;
			}
			a = a->next;
		}
		cout << "Sortarea filmelor dupa an s-a efectuat cu succes!" << endl;
	}
	void sort_name() {
		Film* a, * b;
		string aa, bb;
		a = prim;
		for (int i = 0; i < counter - 1; i++) {
			b = a->next;
			for (int j = i + 1; j < counter; j++) {
				aa = a->denumirea;
				bb = b->denumirea;
				if ((aa.at(0)) > (bb.at(0)))
					schimba(a, b);
				b = b->next;
			}
			a = a->next;
		}
		cout << "Sortarea filmelor dupa denumire s-a efectuat cu succes!" << endl;
	}
	~Lista() {
		Film* a;
		do {
			a = prim;
			prim = prim->next;
			delete a;
		} while (prim != NULL);
	}
};

int main() {
	Lista t;
	int n,g;
	g = 0;
	while (g == 0) {
		system("cls");
		cout << "1. Creeaza." << endl;
		cout << "2. Afisare." << endl;
		cout << "3. Adauga." << endl;
		cout << "4. Sterge." << endl;
		cout << "5. Cauta." << endl;
		cout << "6. Sorteaza." << endl;
		cout << "7. Exit." << endl;
		cout << "Numarul:\t"; cin >> n;
		switch (n) {
		case 1: {
			t.creeaza();
			system("pause");
			break;
		}
		case 2: {
			t.afisare();
			system("pause");
			break;
		}
		case 3: {
			t.adauga();
			system("pause");
			break;
		}
		case 4: {
			t.sterge();
			system("pause");
			break;
		}
		case 5: {
			az:
			int nn;
			cout << "\n\n1. Cauta dupa denumirea filmului." << endl;
			cout << "2. Cauta dupa bugetul filmului." << endl;
			cout << "3. Cauta dupa anul filmului." << endl;
			cout << "Numarul:\t"; cin >> nn;
			switch (nn) {
			case 1: {
				string name;
				cout << "\n\nDenumirea: ";
				cin >> name;
				t.cauta(name);
				system("pause");
				break;
			}
			case 2: {
				double buget;
				cout << "\n\nBugetul: "; cin >> buget;
				t.cauta(buget);
				system("pause");
				break;
			}
			case 3: {
				int an;
				cout << "\n\nAnul: "; cin >> an;
				t.cauta(an);
				system("pause");
				break;
			}
			default: {
				cout << "\n\nNu exista asa optiune!" << endl;
				system("pause");
				goto az;
			}
			}
			break;
		}
		case 6: {
			at:
			int mm;
			cout << "\n\n1. Sortarea dupa an." << endl;
			cout << "2. Sortarea dupa denumire." << endl;
			cout << "Numarul:\t"; cin >> mm;
			switch (mm) {
			case 1: {
				t.sort_an();
				system("pause");
				break;
			}
			case 2: {
				t.sort_name();
				system("pause");
				break;
			}
			default: {
				cout << "\n\nNu exista asa optiune!" << endl;
				system("pause");
				goto at;
			}
			}
			break;
		}
		case 7: {
			g = 1;
			break;
		}
		default: {
			cout << "Nu exista asa optiune!" << endl;
			system("pause");
			break;
		}
		}
	}

	return 0;
}