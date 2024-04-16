/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-04-01 20:34:08
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-04-02 09:10:43
 * @FilePath: \Algorithm\SegmentTree\main.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include "segmentTree.hpp"
using namespace std;
int main()
{
    segmentTree<int> tree1;
    int arr[] = {1, 3, 7, 2, 9, 5, 10};
    tree1.initialize(arr, 0, 6);
    tree1.outputTree();
    tree1.outputLazy();
    tree1.intervalAlter(3, 5, 1);
    tree1.outputTree();
    tree1.outputArr();
    tree1.outputLazy();
    tree1.intervalAlter(4, 7, -2);
    cout << "----------" << endl;
    tree1.outputTree();
    tree1.outputArr();
    tree1.outputLazy();
    tree1.intervalAlter(2,4,2);
    cout << "----------" << endl;
    tree1.outputTree();
    tree1.outputArr();
    tree1.outputLazy();
    cout<<tree1.intervalQuery(4,5)<<endl;
    cout << "----------" << endl;
    tree1.outputTree();
    tree1.outputArr();
    tree1.outputLazy();
    return 0;
}