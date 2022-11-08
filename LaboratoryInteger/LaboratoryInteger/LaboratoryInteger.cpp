#include "LaboratoryInteger.h"
#include <iostream>

using namespace std;

int main()
{
    Integer a(10);
    Integer b(0);
    a.write();
    b.write();
    cout << "_________" << endl;
    /*Integer h = -a;*/
    //--a;
    //a--;
    //++a;
    //a++;
    //a.write();

    Integer c = a + b;
    Integer d = a - b;
    Integer e = a * b;
    //Integer f = a / b;
    //Integer g = a % b;

    //a += b;
    //a -= b;
    //a *= b;
    //a /= b;
    //a %= b;
    //a.write();

    cout << "+:  ";
    c.write();
    cout << "-:  ";
    d.write();
    cout << "*:  ";
    e.write();
    //cout << "/:  ";
    //f.write();
    //cout << "%:  ";
    //g.write();

    //cout << "-a:  ";
    //h.write();

    cout << "<= : " << (a <= b) << endl;
    cout << ">= : " << (a >= b) << endl;
    cout << "< : " << (a < b) << endl;
    cout << "> : " << (a > b) << endl;
    cout << "== : " << (a == b) << endl;
    cout << "!= : " << (a != b) << endl;
    return 0;
}
