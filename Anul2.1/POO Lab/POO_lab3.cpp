#include <iostream>
#include <stdlib.h>
using namespace std;

// a)
class Timp {
    int ora, min, sec;
public:
    Timp();
    Timp(int, int, int);
    void check();
    void afisare();
    int convert(const Timp& t) {
        return (((t.ora * 60) * 60) + (t.min * 60) + t.sec);
    }
    Timp& operator++() {
        sec++;
        check();
        return *this;
    }
    Timp& operator--() {
        sec--;
        check();
        return *this;
    }
    Timp operator++(int){
        Timp temp = *this;
        ++(*this).sec;
        return temp;
    }
    Timp operator--(int){
        Timp temp = *this;
        --(*this).sec;
        return temp;
    }
    friend Timp operator+(Timp& t1, Timp& t2){
        Timp t3;
        t3.ora = t1.ora + t2.ora;
        t3.min = t1.min + t2.min;
        t3.sec = t1.sec + t2.sec;
        t3.check();
        return t3;}
    friend Timp operator-(Timp& t1, Timp& t2){
        Timp t3;
        t3.ora = t1.ora - t2.ora;
        t3.min = t1.min - t2.min;
        t3.sec = t1.sec - t2.sec;
        t3.check();
        return t3;
    }
    friend ostream& operator<<(ostream& output, const Timp& t) {
        if(t.min<10 && t.sec <10)
            output << t.ora << ":0" << t.min << ":0" << t.sec;
        else
        {
            if(t.min<10)
                output << t.ora << ":0" << t.min << ":" << t.sec;
            if(t.sec <10)
                output << t.ora << ":" << t.min << ":0" << t.sec;
            if(t.min>9 && t.sec>9)
                output << t.ora << ":" << t.min << ":" << t.sec;
        }
        return output;
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

// b)
class Queue{
    int front, elements, size;
    int *coada;
public:
    Queue();
    Queue(int);
    ~Queue();
    void adauga(int);
    void elimina();
    void afisare();

    Queue operator+(Queue& q1){
        int n = this->elements + q1.elements, count = 0;
        Queue q3(n);
        for (int i=0;i<this->elements;i++)
            q3.adauga(this->coada[i]);
        for (int i=0;i<q1.elements;i++)
            q3.adauga(q1.coada[i]);
        return q3;
    };
    void operator=(const Queue& q1){
        size = q1.size;
        elements = q1.elements;
        coada = q1.coada;
    };
    friend int operator==(Queue q1,Queue q2) {
        if (q1.elements == q2.elements)
            return 1;
        else
            return 0;
    };
    friend int operator!=(Queue q1,Queue q2) {
        if (q1.elements != q2.elements)
            return 1;
        else
            return 0;
    };
    friend int operator<(Queue q1,Queue q2) {
        if (q1.elements < q2.elements)
            return 1;
        else
            return 0;
    };
    friend int operator>(Queue q1,Queue q2) {
        if (q1.elements > q2.elements)
            return 1;
        else
            return 0;
    };
    friend ostream& operator<<(ostream& output, Queue& q) {
        int n;
        output << "Elementul: ";
        cin >> n;
        q.adauga(n);
        return output;
    };
    friend istream& operator>>(istream& input, Queue& q) {
        q.elimina();
        return input;
    };
};

Queue::Queue(){
    front = 0;
    elements = 0;
    size = 10;
    coada = new int[size];
};

Queue::Queue(int n){
    front = 0;
    elements = 0;
    size = n;
    coada = new int[size];
};

Queue::~Queue(){
    delete [] coada;
};

void Queue::adauga(int n){
    if (elements<size)
        coada[elements++]=n;
    else
        cout << "\nCoada este plina!" << endl;
};

void Queue::elimina(){
    if(front<elements){
        for(int i = 0; i < elements-1; i++)
            coada[i]=coada[i+1];
        --elements;
    }
    else
        cout << "\nCoada nu are elemente!" << endl;
};

void Queue::afisare(){
    for(int i=0;i<elements;i++)
        cout << coada[i] << " ";
};

int main() {
    Timp t1(1,1,1);
    Timp t2(2,2,2);
    cout << t1-t2 << endl;
    cout << t1+t2 << endl;
    ++t1;
    t2--;
    cout << t1 << endl;
    cout << t2 << endl;
    
    Queue q1;
    Queue q2(5);
    cout << "----------- Coada q1:" << endl;
    for(int i=0;i<3;i++)
        cout << q1;
    cout << "----------- Coada q2:" << endl;
    for(int i=0;i<3;i++)
        cout << q2;
    cout << "----------- Afisare q1:" << endl;
    q1.afisare();
    cout << "\n----------- Afisare q2:" << endl;
    q2.afisare();
    cin >> q2;
    cout << "\n----------- Afisare q2 dupa stergerea primului element:" << endl;
    q2.afisare();
    Queue q3 = q1+q2;
    cout << "\n----------- Afisare q3:" << endl;
    q3.afisare();
    if(q1 == q2)
        cout << "\nSunt egale!" << endl;
    else
        cout << "\nNu sunt egale" << endl;
    if(q1 > q2)
        cout << "Coada q1 este mai mare decat coada q2" << endl;
    else
        cout << "Coada q2 este mai mare decat coada q1" << endl;
    
    system("pause");
    return 0;
}