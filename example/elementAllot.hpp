#ifndef __ELEMEMTALLOTH__
#define __ELEMEMTALLOTH__
#include <iostream>
using namespace std;
#include<cmath>
// 将n个不相同的元素分配至m个相同的组，且不允许出现空组
long long elementAllot(int n, int m);       // 递归实现, 导致时间复杂度非常高
long long elemAllotIteration(int n, int m); // 迭代实现，时间复杂度为O(m*n)
int FibArray(int n,int first,int second);
// n为元素的种类数，m为所有取得的元素总数
double Solution(int n, int m);
// 杨辉三角递归法求组合数C(n,m) , 时间复杂度较高2^n
int combRecursion(int n,int m);
// 杨辉三角迭代求解组合数C(n,m) , 时间复杂度为n^2
int combIteration(int n,int m);
#endif