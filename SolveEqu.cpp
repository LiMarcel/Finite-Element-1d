#include "SolveEqu.h"

vector<double> SolveEqu::GaussSeidel()
{
    vector<double> result, temp_result;
    result.resize(N);
    temp_result.resize(N);
    for (size_t i = 0; i < N; i++)
    {
        result[i] = 0.0;
        temp_result[i] = 0.0;
    }

    double dis = 0.0;
    do
    {
        for (size_t i = 0; i < N; i++)
        {
            double temp = 0.0;
            for (size_t j = 0; j < i; j++)
            {

                temp += A[i][j] * temp_result[j];
            }

            for (size_t j = i + 1; j < N; j++)
            {

                temp += A[i][j] * result[j];
            }

            temp_result[i] = (Y[i] - temp) / A[i][i];
        }

        dis = L2(result, temp_result);

        result.assign(temp_result.begin(), temp_result.end());
    } while (dis > 0.0001);

    return result;
}

size_t SolveEqu::IsTriMat()
{

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (j < i - 1 && j > i + 1 && A[i][j] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

double SolveEqu::L2(vector<double> x1, vector<double> x2)
{
    double result = 0.0;
    for (size_t i = 0; i < N; i++)
    {
        result += (x1[i] - x2[i]) * (x1[i] - x2[i]);
    }

    return sqrt(result);
}