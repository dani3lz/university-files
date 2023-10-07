#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Biblioteca {
	string reviste[20], carti[20];
	int nr_carti, nr_reviste, total;
public:
	Biblioteca();
	Biblioteca(string,string);
    Biblioteca(string);
	Biblioteca(Biblioteca*);
	~Biblioteca();
	void AdaugaCarte(string);
	void AdaugaRevista(string);
	void StergeCarte(string);
	void StergeRevista(string);
	void Afiseaza();
	int Total() {
		this->total = nr_reviste + nr_carti;
		return this->total;
	}
};

Biblioteca::Biblioteca() {
	nr_carti = nr_reviste = 0;
	for (int i=0; i < 10; i++) {
		reviste[i] = "";
		carti[i] = "";

	}
}

Biblioteca::Biblioteca(string name_carte, string name_revista) {
	nr_carti = nr_reviste = 0;
	reviste[nr_reviste++] = name_revista;
	carti[nr_carti++] = name_carte;
    for (int i=1; i < 10; i++) {
		reviste[i] = "";
		carti[i] = "";
	}
}
Biblioteca::Biblioteca(string name_carte){
    nr_carti = nr_reviste = 0;
    carti[nr_carti++] = name_carte;
    for (int i=0; i < 10; i++)
		reviste[i] = "";
    for (int i=1; i < 10; i++)
		carti[i] = "";
}

Biblioteca::Biblioteca(Biblioteca* raft) {
	for (int i = 0; i < (*raft).Total(); i++) {
		this->carti[i] = (*raft).carti[i];
		this->reviste[i] = (*raft).reviste[i];
	}
	this->nr_carti = (*raft).nr_carti;
	this->nr_reviste = (*raft).nr_reviste;
}

void Biblioteca::AdaugaCarte(string name) {
	if (Total() < 20) {
		carti[nr_carti++] = name;
		cout << "Cartea " << name << " a fost adaugata cu succes!" << endl;
	}
	else
		cout << "\nRaftul este plin!" << endl;
}

void Biblioteca::AdaugaRevista(string name) {
	if (Total() < 20) {
		reviste[nr_reviste++] = name;
		cout << "Revista " << name << " a fost adaugata cu succes!" << endl;
	}
	else
		cout << "\nRaftul este plin!" << endl;
}

void Biblioteca::StergeCarte(string name) {
	for (int i = 0; i < nr_carti; i++) {
		if (carti[i].find(name) != string::npos) {
			for (int j = i; j < nr_carti; j++)
				carti[j] = carti[j + 1];
			nr_carti--;
			cout << "\nCartea " << name <<" a fost stearsa cu succes!" << endl;
			break;
		}
		if (i == (nr_carti - 1))
			cout << "\nNu exista asa cartea pe raft!" << endl;
	}
}

void Biblioteca::StergeRevista(string name) {
	for (int i = 0; i < nr_reviste; i++) {
		if (reviste[i].find(name) != string::npos) {
			for (int j = i; j < nr_reviste; j++)
				reviste[j] = reviste[j + 1];
			nr_reviste--;
			cout << "\nRevista " << name << " a fost stearsa cu succes!" << endl;
			break;
		}
		if (i == (nr_reviste - 1))
			cout << "\nNu exista asa revista pe raft!" << endl;
	}
}

Biblioteca::~Biblioteca() {
	cout << "\nS-a sters raftul cu " << nr_carti << " carti si " << nr_reviste << " reviste!" << endl;
	cout << "In total s-au sters " << Total() << " carti/reviste." << endl;
	nr_carti = nr_reviste = 0;
}

void Biblioteca::Afiseaza() {
	if (nr_carti > 0) {
		cout << "\n-----------------Afisare------------------" << endl;
		cout << "\nCarti:" << endl;
		for (int i = 0; i < nr_carti; i++)
			cout << i+1 << ". " << carti[i] << endl;
	}
	else {
		cout << "\nPe raft nu este nici-o carte!" << endl;
	}

	if (nr_reviste > 0) {
		cout << "\nReviste:" << endl;
		for (int i = 0; i < nr_reviste; i++)
			cout << i+1 << ". " << reviste[i] << endl;
	}
	else {
		cout << "\nPe raft nu este nici-o revista!" << endl;
	}
	if (nr_carti > 0 || nr_reviste > 0) {
		cout << "\nIn total sunt " << Total() << " carti/reviste" << "(" << nr_carti << " carti, " << nr_reviste << " reviste)" << endl;
		cout << "--------------------------------------------" << endl;
	}

}

int main() {
	Biblioteca* raft1 = new Biblioteca;
	Biblioteca* raft2 = new Biblioteca("Codul lui DaVinci", "A mic");

	cout << "\n==============RAFT 1================" << endl;

	(*raft1).AdaugaCarte("Padurea Spanzuratilor");
	(*raft1).AdaugaRevista("Aquarelle");
	(*raft1).AdaugaCarte("Baltagul");
	(*raft1).Afiseaza();
	(*raft1).StergeCarte("Baltagul");
	(*raft1).AdaugaRevista("Alunelul");
	(*raft1).Afiseaza();
	(*raft1).~Biblioteca();
	(*raft1).Afiseaza();

	cout << "\n==============RAFT 2================" << endl;

	(*raft2).AdaugaCarte("Simbolul Pierdut");
	(*raft2).AdaugaCarte("Crima si Pedeapsa");
	(*raft2).AdaugaCarte("Maestrul si Margarita");
	(*raft2).Afiseaza();
	(*raft2).StergeRevista("A mic");
	(*raft2).Afiseaza();

	cout << "\n==============RAFT 3================" << endl;

	Biblioteca* raft3 = new Biblioteca(raft2);

	(*raft3).Afiseaza();
	(*raft3).AdaugaRevista("Forbes");
	(*raft3).StergeCarte("Codul lui DaVinci");
	(*raft3).Afiseaza();

	cout << "\n==============RAFT 2================" << endl;

	(*raft2).Afiseaza();

	system("pause");
	return 0;
}
