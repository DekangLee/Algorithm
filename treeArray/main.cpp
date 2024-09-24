/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-03-12 21:15:56
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-08-24 21:53:33
 * @FilePath: \Algorithm\treeArray\main.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <cstring>
#include "treeArray.hpp"
using namespace std;
int main()
{
    int _arr[] = {0, 1, 4, 2, 8, 5, 3, 6, 10, 3, 2, 9};

    treeArray<int> t1;
    t1.initilize(_arr, sizeof(_arr) / sizeof(int) - 1);
    cout << "initilize:";
    t1.output();

    t1.alter(4, -1);
    cout << "alter:";
    t1.output();
    cout << t1.intervalQuery(4, 5) << endl;
    // t1.alter(1, -1);
    t1.output();
    // cout<< (11&(-11)) << endl;

    return 0;
}