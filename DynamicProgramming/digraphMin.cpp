// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-14 16:29:48
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-14 20:51:40
//  * @FilePath: \Algorithm\DynamicProgramming\digraphMin.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// using namespace std;
// const int MAXN = 1e3;
// const int INF = 0x3fffffff;
// int G[MAXN][MAXN];
// int dp[MAXN];
// int n;
// int m;
// int source;
// int dest;
// bool isInEdge(int v)
// {
//     for (int i = 1; i <= n; ++i)
//     {
//         if (dp[i] == INF && G[i][v] != 0)
//             return false;
//     }
//     return true;
// }
// int main()
// {
//     cin >> n >> m;
//     cin >> source >> dest;
//     for (int i = 1; i <= m; ++i)
//     {
//         int v1, v2, e;
//         cin >> v1 >> v2 >> e;
//         G[v1][v2] = e;
//     }
//     cout << "-----" << endl;
//     for (int i = 1; i <= n; ++i)
//     {
//         if (i != source)
//             dp[i] = INF;
//     }
//     while (true)
//     {
//         int v;
//         for (int i = 1; i <= n; ++i)
//         {
//             if (dp[i] == INF && isInEdge(i))
//             {
//                 v = i;
//                 break;
//             }
//         }
//         cout << "v = " << v << endl;
//         int minDist = INF;
//         for (int i = 1; i <= n; ++i)
//         {
//             if (G[i][v] != 0 && minDist > (dp[i] + G[i][v]))
//                 minDist = dp[i] + G[i][v];
//         }
//         dp[v] = minDist;
//         if (v == dest)
//             break;
//     }
//     cout << dp[dest] << endl;
//     return 0;
// }