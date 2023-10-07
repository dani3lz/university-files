#include <iostream>
using namespace std;

class Number {
    int num;
public:
    Number() {
        num = 0;
    }
    Number(int num) {
        this->num = num;
    }
    virtual double media() {
        return num;
    }
    virtual void citeste() {
        cout << "Numarul: ";
        cin >> num;
    }
    virtual ~Number() {
        cout << "Numarul a fost sters!" << endl;
    }
};

class Complex : public Number {
    double number;
public:
    Complex(){
        number = 0;
    }
    Complex(double number) {
        this->number = number;
    }
    ~Complex() {
        cout << "Numarul complex a fost sters!" << endl;
    }
    void citeste() {
        cout << "Numarul complex: ";
        cin >> number;
    }
    double media() {
        return number;
    }
};

class Vector : public Number {
    double vector[10];
public:
    Vector() {
        for (int i = 0; i < 10; i++)
            vector[i] = 0;
    }
    ~Vector() {
        cout << "Vectorul a fost sters!" << endl;
    }
    void citeste() {
        for (int i = 0; i < 10; i++) {
            cout << i+1 << ". ";
            cin >> vector[i];
        }
    }
    double media() {
        double m = 0;
        for (int i : vector)
            m += vector[i];
        m /= 10;
        return m;
    }
};

class Matrix : public Number {
    double matrix[2][2];
public:
    Matrix() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                matrix[i][j] = 0;
    }
    ~Matrix() {
        cout << "Matricea a fost stearsa!" << endl;
    }
    void citeste() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                cout << "[" << i << "," << j << "] = ";
                cin >> matrix[i][j];
            }
    }
    double media() {
        double m = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                m += matrix[i][j];
        m /= 4;
        return m;
    }
};

int main() {
    Number* numar[4];
    numar[0] = new Number(5);
    numar[1] = new Complex(8.67);
    numar[2] = new Vector;
    numar[3] = new Matrix;
    cout << "-------------- Vector:" << endl;
    numar[2]->citeste();
    cout << "-------------- Matrix:" << endl;
    numar[3]->citeste();
    cout << endl;
    for (int i = 0; i < 4; i++)
        cout << numar[i]->media() << endl;
    for (int i = 0; i < 4; i++) {
        delete numar[i];
        cout << endl;
    }
    system("pause");
    return 0;
}