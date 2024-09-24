/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-08-26 14:08:12
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-08-26 15:37:17
 * @FilePath: \Algorithm\DynamicProgramming\linearDP\LCS.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int N = 30010;
vector<vector<int>> dp(N, vector<int>(N, 0));

int main()
{
    string str_a, str_b;
    string res;
    cin >> str_a >> str_b;
    int n = str_a.size();
    int m = str_b.size();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (str_a[i - 1] == str_b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;
    while (dp[i][j])
    {
        if (str_a[i - 1] == str_b[j - 1])
        {
            res += str_a[i - 1];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    }
    cout << dp[n][m] << endl;
    for (int c = dp[n][m] - 1; c >= 0; --c)
    {
        cout << res[c];
    }
    cout << endl;
    return 0;
}