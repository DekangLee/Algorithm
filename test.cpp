#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 998244353;
int n, m;
int dp[2][10][10][10][10];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k)
                for (int l = 0; l < 10; ++l)
                    dp[(n + 1) % 2][i][j][k][l] = 1; // 初始化

    for (int i = n; i >= 5; --i)
    {
        int t = i % 2;
        for (int pre = 1 - t; pre < 10; pre += 2)
            for (int ppre = t; ppre < 10; ppre += 2)
                for (int pppre = 1 - t; pppre < 10; pppre += 2)
                    for (int ppppre = t; ppppre < 10; ppppre += 2)
                    {
                        int res = 0;
                        if (t)
                        {
                            for (int i = 1; i <= 9; i += 2)
                            {
                                if (i + pre + ppre + pppre + ppppre <= m)
                                    res = (res + dp[(i + 1) % 2][i][pre][ppre][pppre]) % MOD;
                            }
                        }
                        else
                        {
                            for (int i = 0; i <= 8; i += 2)
                            {
                                if (i + pre + ppre + pppre + ppppre <= m)
                                    res = (res + dp[(i + 1) % 2][i][pre][ppre][pppre]) % MOD;
                            }
                        }
                        dp[i % 2][pre][ppre][pppre][ppppre] = res;
                    }
    }

    int ans = 0;
    for (int i = 1; i <= 9; i += 2)
        for (int j = 0; j <= 8; j += 2)
            for (int k = 1; k <= 9; k += 2)
                for (int l = 0; l <= 8; l += 2)
                {
                    ans = (ans + dp[5 % 2][l][k][j][i]) % MOD;
                }
    cout << ans % MOD;

    return 0;
}