#include <iostream>
#include <math.h>
using namespace std;
class Trinom{
    double a,b,c;
public:
Trinom();
Trinom(double,double,double);
~Trinom();
void afisare();
void calculare();
void operator=(Trinom& t){
        a = t.a;
        b = t.b;
        c = t.c;
}
Trinom operator+(Trinom &t){
    Trinom t3;
    t3.a=this->a+t.a;
    t3.b=this->b+t.b;
    t3.c=this->c+t.c;
    return t3;
}
};
Trinom::Trinom(){
    this->a=0;
    this->b=0;
    this->c=0;
}
Trinom::~Trinom(){
    cout << "Obiectul a fost sters!" << endl;
}
Trinom::Trinom(double a, double b, double c){
    this->a=a;
    this->b=b;
    this->c=c;
}
void Trinom::afisare(){
    if(b<0 && c<0){
        cout << a << "(x^2)" << b << "x" << c << endl;
    }
    else{
        if(b<0 && c>0){
            cout << a << "*(x^2)" << b << "*x+" << c << endl;
        }
        else{
            if(b>0 && c<0){
                cout << a << "*(x^2)+" << b << "*x" << c << endl;
            }
            else{
                cout << a << "*(x^2)+" << b << "*x+" << c << endl;
            }
        }
}
}
void Trinom::calculare(){
    double delta,x1,x2;
    delta = abs(pow(b,2))-4*a*c;
    if(delta>0){
        x1 = (-b+sqrt(delta))/2*a;
        x2 = (-b-sqrt(delta))/2*a;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    if(delta == 0){
        x1 = -b/(2*a);
        x2 = x1;
        cout << "x1 = x2 = " << x1 << endl;
    }
    if(delta < 0){
        cout << "\nNu exista radacina reala!" << endl;
    }
}
int main(){
Trinom a, b(4,8,-2);
cout << "------------ a:" << endl;
a.afisare();
cout << endl;
a.calculare();
cout << endl;
cout << "------------ b:" << endl;
b.afisare();
cout << endl;
b.calculare();
cout << endl;
cout << "------------ c:" << endl;
Trinom c = a+b;
c.afisare();
cout << endl;
c.calculare();
cout << endl;
cout << "------------ d:" << endl;
Trinom d(1,1,1);
d.afisare();
cout << endl;
d.calculare();
cout << endl;
system("pause");
    return 0;
}