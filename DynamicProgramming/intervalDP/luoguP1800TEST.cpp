// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-04-07 20:10:14
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-04-08 09:03:36
//  * @FilePath: \Algorithm\DynamicProgramming\intervalDP\luoguP1800TEST.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// using namespace std;
// int a[105];
// int sum[205]; // 前缀和，给定区间在常数时间内求出区间和
// int n;
// int dpMAX[205][205]; // 记忆化搜索，记录已经解决的区间最大值
// int dpMIN[205][205]; // 记忆化搜索，记录已经解决的区间最小值
// void dfsMax()
// {
//     for (int i = 1; i <= n - 1; ++i)         // l与r相差的个数
//         for (int j = 1; j <= 2 * n - i; ++j) // l的起始位置
//         {
//             int res = 0x80000001;
//             for (int k = j; k < j + i; ++k)
//             {
//                 res = max(res, dpMAX[j][k] + dpMAX[k + 1][j + i] + sum[j + i] - sum[j - 1]);
//             }
//             dpMAX[j][j + i] = res;
//         }
// }
// void dfsMin()
// {
//     for (int i = 1; i <= n - 1; ++i)         // l与r相差的个数
//         for (int j = 1; j <= 2 * n - i; ++j) // l的起始位置
//         {
//             int res = 0x7fffffff;
//             for (int k = j; k < j + i; ++k)
//             {
//                 res = min(res, dpMIN[j][k] + dpMIN[k + 1][j + i] + sum[j + i] - sum[j - 1]);
//             }
//             dpMIN[j][j + i] = res;
//         }
// }
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; ++i)
//     {
//         int t;
//         cin >> t;
//         a[i] = t;
//         sum[i] = sum[i - 1] + t;
//     }
//     // 这里由于石子是成环的，可以考虑将石子堆展开展开后的长度是2*n
//     for (int i = n + 1; i <= 2 * n; ++i)
//     {
//         sum[i] = sum[i - 1] + a[i - n];
//     }
//     dfsMax();
//     dfsMin();
//     int MIN = 0x7fffffff;
//     int MAX = 0x80000001;
//     for (int i = 1; i < n; ++i)
//     {
//         MIN = min(MIN, dpMIN[i][n + i - 1]);
//         MAX = max(MAX, dpMAX[i][n + i - 1]);
//     }
//     cout << MIN << endl;
//     cout << MAX << endl;
//     return 0;
// }