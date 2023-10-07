#include <iostream>
#include <string>
using namespace std;

class Informatie {
protected:
	string denumirea;
	double memoria;
};

class Procesor: public Informatie {
	double frecventa, tehnologia;
public:
	Procesor() {
		denumirea = "";
		tehnologia = 0;
		frecventa = 0;
		memoria = 0;
	}
	~Procesor() {
		cout << "Procesorul s-a distrus!" << endl;
	}
	void citeste() {
		cout << "Denumirea procesorului: "; cin >> denumirea;
		cout << "Frecventa (GHz): "; cin >> frecventa;
		cout << "Tehnologia de fabricatie (nm): "; cin >> tehnologia;
		cout << "Memoria procesorului (MB): "; cin >> memoria;
	}
	void afisare() {
		cout << "Denumirea procesorului: " << denumirea << endl;
		cout << "Frecventa: " << frecventa << " GHz" << endl;
		cout << "Tehnologia de fabricatie: " << tehnologia << " nm" << endl;
		cout << "Memoria procesorului: " << memoria << " MB" << endl;
	}
};

class RAM : public Informatie {
public:
	RAM() {
		denumirea = "";
		memoria = 0;
	}
	~RAM() {
		cout << "RAM-ul s-a distrus!" << endl;
	}
	void citeste() {
		cout << "Denumirea RAM-ului: "; cin >> denumirea;
		cout << "Memoria RAM-ului (GB): "; cin >> memoria;
	}
	void afisare() {
		cout << "Denumirea RAM-ului: " << denumirea << endl;
		cout << "Memoria RAM-ului: " << memoria << " GB" << endl;
	}
};

class Placa_video : public Informatie {
public:
	Placa_video() {
		denumirea = "";
		memoria = 0;
	}
	~Placa_video() {
		cout << "Placa video s-a distrus!" << endl;
	}
	void citeste() {
		cout << "Denumirea placii video: "; cin >> denumirea;
		cout << "Memoria placii video (GB): "; cin >> memoria;
	}
	void afisare() {
		cout << "Denumirea placii video: " << denumirea << endl;
		cout << "Memoria placii video: " << memoria << " GB" << endl;
	}
};

class Cooler {
	string denumirea;
	double viteza;
public:
	Cooler() {
		denumirea = "";
		viteza = 0;
	}
	~Cooler() {
		cout << "Cooler-ul s-a distrus!" << endl;
	}
	void citeste() {
		cout << "Denumirea cooler-ului: "; cin >> denumirea;
		cout << "Viteza cooler-ului pe minut: "; cin >> viteza;
	}
	void afisare() {
		cout << "Denumirea cooler-ului: " << denumirea << endl;
		cout << "Viteza cooler-ului: " << viteza << " rotatii pe minut" << endl;
	}
};

class Mother {
	string denumirea;
public:
	Mother() {
		denumirea = "";
	}
	~Mother() {
		cout << "Motherboard-ul s-a distrus!" << endl;
	}
	void citeste() {
		cout << "Denumirea Motherboard-ului: "; cin >> denumirea;
	}
	void afisare() {
		cout << "Denumirea Motherboard-ului: " << denumirea << endl;
	}
};

class Computer {
	Mother m;
	Procesor p;
	RAM r;
	Placa_video pv;
	Cooler c;
public:
	Computer() {
		cout << "Computerul se creeaza:" << endl;
	}
	~Computer() {
		cout << "Computerul a fost distrus!" << endl;
	}
	void citeste() {
		m.citeste();
		cout << endl;
		p.citeste();
		cout << endl;
		r.citeste();
		cout << endl;
		pv.citeste();
		cout << endl;
		c.citeste();
		cout << endl;
	}
	void afisare() {
		cout << "Specificatiile calculatorului:\n";
		m.afisare();
		cout << endl;
		p.afisare();
		cout << endl;
		r.afisare();
		cout << endl;
		pv.afisare();
		cout << endl;
		c.afisare();
		cout << endl;
	}
};

int main() {
	Computer* PC = new Computer;
	PC->citeste();
	cout << "PC a fost asamblat cu succes!" << endl << endl;
	PC->afisare();
	system("pause");
	delete PC;
	return 0;
}