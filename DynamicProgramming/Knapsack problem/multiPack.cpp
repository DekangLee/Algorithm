// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-26 14:42:34
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-28 09:36:34
//  * @FilePath: \Algorithm\DynamicProgramming\bagProblem\multiBag.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// using namespace std;
// const int N = 10000;
// int c[N];
// int w[N];
// int s[N];
// int n;
// int v;
// int dp[N];
// struct PV
// {
//     int pos;
//     int value;
//     PV()
//     {
//         pos = 0;
//         value = 0;
//     }
// };
// // int dp[N][N];
// // void print();
// int main()
// {
//     cin >> n >> v;
//     // int cnt = 0;
//     // for (int i = 1; i <= n; ++i)
//     // {
//     //     int _c;
//     //     int _w;
//     //     int _s;
//     //     cin >> _c >> _w >> _s;
//     //     int a = 1;
//     //     while (a <= _s)
//     //     {
//     //         c[++cnt] = a * _c;
//     //         w[cnt] = a * _w;
//     //         _s -= a;
//     //         a *= 2;
//     //     }
//     //     if (_s != 0)
//     //     {
//     //         c[++cnt] = _s * _c;
//     //         w[cnt] = _s * _w;
//     //     }
//     // }
//     // for (int i = 1; i <= n; ++i)
//     // {
//     //     for (int j = 1; j <= v; ++j)
//     //     {
//     //         dp[i][j] = dp[i - 1][j];
//     //         for (int k = 1; k <= s[i]; ++k)
//     //         {
//     //             if (j >= k * c[i])
//     //                 dp[i][j] = max(dp[i][j], dp[i-1][j - k * c[i]] + k * w[i]);
//     //         }
//     //     }
//     // }
//     // cout << dp[n][v];
//     // for (int i = 1; i <= n; ++i)
//     // {
//     //     for (int j = v; j >= 0; --j)
//     //     {
//     //         for (int k = 0; k <= s[i] && k * c[i] <= j; ++k)
//     //         {
//     //             dp[j] = max(dp[j], dp[j - k * c[i]] + k * w[i]);
//     //         }
//     //     }
//     // }
//     // cout << dp[v];
//     // 可以对多重背包问题采用二进制优化
//     // for (int i = 1; i <= cnt; ++i)
//     // {
//     //     for (int j = v; j >= c[i]; --j)
//     //     {
//     //         dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
//     //     }
//     // }
//     // cout << dp[v];
//     // 多重背包问题的单调队列优化
//     for (int i = 1; i <= n; ++i)
//         cin >> c[i] >> w[i] >> s[i];
//     PV que[N];
//     int head, tail;
//     for (int i = 1; i <= n; i++) // 枚举物品种类
//     {
//         s[i] = s[i] > (v / c[i]) ? (v / c[i]) : s[i]; // 求lim
//         for (int d = 0; d < c[i]; d++)                // 枚举余数
//         {
//             head = tail = 0; // 队列初始化
//             for (int k = 0; k <= (v - d) / c[i]; k++)
//             {
//                 int x = k;
//                 int y = dp[k * c[i] + d] - k * w[i];
//                 while (head < tail && que[head].pos < k - s[i])
//                     head++; // 限制长度
//                 while (head < tail && que[tail - 1].value <= y)
//                     tail--;
//                 que[tail].value = y, que[tail].pos = x;
//                 tail++;
//                 dp[k * c[i] + d] = que[head].value + k * w[i];
//                 // 加上k*w[i]的原因:
//                 // 我们的单调队列维护的是前i-1种的状态最大值.
//                 // 因此这里加上k*w[i].
//             }
//         }
//     }
//     cout << dp[v];
//     return 0;
// }
