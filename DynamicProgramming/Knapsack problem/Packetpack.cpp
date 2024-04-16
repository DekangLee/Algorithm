// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-28 20:27:50
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-28 20:49:05
//  * @FilePath: \Algorithm\DynamicProgramming\Knapsack problem\Packetpack.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// using namespace std;
// const int N = 10005;
// struct vw
// {
//     int v;
//     int w;
// };
// int dp[N];
// int g[N];
// vw group[N][N];
// int V;
// int n;
// int main()
// {
//     cin >> n >> V;
//     for (int i = 1; i <= n; ++i)
//     {
//         int num;
//         cin >> num;
//         g[i] = num;
//         for (int j = 1; j <= num; ++j)
//         {
//             int v, w;
//             cin >> v >> w;
//             group[i][j].v = v;
//             group[i][j].w = w;
//         }
//     }
//     for (int i = 1; i <= n; ++i)            // 遍历不同的组别
//         for (int j = V; j >= 0; --j)        // 遍历所有的体积
//             for (int k = 1; k <= g[i]; ++k) // 遍历该组别的所有物品
//             {
//                 if (j >= group[i][k].v)
//                     dp[j] = max(dp[j], dp[j - group[i][k].v] + group[i][k].w);
//             }
//     cout << dp[V];
//     return 0;
// }