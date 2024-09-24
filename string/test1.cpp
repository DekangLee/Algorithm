// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-08-18 19:40:07
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-08-18 19:45:29
//  * @FilePath: \Algorithm\string\test1.cpp
//  * @Description: 
//  * 
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved. 
//  */
// #include <iostream>
// #include <string.h>
// using namespace std;
// const int N = 1000005;
// int main()
// {
//     char data[N];
//     memset(data, 0, sizeof(data));
//     cin >> data;
//     int len = sizeof(data);
//     int op = 0;
//     for (int i = 0; i < len-1; ++i)
//     {
//         if (data[i] == '0' && data[i + 1] == '1')
//         {
//             data[i] = '1';
//             data[i+1] = '0';
//             ++op;
//         }
//     }
//     cout << op;
//     return 0;
// }