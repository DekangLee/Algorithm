#include "elementAllot.hpp"
long long elementAllot(int n, int m)
{
    if (m == n)
        return 1;
    if (n < m)
        return 0;
    if (n >= 1 && m == 0)
        return 0;
    return m * elementAllot(n - 1, m) + elementAllot(n - 1, m - 1);
}
long long elemAllotIteration(int n, int m)
{
    if (m > n)
        return 0;
    if (m == n)
        return 1;
    long long **arr = new long long *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new long long[m];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                arr[j][i] = 1;
            }
            if (j < i)
            {
                arr[j][i] = 0;
            }
            if (j > i)
            {
                if (i == 0)
                {
                    arr[j][i] = 1;
                }
                else
                {
                    arr[j][i] = (i + 1) * arr[j - 1][i] + arr[j - 1][i - 1];
                }
            }
        }
    }
    long long res = arr[n - 1][m - 1];
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return res;
}
int FibArray(int n, int first, int second)
{
    if (n == 1)
    {
        return first;
    }
    return FibArray(n - 1, second, first + second);
}
double Solution(int n, int m)
{
    if (m < n)
        return 0;
    double **DP = new double *[m];
    for (int i = 0; i < m; i++)
    {
        DP[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
            {
                DP[i][j] = 0;
                continue;
            }
            if (j <= i)
            {
                if (j == 0)
                {
                    DP[i][j] = 1.0 / pow(n, i);
                }
                else
                {
                    DP[i][j] = DP[i - 1][j] * (static_cast<double>(j + 1) / n) + DP[i - 1][j - 1] * (static_cast<double>(n - (j + 1) + 1) / n);
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << DP[i][j] << "\t";
        }
        cout << endl;
    }
    double res = DP[m - 1][n - 1];
    for (int i = 0; i < m; i++)
    {
        delete[] DP[i];
    }
    delete[] DP;
    return res;
}
int combRecursion(int n, int m)
{
    if (n < m)
        return 0;
    if (n < 2 * m)
    {
        m = n - m;
    }
    if (m == 1)
        return n;
    if (n == 0 || m == 0)
        return 1;
    return combRecursion(n - 1, m) + combRecursion(n - 1, m - 1);
}
int combIteration(int n, int m)
{
    int **DP = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        DP[i] = new int[n + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
                DP[i][j] = 1;
            else if (i < j)
                DP[i][j] = 0;
            else if (j == 0 || i == j)
                DP[i][j] = 1;
            else
            {
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int res = DP[n][m];
    for (int i = 0; i <= n; i++)
    {
        delete[] DP[i];
    }
    delete[] DP;
    return res;
}