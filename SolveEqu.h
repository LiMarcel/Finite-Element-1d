// TODO IsTriMat

#ifndef SolveEquH
#define SolveEquH

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class SolveEqu
{
public:
    SolveEqu(vector<vector<double>> _A, vector<double> _Y)
    {
        A.assign(_A.begin(), _A.end());
        Y.assign(_Y.begin(), _Y.end());
        N = A.size();
    }

private:
    vector<vector<double>> A;
    vector<double> Y;
    size_t N;

public:
    vector<double> GaussSeidel();

private:
    size_t IsTriMat();

    // 衡量两个向量的L2范数
    double L2(vector<double> x1, vector<double> x2);
};

#endif