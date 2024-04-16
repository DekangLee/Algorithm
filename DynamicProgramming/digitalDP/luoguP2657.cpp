/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-04-03 11:26:00
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-04-07 13:38:10
 * @FilePath: \Algorithm\DynamicProgramming\digitalDP\luoguP2657.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int dp[11][11];
int limits1[10];
int limits2[10];
int dfs(int i, int p) // i 是当前的位数，p是当前位置数
{
    if (i == 1)
    {
        dp[i][p] = 1;
        return 1;
    }
    if (dp[i][p] != -1)
        return dp[i][p];
    int res = 0;
    int limit1 = 0; // lmit1即是下一位置的数
    int limit2 = 9;
    while (limit1 <= limit2) // 枚举i位置的数
    {
        if (abs(limit1 - p) >= 2)      // 满足windy数的条件
            res += dfs(i - 1, limit1); // 在该条件下继续向下深搜
        ++limit1;
    }
    dp[i][p] = res;
    return res;
}
int dfs(int i, int p, int *limits) // i 是当前的位数，p是当前位置之前的数
{
    if (i == 1)
    {
        dp[i][p] = 1;
        return 1;
    }
    if (dp[i][p] != -1)
        return dp[i][p];
    int res = 0;
    int limit1 = 0;
    int limit2 = limits[i - 1];
    printf("limit1 = %d, limit2 = %d\n", limit1, limit2);
    while (limit1 < limit2) // 枚举i位置的数
    {
        if (abs(limit1 - p) >= 2)              // 满足windy数的条件
            res += dfs(i - 1, limit1, limits); // 在该条件下继续向下深搜
        if (abs(limits[i] - limits[i - 1]) < 2)
            break;
        ++limit1;
    }
    if (i == 1 && limit1 == limit2 - 1 && abs(limits[i] - limits[i - 1]) >= 2)
        ++res;
    
    return res;
}
int l;
int r;
void printInfo()
{
    for (int i = 1; i <= 9; ++i)
    {
        printf("limit1 = %d, limit2 = %d\n", limits1[i], limits2[i]);
    }
    for (int i = 0; i <= 9; ++i)
    {
        for (int j = 0; j <= 10; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    cin >> l >> r;
    int pos1 = 0;
    int mod = 10;
    int num = l - 1;
    memset(dp, -1, sizeof(dp));
    while (num)
    {
        limits1[++pos1] = num % mod;
        num /= 10;
    }
    int pos2 = 0;
    num = r;
    while (num)
    {
        limits2[++pos2] = num % mod;
        num /= 10;
    }
    cout << "pos1 = " << pos1 << " pos2 = " << pos2 << endl;
    printInfo();
    int ansl = 0;
    int ansr;
    for (int i = 1; i <= pos1; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            if (i == pos1 && j == limits1[i])
            {
                ansl += dfs(i, j, limits1);
                break;
            }
            else
                ansl += dfs(i, j);
        }
        cout << "ansl = " << ansl << endl;
    }
    printInfo();
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= pos2; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            if (i == pos2 && j == limits2[i])
            {
                ansr += dfs(i, j, limits2);
                break;
            }
            else
                ansr += dfs(i, j);
        }
        cout << "ansr = " << ansr << endl;
    }
    cout << ansr - ansl;
    return 0;
}