#include <iostream>
#include <string>
using namespace std;

class Animale {
public:
	string numele;
};

class Leu {
public:
	Animale a;
	Leu(string nume) {
		a.numele = nume;
	}
	Leu() {
		a.numele = "";
	}
	~Leu() {
		cout << "Leul o murit" << endl;
	}
	string get() {
		return a.numele;
	}
};

class Tigru {
public:
	Animale a;
	Tigru(string nume) {
		a.numele = nume;
	}
	Tigru() {
		a.numele = "";
	}
	~Tigru() {
		cout << "Tigrul o murit" << endl;
	}
	string get() {
		return a.numele;
	}
};



class Continent {
protected:
	string numele;
	string animale[10];
	int count;
public:
	Continent() {
		this->numele = "";
		for (int i = 0; i < 10; i++)
			animale[i] = "";
		count = 0;
	}
	~Continent() {
		cout << "Continentul o disparut" << endl;
	}

	void adauga(Leu* l) {
		animale[count++] = l->get();
	}
	void adauga(Tigru* t) {
		animale[count++] = t->get();
	}
	void afisare() {
		cout << "\n------------ Animalele:" << endl;
		for (int i = 0; i < count; i++)
			cout << animale[i] << endl;
	}
};

class Africa : public Continent {
public:
	Africa() {
		cout << "S-a creat continentul Africa" << endl;
	}
	~Africa() {
		cout << "Continentul Africa s-a distrus" << endl;
	}
};


int main() {
	Leu* leu = new Leu("Lion");
	Tigru* tigru = new Tigru("Tiger");
	Continent* continent;
	continent = new Africa();
	continent->adauga(leu);
	continent->adauga(tigru);

	continent->afisare();

	cout << endl << endl;

	delete continent;
	delete tigru;
	delete leu;

	
	return 0;
}