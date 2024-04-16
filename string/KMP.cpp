// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-04-12 20:45:03
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-04-15 14:49:18
//  * @FilePath: \Algorithm\string\KMP.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include <string.h>
// using namespace std;
// char s[1024];
// char p[1024];
// int theNext[1024];
// int n;
// void initNext()
// {
//     n = strlen(p);
//     theNext[0] = 0;
//     int j = 0;
//     for (int i = 1; i < n; ++i)
//     {
//         while (j && p[j] != p[i])
//             j = theNext[j - 1];
//         if (p[j] == p[i])
//             ++j;
//         theNext[i] = j;
//         // cout << "j = " << j << endl;
//     }
// }
// int substr(char *s, char *p)
// {
//     int lens = strlen(s);
//     int lenp = strlen(p);
//     int i = 0;
//     int j = 0;
//     int pos = 0;
//     while (j < lenp && pos <= lens - lenp)
//     {
//         if (s[i] == p[j])
//         {
//             ++i;
//             ++j;
//         }
//         else
//         {
//             if (j == 0)
//                 ++i;
//             else
//             {
//                 j = theNext[j - 1];
//                 pos = i - j;
//             }
//         }
//         // cout <<"j = " << j << " i = " << i << endl;
//         if (j == lenp)
//             return pos;
//     }
//     return -1;
// }
// void printInfo()
// {
//     for(int i = 0; i < strlen(p); ++i)
//         cout << theNext[i] << " ";
//     cout << endl;
// }
// int main()
// {
//     cin >> s >> p;
//     initNext();
//     int j = 0;
//     int i = 0;
//     cout << "s = " << s << " p = " << p << endl;
//     printInfo();
//     cout << substr(s, p);
//     return 0;
// }