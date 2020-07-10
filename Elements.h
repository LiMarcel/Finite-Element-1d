#ifndef ElementsH
#define ElementsH

#include <vector>
#include "Element.h"

using std::vector;

class Elements
{
public:
    Elements(double _a, double _b, double _n);
    Elements(){};
    Elements(const Elements& _elements);

public:
    double a{0.0}, b{1.0};
    size_t n{1};
    vector<Element> elements;

public:
    vector<double> GetParameters();

    size_t GetNumber();

    // Elements &operator=(const Elements &_elements);
};

#endif