#include "SolveEqu.h"

int main()
{
    vector<vector<double>> a = {{8, -3, 2}, {4, 11, -1}, {6, 3, 12}};
    vector<double> y = {20, 33, 36};

    SolveEqu s(a, y);

    vector<double> x = s.GaussSeidel();

    for (size_t i = 0; i < 3; i++)
    {
        cout << x[i] << endl;
    }
    

    
    return 0;
}