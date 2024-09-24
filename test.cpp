// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-27 09:14:53
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-08-26 21:57:21
//  * @FilePath: \Algorithm\test.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <cmath>

// using namespace std;
// class Solution
// {
// public:
//     int monotoneIncreasingDigits(int n)
//     {
//         if (n / 10 == 0)
//             return n;
//         vector<int> data;
//         stack<int> s_r;
//         s_r.push(0);
//         int sum = 0;
//         int s = n;
//         while (n)
//         {
//             data.push_back(n % 10);
//             n /= 10;
//         }
//         int cnum = 0;
//         int prenum = 0;
//         for (int i = data.size() - 1; i >= 0; --i)
//         {
//             prenum = cnum;
//             if (data[i] > prenum)
//             {
//                 s_r.push(data[i]);
//                 cnum = data[i];
//                 sum += pow(10, i) * cnum;
//             }
//             else
//             {
//                 cnum = 9;
//                 s_r.push(cnum);
//                 sum += pow(10, i) * cnum;
//             }
//         }
//         int pos = 1;
//         while (!s_r.empty())
//         {
//             if (cnum >= prenum)
//             {
//                 if (pos != 1)
//                 {
//                     cnum = 9;
//                     s_r.push(cnum);
//                     --pos;
//                     sum += pow(10, pos - 1) * cnum;
//                     prenum = cnum;
//                 }
//                 else
//                 {
//                     if (sum <= s)
//                         return sum;
//                     else
//                     {
//                         cnum = s_r.top();
//                         s_r.pop();
//                         prenum = s_r.top();
//                         sum -= cnum;
//                         --cnum;
//                         s_r.push(cnum);
//                         sum += cnum;
//                     }
//                 }
//             }
//             if (cnum < prenum)
//             {
//                 // 回溯
//                 cnum = s_r.top();
//                 sum -= pow(10, pos - 1) * cnum;
//                 s_r.pop();
//                 ++pos;

//                 cnum = s_r.top();
//                 sum -= pow(10, pos - 1) * cnum;
//                 --cnum;
//                 s_r.pop();
//                 prenum = s_r.top();
//                 s_r.push(cnum);
//                 sum += pow(10, pos - 1) * cnum;
//             }
//         }
//         return -1;
//     }
// };
// int main()
// {
//     Solution s;
//     cout << s.monotoneIncreasingDigits(1234) << endl;
//     return 0;
// }

#include <iostream>
#include <string.h>
#include <unordered_set>
using namespace std;
const int N = 3e3 + 10;
unordered_set<int> res[N];
int pre_data[N];
int cur_data[N];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        res[i].insert(i);
        pre_data[i] = i;
    }
    for (int i = 1; i <= q; ++i)
    {
        int l, r;
        cin >> l >> r;
        int len1 = n - r;
        int len2 = r - l + 1;
        for (int j = 1; j < l; ++j)
            cur_data[j] = j;
        for (int j = l; j <= r; ++j)
            cur_data[j] = j + len1;
        for (int j = r + 1; j <= n; ++j)
            cur_data[j] = j - len2;
        for (int j = 1; j <= n; ++j)
        {
            res[j].insert(cur_data[pre_data[j]]);
        }
        for (int j = 1; j <= n; ++j)
            pre_data[j] = cur_data[pre_data[j]];
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << res[i].size() << " ";
    }
    return 0;
}
