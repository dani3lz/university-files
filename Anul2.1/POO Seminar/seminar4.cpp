#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class persoana{
protected:
    string name;
    int anul_nasterii;
public:
    persoana(string name, int anul){
        this->name = name;
        anul_nasterii = anul;
    }
    persoana(){
        name = "";
        anul_nasterii = 0;
    }
    int get_anul_nasterii(){
        return anul_nasterii;
    }
};

class Salariat : public persoana{
protected:
    int ore_lucrate, plata, anul_angajarii;
public:
    Salariat(string name,int anul_nasterii,int anul_angajarii):persoana(name,anul_nasterii){
        this->anul_angajarii = anul_angajarii;
    }
    Salariat(){
        anul_angajarii = 0;
        ore_lucrate = 0;
        plata = 0;
    }
    ~Salariat(){
        cout << "Salariatul " << name << " a fost concediat." << endl;
    }
    void citire(){
        cout << "Numele: "; cin >> name;
        cout << "Anul nasterii: "; cin >> anul_nasterii;
        cout << "Anul angajarii: "; cin >> anul_angajarii;
        cout << "Ore lucrate: "; cin >> ore_lucrate;
        cout << "Plata pentru o ora: "; cin >> plata;
    }
    int salariu(){
        return ore_lucrate*plata;
    }
    void afisare(){
        cout << "Numele: " << name << endl;
        cout << "Anul nasterii: " << anul_nasterii << endl;
        cout << "Anul angajarii: " << anul_angajarii << endl;
        cout << "Salariu: " << salariu() << endl;
    }
};

int main(){
    int n,t;
    cout << "Dati numarul de angajati: "; cin >> n;
    Salariat *angajat = new Salariat[n];
    for(int i = 0; i < n; i++){
        angajat[i].citire();
        cout << endl << endl;
    }
    int g = 1;
    while(g == 1){
        system("cls");
        cout << "\n1. Afisare toti salariatii." << endl;
        cout << "2. Salariatul cel mai tanar." << endl;
        cout << "3. Salariatul cu salariu maxim." << endl;
        cout << "4. Exit." << endl;
        cout << "Numarul: "; cin >> t;
        switch(t){
            case 1:{
                for(int i = 0; i < n; i++){
                    angajat[i].afisare();
                    cout << endl << endl;
                }
                system("pause");
                break;
            }
            case 2:{
                int MIN = angajat[0].get_anul_nasterii(),nr=0;
                for(int i = 1; i < n; i++){
                    if(angajat[i].get_anul_nasterii()>MIN){
                        MIN = angajat[i].get_anul_nasterii();
                        nr = i;
                    }
                }
                cout << "Angajatul cel mai tanar:\n";
                angajat[nr].afisare();
                system("pause");
                break;
            }
            case 3:{
                int MAX =angajat[0].salariu(),nr=0;
                for(int i = 1; i < n; i++){
                    if(angajat[i].salariu()>MAX){
                        MAX = angajat[i].salariu();
                        nr = i;
                    }
                }
                cout << "Angajatul cu salariu maxim:\n";
                angajat[nr].afisare();
                system("pause");
            }
            case 4:{
                g=0;
                break;
            }
            default:{
                cout << "\nNu exista asa numar!" << endl;
                system("pause");
          }
        }
    }



    return 0;
}