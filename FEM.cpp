#include "FEM.h"

FEM::FEM(double _a, double _b, size_t _n)
{
    a = _a;
    b = _b;
    n = _n;

    elements = Elements(a, b, n);
}

FEMResult FEM::begin()
{
    Assemble assemble(elements, varition_f);

    vector<vector<double>> A = assemble.AssembleA();

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    vector<double> Y = assemble.AssembleD();

    vector<double> parameters = SolveEqu(A, Y).GaussSeidel();

    FEMResult fem_result;

    fem_result.parameters.assign(parameters.begin(), parameters.end());

    fem_result.elements = elements;
    return fem_result;
}