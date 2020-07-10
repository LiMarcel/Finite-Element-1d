#ifndef VaritionH
#define VaritionH

#include "Element.h"
#include <vector>
#include <iostream>

using namespace std;

inline double varition_f(double x)
{
    return 2;
}

inline vector<double> varition_D(Element e, double (*f)(double x))
{
    vector<double> result;
    result.resize(2);

    size_t n = 100;
    double h = (e.b - e.a) / n;

    for (size_t i = 0; i < n; i++)
    {
        double left = e.a + i * h;
        double right = e.a + (i + 1) * h;
        result[0] += h * (e.element_l(left) * f(left) + e.element_l(right) * f(right)) / 2;
        result[1] += h * (e.element_r(left) * f(left) + e.element_r(right) * f(right)) / 2;
    }

    return result;
}

inline vector<vector<double>> varition_A(Element e1, Element e2)
{
    vector<vector<double>> result;
    result.resize(2);
    result[0].resize(2);
    result[1].resize(2);

    size_t n = 100;
    double h = (e1.b - e1.a) / n;

    for (size_t i = 0; i < n; i++)
    {
        double left = e1.a + i * h;
        double right = e1.a + (i + 1) * h;
        result[0][0] += h * (e1.element_l.derivative(left) * e1.element_l.derivative(left) + e1.element_l.derivative(right) * e1.element_l.derivative(right)) / 2;
        result[0][1] += h * (e1.element_l.derivative(left) * e1.element_r.derivative(left) + e1.element_l.derivative(right) * e1.element_r.derivative(right)) / 2;
        result[1][0] += h * (e1.element_r.derivative(left) * e1.element_l.derivative(left) + e1.element_r.derivative(right) * e1.element_l.derivative(right)) / 2;
        result[1][1] += h * (e1.element_r.derivative(left) * e1.element_r.derivative(left) + e1.element_r.derivative(right) * e1.element_r.derivative(right)) / 2;
    }

    return result;
}

#endif