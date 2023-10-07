#include <iostream>
#include <stdlib.h>
using namespace std;

class Timp {
    int ora, min, sec;
public:
    Timp();
    Timp(int, int, int);
    void check();
    int convert(const Timp& t) {
        return (((t.ora * 60) * 60) + (t.min * 60) + t.sec);
    }
    void operator++() {
        this->sec += 1;
        check();
    }
    void operator--() {
        this->sec -= 1;
        check();
    }
    Timp operator+(Timp& t1) {
        Timp t3;
        t3.ora = ora + t1.ora;
        t3.min = min + t1.min;
        t3.sec = sec + t1.sec;
        t3.check();
        return t3;
    }
    Timp operator-(Timp& t1) {
        Timp t3;
        t3.ora = ora - t1.ora;
        t3.min = min - t1.min;
        t3.sec = sec - t1.sec;
        t3.check();
        return t3;
    }
    void operator=(const Timp& Timp2) {
        ora = Timp2.ora;
        min = Timp2.min;
        sec = Timp2.sec;
    }
    int operator==(Timp Timp2) {
        if (convert(*this) == convert(Timp2))
            return 1;
        else
            return 0;
    }
    int operator!=(Timp Timp2) {
        if (convert(*this) != convert(Timp2))
            return 1;
        else
            return 0;
    }
    int operator<=(Timp Timp2) {
        if (convert(*this) <= convert(Timp2))
            return 1;
        else
            return 0;
    }
    int operator<(Timp Timp2) {
        if (convert(*this) < convert(Timp2))
            return 1;
        else
            return 0;
    }
    int operator>(Timp Timp2) {
        if (convert(*this) > convert(Timp2))
            return 1;
        else
            return 0;
    }
    int operator>=(Timp Timp2) {
        if (convert(*this) >= convert(Timp2))
            return 1;
        else
            return 0;
    }
    friend ostream& operator<<(ostream& output, const Timp& t) {
        if(t.min<10 && t.sec <10)
            output << t.ora << ":0" << t.min << ":0" << t.sec << endl;
        else
        {
            if(t.min<10)
                output << t.ora << ":0" << t.min << ":" << t.sec << endl;
            if(t.sec <10)
                output << t.ora << ":" << t.min << ":0" << t.sec << endl;
            if(t.min>9 && t.sec>9)
                output << t.ora << ":" << t.min << ":" << t.sec << endl;
        }
        return output;
    }
    friend istream& operator>>(istream& input, Timp& t) {
        cout << "Ora: ";
        input >> t.ora;
        cout << "Minutele: ";
        input >> t.min;
        cout << "Secunde: ";
        input >> t.sec;
        t.check();
        return input;
    }
};
Timp::Timp() {
    ora = min = sec = 0;
};

void Timp::check() {
az:
    if (this->ora > 23) {
        this->ora -= 24;
        goto az;
    }
    if (this->ora < 0) {
        this->ora += 24;
        goto az;
    }
    if (this->min > 59) {
        this->min -= 60;
        this->ora += 1;
        goto az;
    }
    if (this->min < 0) {
        this->min += 60;
        this->ora -= 1;
        goto az;
    }
    if (this->sec > 59) {
        this->sec -= 60;
        this->min += 1;
        goto az;
    }
    if (this->sec < 0) {
        this->sec += 60;
        this->min -= 1;
        goto az;
    }
};
Timp::Timp(int ora, int min, int sec) {
    this->ora = ora;
    this->min = min;
    this->sec = sec;
    check();
};

int main() {
    Timp t1;
    Timp t2(33, 66, 80);
    if (t1 == t2)
        cout << "Timpul este egal!" << endl;
    if (t1 != t2)
        cout << "Timpul nu este egal!" << endl;
    if (t1 < t2)
        cout << "Timupl 2 este mai mare decat Timpul 1" << endl;
    cout << "Timpul 1:" << endl;
    cout << t1;
    cout << "Timpul 2:" << endl;
    cout << t2;
    cout << "Citirea pentru Timpul 1:" << endl;
    cin >> t1;
    cout << "Timpul 1:" << endl;
    cout << t1;
    cout << "Incrementarea cu o secunda pentru Timpul 1:" << endl;
    ++t1;
    cout << t1;
    cout << "Decrementarea cu o secunda secundei pentru Timpul 1:" << endl;
    --t1;
    cout << t1;
    cout << "Timpul 3 care este egal cu Timpul 1 + Timpul 2:" << endl;
    Timp t3 = t1 + t2;
    cout << t3;
    cout << "Timpul 4 care este egal cu Timpul 1 - Timpul 2:" << endl;
    Timp t4 = t1 - t2;
    cout << t4;

    system("pause");

    return 0;
}