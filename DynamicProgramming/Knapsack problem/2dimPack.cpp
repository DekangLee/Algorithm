// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-28 20:15:19
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-28 20:25:59
//  * @FilePath: \Algorithm\DynamicProgramming\Knapsack problem\2dimPack.cpp
//  * @Description: 
//  * 
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved. 
//  */
// #include <iostream>
// using namespace std;
// const int N = 1005;
// int dp[N][N];
// int V;
// int M;
// int n;
// int main()
// {
//     cin >> n >> V >> M;
//     for (int i = 1; i <= n; ++i) // 遍历物品的个数
//     {
//         int v, m, w;
//         cin >> v >> m >> w;
//         for (int j = V; j >= v; --j) // 遍历所有的体积
//         {
//             for (int k = M; k >= m; --k) // 遍历所有的重量
//             {
//                 dp[j][k] = max(dp[j][k], dp[j - v][k - m] + w);
//             }
//         }
//     }
//     cout << dp[V][M];
//     return 0;
// }