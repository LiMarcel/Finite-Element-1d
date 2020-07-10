#include "Varition.h"

#include "Elements.h"

#include <iostream>

using namespace std;

int main()
{
    Element element(0, 1);

    vector<double> result = varition_D(element, varition_f);

    cout << result[0] << "  " << result[1] << endl;

    Element element1(0, 1);
    Element element2(0, 1);

    vector<vector<double>> result2 = varition_A(element1, element2);

    cout << result2[0][0] << " " << result2[0][1] << endl;
    cout << result2[1][0] << " " << result2[1][1] << endl;

    Elements elements1(0, 1, 1);

    vector<vector<double>> result3 = varition_A(elements1.elements[0], elements1.elements[0]);

    cout << result3[0][0] << " " << result3[0][1] << endl;
    cout << result3[1][0] << " " << result3[1][1] << endl;

    cout << size_t(5 > 3) + 1 << endl;

    return 0;
}