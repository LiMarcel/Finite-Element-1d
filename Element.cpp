#include "Element.h"

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