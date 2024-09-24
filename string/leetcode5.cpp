// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-04-16 19:52:25
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-04-18 19:44:50
//  * @FilePath: \Algorithm\string\leetcode5.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// // 求最长回文子串
// // #include <iostream>
// // using namespace std;
// // bool check(string &s) // 判断字符串是否为回文子串
// // {
// //     int len = s.size() - 1;
// //     int end = len / 2 + 1;
// //     for (int i = 0; i < end; ++i)
// //     {
// //         if (s[i] != s[len - i])
// //             return false;
// //     }
// //     return true;
// // }
// // int main()
// // {
// //     string str;
// //     string res;
// //     cin >> str;
// //     int m = 0;
// //     for(int i = 0; i < str.size(); ++i)
// //         for(int j = i; j < str.size(); ++j)
// //         {
// //             string s(str.begin() + i, str.begin() + j + 1);
// //             if(check(s) && m < s.size())
// //             {
// //                 m = s.size();
// //                 res = s;
// //             }
// //         }
// //     cout << res;
// //     return 0;
// // }

// // 以上解法为暴力解法，可以通过动态规划来优化该问题

// // #include <iostream>
// // #include <string>
// // using namespace std;
// // const int N = 10005;
// // bool dp[N][N]; // dp[i][j] 表示从位置i到位置j是否为回文子串
// // int main()
// // {
// //     string str;
// //     string res;
// //     int m = 1;
// //     cin >> str;
// //     for (int i = 0; i < str.size(); ++i)
// //     {
// //         dp[i][i] = true;
// //         dp[i + 1][i] = true;
// //     }
// //     for (int len = 2; len <= str.size(); ++len)
// //     {
// //         for (int i = 0; i <= str.size() - len; ++i)
// //         {
// //             int j = i + len - 1;
// //             if (str[i] == str[j])
// //             {
// //                 dp[i][j] = dp[i + 1][j - 1];
// //                 if (dp[i][j])
// //                     res.assign(str.begin() + i, str.begin() + j + 1);
// //             }
// //             else
// //                 dp[i][j] = false;
// //         }
// //     }
// //     cout << res;
// //     return 0;
// // }

// // 使用动态规划的复杂度仍然有n^2，下面考虑使用hash与二分查找的方法降低复杂度
// // #include <iostream>
// // #include <string.h>
// // #define rep(a, b, c) for (int a = b; a <= c; ++a)
// // using namespace std;
// // typedef unsigned long long uLL;
// // const int N = 2000010;
// // const int P = 131;
// // char s[N];
// // uLL h1[N], h2[N], p[N];
// // inline uLL get(uLL *h, uLL l, uLL r)
// // {
// //     return h[r] - h[l - 1] * p[r - l + 1];
// // }
// // int main()
// // {
// //     int cnt = 0;
// //     s[0] = '1';
// //     while (scanf("%s", s + 1) && strcmp(s + 1, "END"))
// //     {
// //         // cout << s << endl;
// //         int len = strlen(s + 1) * 2;
// //         for (int i = len; i > 0; i -= 2)
// //         {
// //             s[i] = s[i / 2];
// //             s[i - 1] = 'z' + 1;
// //         }
// //         p[0] = 1;
// //         for (int i = 1, j = len; i <= len; ++i, --j)
// //         {
// //             h1[i] = h1[i - 1] * P + s[i] - 'a' + 1;
// //             h2[i] = h2[i - 1] * P + s[j] - 'a' + 1;
// //             p[i] = p[i - 1] * P;
// //         }
// //         uLL ans = 0;
// //         for (int i = 1; i <= len; i++) // i是需要遍历扩展后字符串的位置，并且以该位置向两边伸展
// //         {
// //             uLL l = 0, r = min(i - 1, len - i);
// //             // l 是以i为中心的左半部分的回文匹配的个数，r是可以最大匹配的个数
// //             cout << "i = " << i << "------" << endl;
// //             while (l < r)
// //             {
// //                 uLL mid = (l + r + 1) / 2;
// //                 cout << "l = " << l << " r = " << r << " mid = " << mid << endl;
// //                 if (get(h1, i - mid, i - 1) != get(h2, len - (i + mid) + 1, len - i))
// //                 // 如果未匹配上，则mid左边的均不能再匹配，最大匹配的长度应该变小继续查找是否能匹配
// //                     r = mid - 1;
// //                 else
// //                 // 如果匹配成功则mid左边的均可以匹配成功，直接将l移向mid继续试探能否匹配
// //                     l = mid;
// //             }
// //             if (s[i - l] <= 'z')
// //                 ans = max(ans, l + 1);
// //             else
// //                 ans = max(ans, l);
// //             cout << "ans = " << ans << endl;
// //         }
// //         printf("Case %d: %d\n", ++cnt, ans);
// //     }
// //     return 0;
// // }

// // 继续优化上述代码，主要考虑以i为中心的字符串最大回文子串是ans，如果后面的回文子串长度小于ans就不必再继续二分更新了

// #include <iostream>
// #include <string.h>
// using namespace std;
// typedef unsigned long long uLL;
// const int N = 2000010;
// char s[N];
// uLL h1[N], h2[N], p[N];
// const int P = 131;
// inline uLL get(uLL *h, int l, int r)
// {
//     return h[r] - h[l - 1] * p[r - l + 1];
// }
// int cnt = 0;
// int main()
// {
//     while (scanf("%s", s + 1) && strcmp(s + 1, "END"))
//     {
//         int len = 2 * strlen(s + 1);
//         for (int i = len; i; i -= 2)
//         {
//             s[i] = s[i / 2];
//             s[i - 1] = 'z' + 1;
//         }
//         s[++len] = 'z' + 1;
//         printf("%s\n", s + 1);
//         p[0] = 1;
//         int ans = 0;
//         for (int i = 1, j = len; i <= len; ++i, --j)
//         {
//             h1[i] = h1[i - 1] * P + s[i] - 'a' + 1;
//             h2[i] = h2[i - 1] * P + s[j] - 'a' + 1;
//             p[i] = p[i - 1] * P;
//         }
//         for (int i = 1; i <= len; ++i)
//         {
//             int l = 0;
//             int r = min(i - 1, len - i);
//             cout << "i = " << i << "-------" << endl;
//             while (l < r && r > ans)
//             {
//                 int mid = (l + r + 1) >> 1;
//                 cout << "l = " << l << " r = " << r << " mid = " << mid << endl;
//                 if (get(h1, i - mid, i) != get(h2, len - i - mid + 1, len - i + 1))
//                     r = mid - 1;
//                 else
//                     l = mid;
//             }
//             ans = max(ans, l);
//         }
//         printf("Case %d: %d\n", ++cnt, ans);
//     }
//     return 0;
// }