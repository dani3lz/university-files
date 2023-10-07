#include <iostream>
#include <stdlib.h>
#include <math.h>
#define eps2 0.01
#define eps6 0.000001
using namespace std;

// a) log(x+2*x)+x-2
// b) (x*x*x)-25*x+2

double f1(double x){
    return (log(x+2*x)+x-2);
}
double f2(double x){
    return ((x*x*x)-25*x+2);
}
double g1(double x){
    return (2-log(x+2*x));
}
double g2(double x){
    return ((x*x*x+2)/25);
}
double f1_derivat(double x){
    return ((1/x)+1);
}
double f2_derivat(double x){
    return (3*x*x-25);
}
void half_f1(double a, double b){
    int iteratii=0;
    cout.precision(10);
    if(f1(a)*f1(b)>=0){
        cout << "Intervalul este incorect!"<< endl;
        return;
    }
    double c=a;
    while((b-a)>=2*eps2){
        c=(a+b)/2;
        if(f1(c)== 0.0)
            break;
        else
        {
            if(f1(c)*f1(a)<0)
                b=c;
            else
                a=c;
        }
        cout << "Intervalul este ["<< a << "," << b << "]" << endl;
        iteratii++;
    }
    c=(a+b)/2;
    cout << "Solutia ecuatiei este:" << c << endl;
    cout << "Iteratii --> " << iteratii << endl;
}
void half_f2(double a, double b){
    int iteratii=0;
    cout.precision(10);
    if(f2(a)*f2(b)>=0){
        cout << "Intervalul este incorect!"<< endl;
        return;
    }
    double c=a;
    while((b-a)>=2*eps2){
        c=(a+b)/2;
        if(f2(c)== 0.0)
            break;
        else
        {
            if(f2(c)*f2(a)<0)
                b=c;
            else
                a=c;
        }
        cout << "Intervalul este ["<< a << "," << b << "]" << endl;
        iteratii++;
    }
    c=(a+b)/2;
    cout << "Solutia ecuatiei este:" << c << endl;
    cout << "Iteratii --> " << iteratii << endl;
}
void aproximare_f1(double xn){
    double x0;
    cout.precision(10);
    int iteratii=0;
    do{
        x0=xn;
        xn=g1(x0);
        iteratii++;
        cout << "X0 = " << x0 << "\tXn = " << xn << "----> Iteratii = " << iteratii << endl;
    } while (fabs(xn-x0)>eps6);
    cout << "Solutia =\t" << xn << endl;
    cout << "Iteratii =\t" << iteratii << endl;
}
void aproximare_f2(double xn){
    double x0;
    cout.precision(10);
    int iteratii=0;
    do{
        x0=xn;
        xn=g2(x0);
        iteratii++;
        cout << "X0 = " << x0 << "\tXn = " << xn << "----> Iteratii = " << iteratii << endl;
    } while (fabs(xn-x0)>eps6);
    cout << "Solutia =\t" << xn << endl;
    cout << "Iteratii =\t" << iteratii << endl;
}
double newton_f1(double x0){
    cout.precision(10);
    double x;
    int iteratii=0;
    do{
        iteratii++;
        x= x0-f1(x0)/ f1_derivat(x0);
        x0=x;
        cout << "Iteratii: " << iteratii << "\tx = " << x0 << endl;
        if(iteratii>1000){
            cout << "Solutia nu a putut fi calculata!" << endl;
            return -1;
        }
    } while(abs(f1(x))>eps6);
    cout << "Solutia ecuatiei este: " << x << endl;
    cout << "Nr. de iteratii: " << iteratii << endl;
    return x;
}
double newton_f2(double x0){
    cout.precision(10);
    double x;
    int iteratii=0;
    do{
        iteratii++;
        x= x0-f2(x0)/ f2_derivat(x0);
        x0=x;
        cout << "Iteratii: " << iteratii << "\tx = " << x0 << endl;
        if(iteratii>1000){
            cout << "Solutia nu a putut fi calculata!" << endl;
            return -1;
        }
    } while(abs(f2(x))>eps6);
    cout << "Solutia ecuatiei este: " << x << endl;
    cout << "Nr. de iteratii: " << iteratii << endl;
    return x;
}
void secante_f1(double x1, double x2){
    cout.precision(10);
    int iteratii=0;
    do{
        iteratii++;
        cout << "x = " << x2 << " ----> Iteratii = " << iteratii << endl;
        double punctul_m= x2-(x2-x1)*f1(x2)/(f1(x2)-f1(x1));
        x1=x2;
        x2=punctul_m;
    } while(abs(f1(x2))>eps6);
    cout << "Solutia = " << x2 << endl;
}
void secante_f2(double x1, double x2){
    cout.precision(10);
    int iteratii=0;
    do{
        iteratii++;
        cout << "x = " << x2 << " ----> Iteratii = " << iteratii << endl;
        double punctul_m= x2-(x2-x1)*f2(x2)/(f2(x2)-f2(x1));
        x1=x2;
        x2=punctul_m;
    } while(abs(f2(x2))>eps6);
    cout << "Solutia = " << x2 << endl;
}
/* =================== Main ======================= */
int main(){
    int n, g=1;
while(g==1){
    system("cls");
    cout << "\n1. Metoda injumatatirii." << endl;
    cout << "2. Metoda aproximarii succesive." << endl;
    cout << "3. Metoda Newton(tangentelor)." << endl;
    cout << "4. Metoda secantelor." << endl;
    cout << "5. Exit" << endl;
    cout << "Numarul:\t";
    cin >> n;
    switch (n)
    {
    case 1:{
        double a,b;
        cout << "\nIntroduceti marginile intervalului p/u functia nr.1:\t";
        cin >> a >> b;
        cout << "\n----------------Functia nr.1:" << endl;
        half_f1(a,b);
        cout << "\nIntroduceti marginile intervalului p/u functia nr.2:\t";
        cin >> a >> b;
        cout << "\n----------------Functia nr.2:" << endl;
        half_f2(a,b);
        cout << endl;
        system("pause");
        break;
    }
    case 2:{
        double x0;
        cout << "Introduceti aproximatia initiala p/u functia nr.1:\t";
        cin >> x0;
        cout << "\n----------------Functia nr.1:" << endl;
        aproximare_f1(x0);
        cout << "Introduceti aproximatia initiala p/u functia nr.2:\t";
        cin >> x0;
        cout << "\n----------------Functia nr.2:" << endl;
        aproximare_f2(x0);
        system("pause");
        break;
    }
    case 3:{
        double x0;
        cout << "Introduceti solutia initiala p/u functia nr.1:\t";
        cin >> x0;
        cout << "\n----------------Functia nr.1:" << endl;
        newton_f1(x0);
        cout << "Introduceti solutia initiala p/u functia nr.1:\t";
        cin >> x0;
        cout << "\n----------------Functia nr.2:" << endl;
        newton_f2(x0);
        system("pause");
        break;
    }
    case 4:{
        double x0, x1;
        cout << "Solutia initiala x0 si x1 p/u functia nr.1:\t";
        cin >> x0 >> x1;
        cout << "\n----------------Functia nr.1:" << endl;
        secante_f1(x0,x1);
        cout << "Solutia initiala x0 si x1 p/u functia nr.2:\t";
        cin >> x0 >> x1;
        cout << "\n----------------Functia nr.2:" << endl;
        secante_f2(x0,x1);
        system("pause");
        break;
    }
    case 5:{
        g=0;
        break;
    }
    default:{
        cout << "\nNu exista asa optiune!" << endl;
        system("pause");
        break;
    }
    }
}
    return 0;
}