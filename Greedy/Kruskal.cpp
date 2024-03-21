// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-03-13 16:47:36
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-03-13 20:31:57
//  * @FilePath: \Algorithm\Greedy\Kruskal.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;
// const int MAXN = 5e2; // 存储顶点
// const int MAXM = 1e3; // 存储边
// const int INF = 0x3fffffff;
// void print(int *a, int n)
// {
//     for (int i = 1; i <= n; ++i)
//         cout << a[i] << " ";
//     cout << endl;
// }
// struct edge
// {
//     int v1;
//     int v2;
//     int weight;
//     bool operator<(const edge &theEdge)
//     {
//         return this->weight < theEdge.weight;
//     }
//     bool operator>(const edge &theEdge)
//     {
//         return this->weight > theEdge.weight;
//     }
// };
// ostream &operator<<(ostream &cout, const edge &theE)
// {
//     cout << "v1 = " << theE.v1 << "  v2 = " << theE.v2 << "  weight = " << theE.weight;
//     return cout;
// }
// edge E[MAXM];      // 边集
// int V[MAXN] = {0}; // 顶点集
// edge resE[MAXM];
// int n; // 顶点的数目
// int m; // 边的数目
// int cnt = 0;
// int findUnite(int _n)
// {
//     int pNode = V[_n];
//     while (pNode != V[pNode])
//         pNode = V[pNode];
//     return pNode;
// }
// int Kruskal()
// {
//     sort(E + 1, E + m + 1);
//     int ans = 0;
//     for (int i = 1; i <= m; ++i)
//     {
//         int u = findUnite(E[i].v1);
//         int v = findUnite(E[i].v2);
//         if (u == v) // 该条件下生成树存在环路
//             continue;
//         ans += E[i].weight;
//         V[u] = v;
//         cnt++;
//         resE[cnt] = E[i];
//         if (cnt == n - 1)
//             break;
//     }
//     return ans;
// }
// int main()
// {
//     // priority_queue<int, vector<int>, less<int>> heap1;
//     // heap1.push(10);
//     // heap1.push(20);
//     // heap1.push(11);
//     // cout << heap1.top() << endl;
//     cout << "输入节点的数量：";
//     cin >> n;
//     cout << "输入边的数量：";
//     cin >> m;
//     for (int i = 1; i <= n; ++i)
//         V[i] = i;
//     for (int i = 1; i <= m; ++i)
//     {
//         cin >> E[i].v1 >> E[i].v2 >> E[i].weight;
//     }
//     cout << Kruskal() << endl;
//     for (int i = 1; i <= cnt; ++i)
//     {
//         cout << resE[i] << endl;
//     }
//     print(V,n);
//     return 0;
// }