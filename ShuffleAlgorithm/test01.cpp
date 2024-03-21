// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-02 13:59:29
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-02 16:04:46
//  * @FilePath: \Algorithm\ShuffleAlgorithm\test01.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include <string>
// #include <unordered_map>
// using namespace std;
// int main()
// {
//     string str;
//     cin >> str;
//     int res = 0;
//     unordered_map<char, int> _map;
//     for (int i = 0; i < str.size(); i++)
//     {
//         for (int j = i; j < str.size(); ++j)
//         {
//             _map[str[j]]++;
//             res += _map.size();
//         }
//         _map.clear();
//     }
//     cout << res << endl;
//     return 0;
// }