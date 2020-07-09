#include "Elements.h"

Elements::Elements(double _a, double _b, double _n)
{
    a = _a;
    b = _b;
    n = _n;

    elements.resize(n);

    double h = (b - a) / n;

    for (size_t i = 0; i < n; i++)
    {
        elements[i] = new Element(a + i * h, a + (i + 1) * h);
    }

}