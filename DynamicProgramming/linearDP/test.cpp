// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-08-12 20:01:38
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-08-16 09:33:19
//  * @FilePath: \Algorithm\DynamicProgramming\linearDP\test.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include <stack>
// #include <vector>
// #include <cmath>

// using namespace std;
// class Solution
// {
// public:
//     stack<pair<int, int>> order_stack;
//     vector<int> dailyTemperatures(vector<int> &temperatures)
//     {
//         vector<int> res(temperatures.size());
//         for (int i = temperatures.size() - 1; i >= 0; --i)
//         {
//             if (order_stack.empty())
//             {
//                 res[i] = 0;
//                 order_stack.push(make_pair(temperatures[i], i));
//             }
//             else
//             {
//                 int count = 0;
//                 while (!order_stack.empty())
//                 {
//                     count++;
//                     auto top = order_stack.top();
//                     if (top.first > temperatures[i])
//                     {
//                         res[i] = top.second - i;
//                         order_stack.push(make_pair(temperatures[i], i));
//                         break;
//                     }
//                     else
//                     {
//                         order_stack.pop();
//                     }
//                 }
//                 if (order_stack.empty())
//                 {
//                     res[i] = 0;
//                     order_stack.push(make_pair(temperatures[i], i));
//                 }
//             }
//         }
//         return res;
//     };
// };
// int fun(int x)
// {
//     int countx = 0;
//     while (x)
//     {
//         countx++;
//         x = x & (x - 1);
//     }
//     return countx;
// }
// int main()
// {
//     // vector<int> b = {73, 74, 75, 71, 69, 72, 76, 73};
//     // stack<int> a;
//     // cout << b.size() << endl;
//     // cout << a.empty() << endl;
//     // Solution mySlu;
//     // vector<int> res = mySlu.dailyTemperatures(b);
//     // for (auto it : res)
//     // {
//     //     cout << it << " ";
//     // }
//     // cout << fun(500) << endl;
//     // int n, m;
//     // while (cin >> n >> m)
//     // {
//     //     double sum = 0;
//     //     double res = n;
//     //     cout << "n = " << n << " m = " << m << endl;
//     //     for (int i = 0; i < m; ++i)
//     //     {
//     //         sum += res;

//     //         res = sqrt(res);
//     //     }

//     // }
//     return 0;
// }