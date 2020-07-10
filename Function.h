#ifndef FunctionH
#define FunctionH

class Function
{
    virtual double operator()(double x) = 0;

    virtual double derivative(double x)
    {
        return  (operator()(x + 0.001) - operator()(x))/0.001;
    }
};

#endif