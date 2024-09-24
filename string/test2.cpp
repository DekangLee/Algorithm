/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-08-18 19:51:24
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-08-26 11:05:52
 * @FilePath: \Algorithm\string\test2.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-08-18 19:51:24
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-08-18 20:01:11
//  * @FilePath: \Algorithm\string\test2.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include<iostream>
// #include<unordered_map>

// using namespace std;
// const int N = 16;
// int result[N]; // 计算最终结果
// unordered_map<int,int> res;
// int main()
// {
//     int T;
//     cin >> T;
//     for(int i = 0; i < T; ++i)
//     {
//         int number;
//         cin >> number;
//         res[number]++;
//     }
//     cin >> T;
//     for(int i = 0; i < T; ++i)
//     {
//         int number;
//         cin >> number;
//         res[number]--;
//     }
//     for(auto a : res)
//     {
//         result[a.second]++;
//     }
//     for(int i = 1 ;i < N; ++i)
//     {
//         cout <<result[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }
// #include <iostream>
// #include <queue>
// using namespace std;
// const int M = 105;
// const int N = 1005;
// int _hash[M];
// queue<int> q;
// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     int res = 0;
//     for (int i = 1; i <= n; ++i)
//     {
//         int a;
//         cin >> a;
//         if (_hash[a] == 0) // 需要查字典
//         {
//             res++;
//             if (q.size() == m - 1)
//             {
//                 int b = q.front();
//                 _hash[b] = 0;
//                 q.pop();
//             }
//             q.push(a);
//             _hash[a] = 1;
//         }
//     }
//     cout << res;
//     return 0;
// }