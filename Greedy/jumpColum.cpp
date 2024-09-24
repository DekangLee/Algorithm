// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-08-24 15:44:31
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-08-24 15:47:41
//  * @FilePath: \Algorithm\Greedy\jumpColum.cpp
//  * @Description: 
//  * 
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved. 
//  */
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// int max_H(const vector<int> &H, int pos, int n, int k, bool &ac)
// {
//     int max_pos = -1;
//     int max_h = 0;
//     int x = 1;
//     for (x = 1; x <= k && pos + x <= n; ++x)
//     {
//         if (H[pos + x] <= H[pos])
//         {
//             if (max_h < H[pos + x])
//             {
//                 max_pos = pos + x;
//                 max_h = H[pos + x];
//             }
//         }
//     }
//     if (pos + x == n && max_pos == -1)
//         ac = false;
//     return max_pos;
// }
// int main()
// {
//     int m;
//     vector<int> H;
//     H.reserve(10000);
//     cin >> m;
//     for (int i = 0; i < m; ++i)
//     {
//         int n, k;
//         bool isuse = false; // 超能力未被使用
//         bool ac = true;
//         cin >> n >> k;
//         for (int j = 1; j <= n; ++j)
//         {
//             int h;
//             cin >> h;
//             H[j] = h;
//         }
//         int pos = 1; // 当前位置
//         int next_pos = 0;
//         while (pos < n)
//         {
//             int max_pos = max_H(H, pos, n, k, ac); // 普通尝试
//             if (!ac)
//                 break;
//             if (max_pos == -1)
//             {
//                 // 必须使用超能力
//                 if (!isuse)
//                 {
//                     int max_h = 0;
//                     int max_pos = -1;
//                     for (int x = 1; x <= k && pos + x <= n; ++x)
//                     {
//                         if (max_h < H[pos + x])
//                         {
//                             max_h = H[pos + x];
//                             max_pos = pos + x;
//                         }
//                     }
//                     pos = max_pos;
//                     isuse = true;
//                 }
//                 else
//                 {
//                     ac = false;
//                     break;
//                 }
//             }
//             else
//             {
//                 pos = max_pos;
//             }
//         }
//         if (ac)
//         {
//             cout << "YES";
//         }
//         else
//         {
//             cout << "NO";
//         }
//     }
//     return 0;
// }
// // 64 位输出请用 printf("%lld")