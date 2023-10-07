#include <iostream>
#include <string>
using namespace std;

class Tipul{
protected:
    string type;
public:
    Tipul(){
        this->type = "A4";
    }
    ~Tipul(){
        this->type = "";
    }
};

class Culoarea{
protected:
    string color;
public:
    Culoarea(){
        this->color = "alb";
    }
    ~Culoarea(){
        this->color = "";
    }
};

class Hartie : public Tipul, public Culoarea{
private:
    string compania;
    int nr;
public:
    Hartie(){
        this->compania = "Papermax";
        this->nr = 100;
    }
    Hartie(string compania, int nr,string type,string color){
        this->compania = compania;
        this->nr = nr;
        Tipul::type = type;
        Culoarea::color = color;
    }
    ~Hartie(){
        cout << "Foile s-au ars! :'(" << endl;
    }
    void set(){
        cout << "\nCompania: "; cin >> compania;
        cout << "Numarul: "; cin >> nr;
        cout << "Culoarea: "; cin >> Culoarea::color;
        cout << "Tipul: "; cin >> Tipul::type;
    }
    void afisare(){
        cout << "Compania: " << compania << endl;
        cout << "Numarul de foi: " << nr << endl;
        cout << "Tipul: " << type << endl;
        cout << "Culoarea: " << color << endl;
    }
};

int main(){
    Hartie b;
    Hartie a("Velmart", 50, "A3", "gri");
    b.afisare();
    cout << endl;
    a.afisare();
    cout << endl;
    b.set();
    cout << endl;
    b.afisare();
    system("pause");
    return 0;
}