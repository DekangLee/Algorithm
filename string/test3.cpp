// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-08-19 20:25:07
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-08-20 09:04:48
//  * @FilePath: \Algorithm\string\test3.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include <string.h>

// using namespace std;
// char num1[1024];
// char num2[1024];
// char res[1024];
// void resve(char *input, int len)
// {
//     int mid = len / 2;
//     for (int i = 0; i < mid; ++i)
//     {
//         char temp = input[i];
//         input[i] = input[len - i - 1];
//         input[len - i - 1] = temp;
//     }
// }

// void alig(char *input, int max, int min)
// {
//     memmove(input + max - min, input, min);
//     for (int i = 0; i < max - min; ++i)
//     {
//         input[i] = '0';
//     }
// }
// void cacul(char *_num1, char *_num2, char *_res, int len, int &pos) // 同等长度
// {
//     bool flag = false;

//     for (int i = len - 1; i >= 0; --i)
//     {
//         int int_num1 = _num1[i] - '0'; // 当前位置的数
//         int int_num2 = _num2[i] - '0';
//         if (flag) // 存在借位
//         {
//             int_num1 -= 1;
//         }
//         if (int_num1 < int_num2) // 发生借位
//         {
//             flag = true;
//             int_num1 += 10;
//             int temp = int_num1 - int_num2;
//             res[pos++] = static_cast<char>(temp + '0');
//         }
//         else // 无借位情况
//         {
//             flag = false;
//             int temp = int_num1 - int_num2;
//             res[pos++] = static_cast<char>(temp + '0');
//         }
//     }
// }
// int main()
// {
//     memset(num1, 0, sizeof(num1));
//     memset(num2, 0, sizeof(num2));
//     cin >> num1 >> num2;
//     int len1 = strlen(num1);
//     int len2 = strlen(num2);
//     bool sig_flag = false;
//     bool zero_flag = true;
//     int pos = 0;
//     if (len1 > len2)
//     {
//         // 结果为正
//         alig(num2, len1, len2);
//         cout << num2 << endl;
//         cacul(num1, num2, res, len1, pos);

//         for (int i = pos; i >= 0; --i)
//         {
//             if (res[i] != '0')
//                 cout << res[i];
//         }
//         cout << endl;
//     }
//     else if (len2 > len1)
//     {
//         // 结果为负
//         alig(num1, len2, len1);
//         cacul(num2, num1, res, len2, pos);
//         cout << "-";
//         for (int i = pos; i >= 0; --i)
//         {
//             if (res[i] != '0')
//                 cout << res[i];
//         }
//         cout << endl;
//     }
//     else
//     {
//         // 未定，但最多借一位
//         char *_max;
//         char *_min;
//         int i = 0;
//         for (; i < len1; ++i)
//         {
//             if (num1[i] < num2[i])
//             {
//                 _max = num2;
//                 _min = num1;
//                 sig_flag = true;
//                 break;
//             }
//             else if (num1[i] > num2[i])
//             {
//                 _max = num1;
//                 _min = num2;
//                 sig_flag = false;
//                 break;
//             }
//         }
//         if (i == len1)
//             cout << "0" << endl;
//         else
//         {
//             cacul(_max, _min, res, len1, pos);
//             if (sig_flag)
//                 cout << "-";
//             for (int i = pos; i >= 0; --i)
//             {
//                 cout << res[i];
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }