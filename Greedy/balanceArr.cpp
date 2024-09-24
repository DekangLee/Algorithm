/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-08-24 16:41:26
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-08-24 16:45:48
 * @FilePath: \Algorithm\Greedy\balanceArr.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <string>
using namespace std;
// 使用二维前缀和
#include <vector>
vector<vector<int>> sum(110, vector<int>(110, 0));
int main()
{
    int row;
    cin >> row;
    for (int i = 1; i <= row; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j <= str.size(); ++j)
        {
            int col = j + 1;
            int x = row - 1;
            int y = col - 1;
            int sum1 = sum[x][y];
            int sum2 = sum[row][y] - sum1;
            int sum3 = sum[x][col] - sum1;
            int num = 1;
            if(str[j] =='0')
                num = -1;
            sum[i][col] = num + sum1 + sum2 + sum3;
        }
    }
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= row; ++j)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= row; ++i)
    {
        if ((i * i) % 2 == 0)
        {
            int res = 0;
            int row_start = 1;
            while (row_start + i - 1 <= row)
            {
                int col_start = 1;
                while (col_start + i - 1 <= row)
                {
                    int p1 = row_start + i - 1;
                    int p2 = col_start + i - 1;
                    int t = sum[p1][p2] - sum[p1][col_start - 1] - sum[row_start - 1][p2] +
                            sum[row_start - 1][col_start - 1];
                    if (t == 0)
                        res++;
                    col_start += 1;
                }
                row_start += 1;
            }
            cout << res << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")