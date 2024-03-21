/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-03-05 16:50:23
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-03-06 08:58:13
 * @FilePath: \Algorithm\ShuffleAlgorithm\test05.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isInf(vector<bool> &_A, int s1, int e1, int s2)
{
	for (int i = s1, j = s2; i <= e1; ++i, ++j)
	{
		if (_A[i] != _A[j])
			return false;
	}
	return true;
}
int maxNum(int a, int b)
{
	if (b % a == 0)
		return b;
	else
	{
		return (b / a + 1) * a;
	}
}
int main()
{
	int n;
	int res;
	vector<bool> A;
	vector<int> _arr;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		_arr.push_back(num);
	}
	sort(_arr.begin(), _arr.end());
	int start1 = _arr[0];
	int end1 = maxNum(start1, _arr.back()) - 1;
	int dist = end1 - start1 + 1;
	int start2 = end1 + 1;
	int end2 = start2 + dist - 1;
	int end3 = start1 + 4 * dist - 1;
	A.reserve(end3);
	A[0] = true;
	int count = 1;
	int flag = false;
	while (count != end3)
	{
		for (int j = 0; j < n; j++)
		{
			int num = count - _arr[j];
			if (num < 0)
			{
				A[count] = false;
				if (j == (n - 1))
					res++;
			}
			else if (num == 0)
			{
				A[count] = true;
				break;
			}                            
			else if (num > 0)
			{
				A[count] = false;
				if (A[num])
				{
					A[count] = true;
					break;
				}
				if (j == (n - 1))
					res++;
			}
		}
		if (count == end2)
		{
			if (flag = isInf(A, start1, end1, start2))
				break;
		}
		count++;
	}
	if (flag)
		cout << "INF";
	else
	{
		cout << res;
		// for (int i = 0; i < count; ++i)
		// {
		// 	if (!A[i])
		// 		cout << i << " ";
		// }
		// cout << endl;
	}
	return 0;
}