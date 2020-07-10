#include "FEM.h"

#include <iostream>

#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    FEM fem(0, 1, 4);

    cout << "123" << endl;

    FEMResult fem_result = fem.begin();

    cout << "123" << endl;

    cout << fem_result.parameters[0] << endl;

    copy(fem_result.parameters.begin(), fem_result.parameters.end(), ostream_iterator<double>(cout, "\n"));
}