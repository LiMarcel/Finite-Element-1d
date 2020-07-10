#ifndef AssembleH
#define AssembleH

#include "Elements.h"
#include "Varition.h"

#include <iostream>

using namespace std;

class Assemble
{
public:
    Assemble(Elements _elements, double (*_f)(double x));

private:
    Elements elements;

    double (*f)(double x);

    size_t n{1};

    vector<vector<double>> cut(vector<vector<double>> _mat, size_t _i);
    vector<double> cut(vector<double> _vec, size_t _i);

public:
    vector<vector<double>> AssembleA();
    vector<double> AssembleD();
};

#endif