/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-03-02 16:35:28
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-03-04 15:25:58
 * @FilePath: \Algorithm\ShuffleAlgorithm\test02.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
int _and(int a, int b)
{
    if (a == 1 && b == 1)
        return 1;
    else
        return 0;
}
int _or(int a, int b)
{
    if (a == 1 || b == 1)
        return 1;
    else
        return 0;
}
int _ox(int a, int b)
{
    if (a == b)
        return 0;
    else
        return 1;
}
int ijadd(int &i, int &j)
{
    if (j < 3 - i)
        j++;
    else
    {
        i++;
        j = 0;
    }
    int count = 0;
    for (int row = 0; row < i; row++)
    {
        count += 4 - row;
    }
    return count + j + 1;
}
int ijsub(int &i, int &j)
{
    if (j == 0)
    {
        i--;
        j = 3 - i;
    }
    else
        j--;
    int count = 0;
    for (int row = 0; row < i; row++)
    {
        count += 4 - row;
    }
    return count + j + 1;
}
int _Array[5][5];
int (*_a[5][5])(int, int) = {nullptr};
int (*_c[3])(int, int) = {_and, _or, _ox};
int out(int _A[5][5], int (*_a[5][5])(int, int))
{
    for (int i = 0; i < 4; i++)
    {
        // cout << "i = " << i << endl;
        for (int j = 0; j < 4 - i; j++)
        {
            // cout << "j = " << j << endl;
            // cout << "_A[i][j] = " << _A[i][j] << " _A[i][j + 1] = " << _A[i][j + 1] << endl;
            // if (_a[i][j] == nullptr)
            // {
            //     cout << "nullptr: " << i << " " << j << endl;
            // }
            _A[i + 1][j] = _a[i][j](_A[i][j], _A[i][j + 1]);
            // cout << "--------" << endl;
        }
    }
    // cout << "_A[4][0] = " << _A[4][0] << endl;
    return _A[4][0];
}
int main()
{
    _Array[0][0] = 1;
    _Array[0][1] = 0;
    _Array[0][2] = 1;
    _Array[0][3] = 0;
    _Array[0][4] = 1;
    int count = 1;
    stack<int> _stack;
    int row = 0;
    int col = 0;
    int res = 0;
    int num = 0;
    _a[row][col] = _c[num];
    count = ijadd(row, col);
    // cout << "count = " << count << endl;
    _stack.push(num);
    while (count != 0)
    {
        // cout << "count = " << count << endl;
        // cout << "i = " << row << "  j = " << col << endl;
        // cout << "num = " << num << endl;
        if (num < 3)
        {
            _stack.push(num);
            _a[row][col] = _c[num];
            count = ijadd(row, col);
            num = 0;
            if (count == 11) // 到达终点
            {
                // cout << "Tcount = " << count << endl;
                if (out(_Array, _a) == 1)
                    res++;
                num = _stack.top();
                _stack.pop();
                count = ijsub(row, col);
                num++;
                // cout << "size1 = " << _stack.size() << endl;
            }
        }
        if (num == 3) // 意味着已经全部访问
        {
            // cout << "Tnum = " << num << endl;
            // cout << "size = " << _stack.size() << endl;
            // cout << "Tcount = " << count << endl;
            if (_stack.empty())
                break;
            num = _stack.top();
            _stack.pop();
            count = ijsub(row, col);
            num++;
        }
    }
    cout << res;
    return 0;
}