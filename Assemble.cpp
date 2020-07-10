#include "Assemble.h"

Assemble::Assemble(Elements _elements, double (*_f)(double x))
{
    elements = _elements;
    f = _f;

    n = elements.elements.size();
}

vector<vector<double>> Assemble::cut(vector<vector<double>> _mat, size_t _i)
{
    size_t temp_n = _mat.size();

    vector<vector<double>> mat;
    mat.resize(temp_n - 1);
    for (size_t i = 0; i < temp_n - 1; i++)
    {
        mat[i].resize(temp_n - 1);

        for (size_t j = 0; j < temp_n - 1; j++)
        {
            mat[i][j] = _mat[i + size_t(i >= _i)][j + size_t(j >= _i)];
        }
    }

    return mat;
}

vector<double> Assemble::cut(vector<double> _vec, size_t _i)
{
    size_t temp_n = _vec.size();

    vector<double> vec;
    vec.resize(temp_n - 1);

    for (size_t i = 0; i < temp_n-1; i++)
    {
        vec[i] = _vec[i + size_t(i >= _i)];
    }

    return vec;
}

vector<vector<double>> Assemble::AssembleA()
{
    vector<vector<double>> result;

    result.resize(n + 1);
    for (size_t i = 0; i < n + 1; i++)
    {
        result[i].resize(n + 1);
    }

    for (size_t i = 0; i < n; i++)
    {
        vector<vector<double>> temp_result = varition_A(elements.elements[i], elements.elements[i]);

        result[i][i] += temp_result[0][0];
        result[i][i + 1] += temp_result[0][1];
        result[i + 1][i] += temp_result[1][0];
        result[i + 1][i + 1] += temp_result[1][1];
    }

    // for (size_t i = 0; i < n+1; i++)
    // {
    //     for (size_t j = 0; j < n+1; j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return cut(result, 0);
}

vector<double> Assemble::AssembleD()
{
    vector<double> result;

    result.resize(n + 1);

    for (size_t i = 0; i < n; i++)
    {
        vector<double> temp_result = varition_D(elements.elements[i], f);

        cout << temp_result[0] << " " << temp_result[1] << endl;
        result[i] += temp_result[0];
        result[i + 1] += temp_result[1];
    }

    // for (size_t i = 0; i < n+1; i++)
    // {
    //     cout << result[i] << " ";
    // }

    // cout << endl;

    return cut(result, 0);
}
