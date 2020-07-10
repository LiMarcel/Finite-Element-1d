#ifndef FEMH
#define FEMH

#include "Elements.h"
#include "SolveEqu.h"
#include "Assemble.h"

typedef struct 
{
    Elements elements;
    vector<double> parameters;
} FEMResult;

#include <iostream>

using namespace std;

class FEM
{
public:
    FEM(double _a, double _b, size_t _n);

    double a{0.0}, b{1.0};
    size_t n{1};

    Elements elements;

    FEMResult begin();
};

#endif