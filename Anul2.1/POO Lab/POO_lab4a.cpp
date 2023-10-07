#include <iostream>
#include <string>
using namespace std;

class Tipul{
protected:
    string type;
    string format;
public:
    Tipul(){
        this->format = "A4";
        this->type = "Foaie";
    }
    ~Tipul(){
        this->format = "";
        this->type = "";
    }
};

class Culoarea{
protected:
    string color;
    string gama;
public:
    Culoarea(){
        this->color = "alb";
        this->gama = "deschis";
    }
    ~Culoarea(){
        this->color = "";
        this->gama = "";
    }
};

class Specificatii : public Culoarea, public Tipul{
public:
    Specificatii(){

    }
    Specificatii(string format, string type, string color, string gama){
        Tipul::format = format;
        Tipul::type = type;
        Culoarea::color = color;
        Culoarea::gama = gama;
    }
    ~Specificatii(){
       Tipul::format = "";
        Tipul::type = "";
        Culoarea::color = "";
        Culoarea::gama = ""; 
    }
    void show(){
        cout << "Formatul: " << format << endl;
        cout << "Tipul: " << type << endl;
        cout << "Culoarea: " << color << endl;
        cout << "Gamma: " << gama << endl;
    }
    void set(){
        cout << "Formatul: "; cin >> Tipul::format;
        cout << "Tipul: "; cin >> Tipul::type;
        cout << "Culoarea: "; cin >> Culoarea::color;
        cout << "Gamma: "; cin >> Culoarea::gama;
    }
};

int main(){
Specificatii Hartie;
Specificatii Carton("A4","Carton","Albastru","Inchis");
Hartie.show();
cout << endl;
Carton.show();
cout << endl;
Hartie.set();
cout << endl;
Hartie.show();

    system("pause");
    return 0;
}