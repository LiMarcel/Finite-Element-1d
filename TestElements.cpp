#include "Elements.h"

#include <iostream>
using namespace std;

int main()
{
    Elements e(0, 1, 4);
    Elements elements;

    cout << e.elements[0].element_l(0) << endl;
    cout << e.elements[0].element_r(0) << endl;
    cout << e.elements[3].element_l(1) << endl;

    elements = e;
    cout << e.a << endl;
    cout << e.b << endl;
    cout << e.n << endl;
    cout << elements.elements[0].element_l(0) << endl;


    return 0;
}