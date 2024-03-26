// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-26 14:42:34
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-26 15:36:53
//  * @FilePath: \Algorithm\DynamicProgramming\01bag.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// using namespace std;
// int c[1005];
// int w[1005];
// int n;
// int v;
// // int dp[1005][1005];
// int dp[1005];
// int main()
// {
//     cin >> n >> v;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> c[i] >> w[i];
//     }
//     // for (int i = 1; i <= n; ++i)
//     // {
//     //     for (int j = 1; j <= v; ++j)
//     //     {
//     //         if (c[i] <= j)
//     //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + w[i]);
//     //         else
//     //             dp[i][j] = dp[i - 1][j];
//     //     }
//     // }
//     // cout << dp[n][v];
//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = v; j >= 0; --j)
//         {
//             if (j >= c[i])
//                 dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
//         }
//     }
//     cout << dp[v];
//     return 0;
// }