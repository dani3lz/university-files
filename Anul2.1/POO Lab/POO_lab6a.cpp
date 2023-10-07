#include <iostream>
#include <string>
using namespace std;

class Presa {
protected:
	string denumirea;
	int n, campuri;
	string text[100];
public:
	Presa() {
		denumirea = "";
		campuri = 3;
		n = 0;
	}
	Presa(string denumirea, int campuri) {
		this->denumirea = denumirea;
		this->campuri = campuri;
		n = 0;
	}
	virtual ~Presa() {
		cout << "Presa s-a sters!" << endl;
	}
	void citeste() {
		for (int i = 0; i < campuri; i++) {
			cout << i + 1 << ". "; 
			cin >> text[n++];
		}
	}
	void afisare_text() {
		cout << "Text:\n";
		for (int i = 0; i < campuri; i++)
			cout << text[i] << endl;
	}
	virtual void afisare() {
		cout << "Denumirea: " << denumirea << endl;
		afisare_text();
	}
};

class Ziar : virtual public Presa {
protected:
	string tiraj, perioada;
public:
	Ziar() :Presa() {
		tiraj = "";
		perioada = "";
	}
	Ziar(string denumirea, string perioada, string tiraj, int campuri) :Presa(denumirea, campuri) {
		this->tiraj = tiraj;
		this->perioada = perioada;
	}
	virtual ~Ziar() {
		cout << "Ziarul s-a sters!" << endl;
	}
	virtual void afisare() {
		cout << "Denumirea: " << denumirea << endl;
		cout << "Tiraj: " << tiraj << endl;
		cout << "Perioada: " << perioada << endl;
		afisare_text();
	}
};

class Revista : virtual public Ziar {
protected:
	string index;
public:
	Revista() :Ziar() {
		index = "";
	}
	Revista(string denumirea, string perioada, string tiraj, int campuri, string index) :Ziar(denumirea, perioada, tiraj, campuri),Presa(denumirea, campuri) {
		this->index = index;
	}
	~Revista() {
		cout << "Revista s-a sters!" << endl;
	}
	void afisare() {
		cout << "Denumirea: " << denumirea << endl;
		cout << "Tiraj: " << tiraj << endl;
		cout << "Perioada: " << perioada << endl;
		cout << "Index: " << index << endl;
		afisare_text();
	}
};

class Ziar_electronic : virtual public Ziar {
public:
	Ziar_electronic() : Ziar() {
	}
	Ziar_electronic(string denumirea, string perioada, string tiraj, int campuri) :Ziar(denumirea, perioada, tiraj, campuri),Presa(denumirea, campuri) {
	}
	~Ziar_electronic() {
		cout << "Ziarul electronic s-a sters!" << endl;
	}
	void afisare() {
		Ziar::afisare();
	}
};

int main() {
	Presa* presa[3];
	presa[0] = new Ziar("Adevarul", "Odata pe luna", "2020", 2);
	presa[1] = new Revista("Maxim", "Odate la 3 luni", "2019", 1, "RU18976541KK");
	presa[2] = new Ziar_electronic("Point", "Odata la 2 ore", "2015", 3);
	for (int i = 0; i < 3; i++) {
		presa[i]->citeste();
		cout << endl << endl;
	}
	for (int i = 0; i < 3; i++) {
		presa[i]->afisare();
		cout << "\n\n";
	}
	for (int i = 0; i < 3; i++) {
		delete presa[i];
		cout << endl;
	}
	system("pause");
	return 0;
}