#ifndef ElementsH
#define ElementsH

#include <vector>
#include "Element.h"

using std::vector;


class Elements
{
public:
    Elements(double _a, double _b, double _n);

private:
    double a{0}, b{1}, n{1};

public:
    vector<Element*> elements;
};

#endif