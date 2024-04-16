#include <iostream>
#include <vector>
using namespace std;
const int N = 4e4;
const int M = 65;
int dp[M][N];
vector<int> G[M];
int c[N];
int w[N];
int n;
int V;
void utiltiy(int x) // 将父节点输入
{
    for (int i = c[x]; i <= V; ++i)
        dp[x][i] = w[x];                  // 将所有以x为父节点的子树都加上父节点的价值
    for (int i = 0; i < G[x].size(); ++i) // 遍历x节点的所有子节点
    {
        int y = G[x][i]; // x节点的子节点
        utiltiy(y); // 递归求解子节点y
        for (int j = V; j >= c[x]; --j)
        {
            for (int k = 0; k <= j - c[x]; ++k)
            {
                dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[y][k]);
            }
        }
    }
}
int main()
{
    cin >> n >> V;
    int root;
    for (int i = 1; i <= n; ++i)
    {
        int p;
        cin >> c[i] >> w[i] >> p;
        if (p == -1)
            root = i;
        else
            G[p].push_back(i);
    }
    utiltiy(root);
    cout << dp[root][V];
    return 0;
}