#include <iostream>
#include <stdlib.h>
#define pi 3.14
using namespace std;

class cerc{
    double lungimea_razei;
public:
    double lungimea_r(){
        return lungimea_razei;
    }
    void citire();
    void afisare();
    double lungimea_discului(double);
    double suprafata(double);
    double diametrul(double);
    void sortare(cerc*);
};
void cerc::citire(){
    cout << "Dati lungimea razei:\t";
    cin >> lungimea_razei;
}
double cerc::lungimea_discului(double raza){
    double lungimea;
    lungimea = 2*pi*raza;
    return lungimea;
}
double cerc::suprafata(double raza){
    double aria;
    aria = pi*raza*raza;
    return aria;
}
double cerc::diametrul(double raza){
    double d;
    d=raza*2;
    return d;
}
void cerc::afisare(){
    cout << "\n1. Lungimea cercului = " << this->lungimea_razei << endl;
    cout << "2. Lungimea discului = " << lungimea_discului(lungimea_razei) << endl;
    cout << "3. Suprafata discului = " << suprafata(lungimea_razei) << endl;
    cout << "4. Diametrul discului = " << diametrul(lungimea_razei) << endl;
}
void cerc::sortare(cerc* cercul){
    int n, g=1;
while(g==1){
    cout << "\n1. Suprafata maxima." << endl;
    cout << "2. Lungimea discului minimal." << endl;
    cout << "3. Exit" << endl;
    cout << "Numarul:\t";
    cin >> n;
    switch (n)
    {
        case 1:{
            if(suprafata(this->lungimea_r())>suprafata((*cercul).lungimea_r()))
                cout << "\nSuprafata maxima este la Cercul nr.1" << endl;
            else{
                if(suprafata(this->lungimea_r())<suprafata((*cercul).lungimea_r()))
                    cout << "\nSuprafata maxima este la Cercul nr.2" << endl;
                else
                    cout << "\nSuprafata este egala la ambele cercuri." << endl;
            }
            break;
        }
        case 2:{
            if(lungimea_discului(this->lungimea_r())<lungimea_discului((*cercul).lungimea_r()))
                cout << "\nLungimea minimala este la cercul nr.1" << endl;
             else{
                if(lungimea_discului(this->lungimea_r())>lungimea_discului((*cercul).lungimea_r()))
                    cout << "\nLungimea minimala este la cercul nr.2" << endl;
                else
                    cout << "\nLungimea este egala la ambele cercuri." << endl;
            }
            break;
        }
        case 3:{
            g=0;
            break;
        }
        default:{
            cout << "Nu exista asa optiune!" << endl;
            system("pause");
        }
    }
}
}

int main(){
    cerc *cercul1 = new cerc;
    cerc *cercul2 = new cerc;

    cout << "----------- Cercul nr.1:" << endl;
    (*cercul1).citire();
    cout << "----------- Cercul nr.2:" << endl;
    (*cercul2).citire();

    cout << "\n----------- Cercul nr.1:" << endl;
    (*cercul1).afisare();
    cout << "----------- Cercul nr.2:" << endl;
    (*cercul2).afisare();

    cout << "----------- Sortarea:" << endl;
    (*cercul1).sortare(cercul2);

    system("pause");
    return 0;
}