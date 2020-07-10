#include "Element.h"

// Element::Element(const Element& _element)
// {
//     this -> element_l = _element.element_l;
//     this -> element_r = _element.element_r;
// }

double ElementL::operator()(double x)
{
    return (b - x) / (b - a);
}

double ElementL::derivative(double x)
{
    return (-1) / (b - a);
}

double ElementR::operator()(double x)
{
    return (x - a) / (b - a);
}

double ElementR::derivative(double x)
{
    return (1) / (b - a);
}