/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-04-03 20:04:30
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-04-07 10:32:01
 * @FilePath: \Algorithm\DynamicProgramming\digitalDP\luoguP2657test.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
LL dp[20][10]; // dp[i][j] 表示第i位数值为j的windy数的个数
void init()
{
    // 将所有的windy数都求出来存放在数组dp里面
    for (int i = 0; i <= 9; ++i)
        dp[1][i] = 1;
    for (int i = 2; i <= 10; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            for (int k = 0; k <= 9; ++k)
            {
                if (abs(j - k) >= 2)
                    dp[i][j] += dp[i - 1][k];
            }
        }
    }
}
LL work(int x) // 求出<=x的windy数
{
    // 这里先将windy数拆分存放在数组num里面
    int len = 0; // len为x的长度
    int num[11];
    while (x)
    {
        num[++len] = x % 10;
        x /= 10;
    }
    LL ans = 0;
    // 这里可以考虑假如x是一位n位数，其小于n位的所有数字都可以通过dp[i][j]来求出
    for (int i = 1; i < len; ++i)
    {
        for (int j = 1; j <= 9; ++j) // 枚举第二维的时候要注意从1开始枚举，否则存在前导为零的数字，不符合题意
        {
            ans += dp[i][j];
        }
    }
    // 最后将位数与x相等的windy数加入ans，这里需要注意使用num数组来枚举
    for (int i = 1; i < num[len]; ++i)
    {
        ans += dp[len][i];
    }
    // 如果要枚举的最后一位与x相同
    for (int i = len - 1; i >= 1; --i)
    {
        for (int j = 0; j < num[i]; ++j)
        {
            if (abs(j - num[i + 1]) >= 2)
                ans += dp[i][j];
        }
        if (abs(num[i] - num[i + 1]) < 2)
            break;
        if (i == 1)
            ans++;
    }
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    init();
    cout << work(b) - work(a - 1);
    return 0;
}