// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-13 20:37:41
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-26 10:35:50
//  * @FilePath: \Algorithm\Greedy\Prim.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// using namespace std;
// const int MAXN = 2e3;
// const int INF = 0x3f3f3f3f;
// int n; // 顶点的数量
// int m; // 边的数量
// template <class T>
// struct edge
// {
//     int v1;
//     int v2;
//     T weight;
//     bool operator<(const edge<T> &theEdge)
//     {
//         return this->weight < theEdge;
//     }
//     bool operator>(const edge<T> &theEdge)
//     {
//         return this->weight > theEdge;
//     }
// };
// edge<int> E[MAXN << 2];
// int dist[MAXN];
// bool vist[MAXN];
// int cnt = 0;
// void print()
// {
//     for (int i = 1; i <= n; ++i)
//     {
//         if (dist[i] == INF)
//             cout << "INF"
//                  << " ";
//         else
//             cout << dist[i] << " ";
//     }
//     cout << endl;
// }
// int prim()
// {
//     int res = 0;
//     dist[1] = 0;
//     while (true)
//     {
//         int v = 0;
//         int minDist = INF;
//         for (int i = 1; i <= n; ++i)
//         {
//             if (dist[i] < minDist && !vist[i])
//             {
//                 v = i;
//                 minDist = dist[i];
//             }
//         }
//         if (v == 0)
//             break;
//         else
//         {
//             cout << "v = " << v << endl;
//             cnt++;
//             vist[v] = true;
//             res += dist[v];
//         }
//         for (int i = 1; i <= m; ++i)
//         {
//             if (E[i].v1 == v && !vist[E[i].v2])
//                 dist[E[i].v2] = min(E[i].weight, dist[E[i].v2]);
//             if (E[i].v2 == v && !vist[E[i].v1])
//                 dist[E[i].v1] = min(E[i].weight, dist[E[i].v1]);
//         }
//         print();
//     }
//     return res;
// }
// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= m; ++i)
//     {
//         int v1, v2, e;
//         cin >> v1 >> v2 >> e;
//         E[i].v1 = v1;
//         E[i].v2 = v2;
//         E[i].weight = e;
//     }
//     for(int i = 1; i<= n; ++i)
//     {
//         dist[i] = INF;
//         vist[i] = false;
//     }
//     int res = prim();
//     // cout << "cnt = " << cnt << endl;
//     // cout << "res = " << res << endl;
//     if (cnt == n)
//         cout << res << endl;
//     else
//         cout << "orz" << endl;
//     return 0;
// }
