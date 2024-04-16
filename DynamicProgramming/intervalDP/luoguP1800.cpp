// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-04-07 20:10:14
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-04-07 21:08:48
//  * @FilePath: \Algorithm\DynamicProgramming\intervalDP\luoguP1800.cpp
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
// int dfsMax(int l, int r)
// {
//     if (l == r)
//         return 0;
//     if (dpMAX[l][r])
//         return dpMAX[l][r];
//     int res = 0x80000001;
//     for (int k = l; k < r; ++k)
//     {
//         res = max(res, dfsMax(l, k) + dfsMax(k + 1, r) + sum[r] - sum[l - 1]);
//     }
//     dpMAX[l][r] = res;
//     return res;
// }
// int dfsMin(int l, int r)
// {
//     if (l == r)
//         return 0;
//     if (dpMIN[l][r])
//         return dpMIN[l][r];
//     int res = 0x7fffffff;
//     for (int k = l; k < r; ++k)
//     {
//         res = min(res, dfsMin(l, k) + dfsMin(k + 1, r) + sum[r] - sum[l - 1]);
//     }
//     dpMIN[l][r] = res;
//     return res;
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
//     int MIN = 0x7fffffff;
//     for (int i = 1; i <= n - 1; ++i)
//     {
//         MIN = min(MIN, dfsMin(i, i + n - 1));
//     }
//     int MAX = 0x80000001;
//     for (int i = 1; i <= n - 1; ++i)
//     {
//         MAX = max(MAX, dfsMax(i, i + n - 1));
//     }
//     cout << MIN << endl;
//     cout << MAX << endl;
//     return 0;
// }