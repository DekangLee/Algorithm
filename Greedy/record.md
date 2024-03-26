### 最小生成树算法
用于解决无向图的生成树问题
#### prim算法
&emsp;&emsp;prim算法的基本思想为贪婪，从任意一个顶点开始，选取与该顶点相连的最小权值的边节点。将该节点作为新的源节点对剩下的未访问的节点进行更新，直到所有的顶点均访问完成。
&emsp;&emsp;以一个图为例
```cpp
template <class T>
struct edge
{
    int v1;
    int v2;
    T weight;
    bool operator<(const edge<T> &theEdge)
    {
        return this->weight < theEdge;
    }
    bool operator>(const edge<T> &theEdge)
    {
        return this->weight > theEdge;
    }
};
```
这里定义一个存储边信息的结构体，和需要记录的全局变量。
```cpp
edge<int> E[MAXN << 2];
int dist[MAXN];
bool vist[MAXN];
int cnt = 0;
```
prim算法的主要过程如下。
```cpp
int prim()
{
    int res = 0;
    dist[1] = 0;
    while (true)
    {
        int v = 0;
        int minDist = INF;
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] < minDist && !vist[i])
            {
                v = i;
                minDist = dist[i];
            }
        }
        if (v == 0)
            break;
        else
        {
            cout << "v = " << v << endl;
            cnt++;
            vist[v] = true;
            res += dist[v];
        }
        for (int i = 1; i <= m; ++i)
        {
            if (E[i].v1 == v && !vist[E[i].v2])
                dist[E[i].v2] = min(E[i].weight, dist[E[i].v2]);
            if (E[i].v2 == v && !vist[E[i].v1])
                dist[E[i].v1] = min(E[i].weight, dist[E[i].v1]);
        }
        print();
    }
    return res;
}
```
&emsp;&emsp;用数组E存储边的信息，dist数组为剩余顶点到已选集合的最小距离，vist数组记录该顶点是否已经存在于已选集合。cnt为已选边的数量，当`cnt==n-1`时程序结束。
&emsp;&emsp;事实上该图可能存在孤立点，若程序结束时`cnt!=n-1`说明该无向图存在孤立点，不存在最小生成树。
#### Kruskal算法
&emsp;&emsp;该算法同样是基于贪婪的算法思想，不断从边集中选出最小权值的边，并且建立一个动态并查集的数据结构，该数据结构用来判断两个顶点是否在同一个集合中。如果在一个集合中则存在环路，需要将该边抛弃。具体实现的时候可以通过二叉堆优化查找最小权值边的时间复杂度。通过路径压缩优化并查集判断两顶点是否在同一集合里的时间复杂度。
```cpp
edge E[MAXM];      // 边集
int V[MAXN] = {0}; // 顶点集
edge resE[MAXM];
int n; // 顶点的数目
int m; // 边的数目
int cnt = 0;
```
以上全局变量为需要存储和记录的参数，`E`为所有边集，这里可以采用小根堆组织数据，`V`为顶点集，用来建立并查集数据结构，`cnt`为最终边的个数。
```cpp
struct edge
{
    int v1;
    int v2;
    int weight;
    bool operator<(const edge &theEdge)
    {
        return this->weight < theEdge.weight;
    }
    bool operator>(const edge &theEdge)
    {
        return this->weight > theEdge.weight;
    }
};
```
用于存储边的结构体，并重载了比较运算符。
```cpp
int findUnite(int _n)
{
    int pNode = V[_n];
    while (pNode != V[pNode])
        pNode = V[pNode];
    int node = _n;
    while(node != pNode)
    {
        int theNode = V[node];
        V[node] = pNode;
        node = theNode;
    }
    return pNode;
}
```
带路径压缩的并查集，根节点查找函数
```cpp
int Kruskal()
{
    sort(E + 1, E + m + 1);
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        int u = findUnite(E[i].v1);
        int v = findUnite(E[i].v2);
        if (u == v) // 该条件下生成树存在环路
            continue;
        ans += E[i].weight;
        V[u] = v;
        cnt++;
        resE[cnt] = E[i];
        if (cnt == n - 1)
            break;
    }
    return ans;
}
```
Kruskal算法的过程，通过找出最小边，判断是否存在环路，`cnt`为最小生成树的边的个数，程序结束时应有`cnt == n-1`，否则存在孤立点，该无向图不存在最小生成树。
