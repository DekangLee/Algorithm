// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-27 16:53:21
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-27 16:53:56
//  * @FilePath: \Algorithm\DynamicProgramming\bagProblem\multiBag1.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 20010;

// int dp[N], pre[N], q[N];
// int n, m;

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; ++i)
//     {
//         memcpy(pre, dp, sizeof(dp));
//         int v, w, s;
//         cin >> v >> w >> s;
//         for (int j = 0; j < v; ++j)
//         {
//             int head = 0, tail = -1;
//             for (int k = j; k <= m; k += v)
//             {
//                 if (head <= tail && k - s * v > q[head])
//                     ++head;

//                 while (head <= tail && pre[q[tail]] - (q[tail] - j) / v * w <= pre[k] - (k - j) / v * w)
//                     --tail;

//                 if (head <= tail)
//                     dp[k] = max(dp[k], pre[q[head]] + (k - q[head]) / v * w);

//                 q[++tail] = k;
//             }
//         }
//     }
//     cout << dp[m] << endl;
//     return 0;
// }