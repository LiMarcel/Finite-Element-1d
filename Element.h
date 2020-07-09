#ifndef ElementH
#define ElementH

#include "Function.h"

class ElementL : public Function
{
public:
    ElementL(double _a, double _b) : a(_a), b(_b) {}

    double operator()(double x);

    double derivative(double x);

private:
    double a{0}, b{1};
};

class ElementR : public Function
{
public:
    ElementR(double _a, double _b) : a(_a), b(_b) {}

    double operator()(double x);

    double derivative(double x);

private:
    double a{0}, b{1};
};
class Element
{
public:
    Element(double _a, double _b) : a(_a), b(_b)
    {
        element_l = new ElementL(a, b);
        element_r = new ElementR(a, b);
    }
    ~Element()
    {
        if (element_l)
            delete element_l;
        if (element_r)
            delete element_r;
    }

    ElementL *element_l;
    ElementR *element_r;

private:
    double a{0}, b{1};
};

#endif