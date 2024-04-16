/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-04-15 14:55:11
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-04-16 15:30:41
 * @FilePath: \Algorithm\string\luoguP3375.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <string.h>
using namespace std;
const int N = 1e6 + 10;
char s1[N];
char s2[N];
int theNext[N];
void initNext()
{
    int lens2 = strlen(s2);
    int j = 0;
    theNext[0] = 0;
    for (int i = 1; i < lens2; ++i)
    {
        while (j && s2[j] != s2[i])
            j = theNext[j - 1];
        if (s2[j] == s2[i])
            ++j;
        theNext[i] = j;
    }
}
int main()
{
    cin >> s1 >> s2;
    initNext();
    int pos = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = 0;
    int j = 0;
    while (pos <= len1 - len2)
    {
        if (s1[i] == s2[j])
            ++i, ++j;
        else
        {
            if (j == 0)
            {
                ++i;
                pos = i;
            }
            else
            {
                j = theNext[j - 1];
                pos = i - j;
            }
        }
        if (j == len2)
        {
            cout << pos + 1 << endl;
            ++pos;
            i = pos;
            j = 0;
        }
    }
    for (int i = 0; i < len2; ++i)
    {
        cout << theNext[i] << " ";
    }
    return 0;
}