#ifndef ElementH
#define ElementH

#include "Function.h"

class ElementL : public Function
{
public:
    ElementL(double _a, double _b) : a(_a), b(_b) {}
    ElementL() {}

    double operator()(double x);

    double derivative(double x);

public:
    double a{0}, b{1};
};

class ElementR : public Function
{
public:
    ElementR(double _a, double _b) : a(_a), b(_b) {}
    ElementR() {}

    double operator()(double x);

    double derivative(double x);

public:
    double a{0}, b{1};
};
class Element
{
public:
    Element(double _a, double _b) : a(_a), b(_b)
    {
        element_l = ElementL(a, b);
        element_r = ElementR(a, b);
    }
    Element(){}
    // Element(const Element& _element);

    ElementL element_l;
    ElementR element_r;

public:
    double a{0}, b{1};
};

#endif