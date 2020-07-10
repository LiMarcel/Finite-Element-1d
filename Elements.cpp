#include "Elements.h"

Elements::Elements(double _a, double _b, double _n)
{
    a = _a;
    b = _b;
    n = _n;

    double h = (b - a) / n;

    for (size_t i = 0; i < n; i++)
    {
        elements.push_back(Element(a + i * h, a + (i + 1) * h));
    }
}

Elements::Elements(const Elements &_elements)
{
    this->a = _elements.a;
    this->b = _elements.b;
    this->n = _elements.n;

    double h = (b - a) / n;

    for (size_t i = 0; i < n; i++)
    {
        this->elements.push_back(Element(a + i * h, a + (i + 1) * h));
    }

}

vector<double> Elements::GetParameters()
{
    return vector<double>{a, b};
}

size_t Elements::GetNumber()
{
    return n;
}

// Elements &Elements::operator=(const Elements &_elements)
// {
//     Elements temp_elements;
//     temp_elements.a = _elements.a;
//     temp_elements.b = _elements.b;
//     temp_elements.n = _elements.n;

//     double h = (b - a) / n;

//     for (size_t i = 0; i < n; i++)
//     {
//         temp_elements.elements.push_back(Element(a + i * h, a + (i + 1) * h));
//     }

//     return temp_elements;
// }