#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int dp[200005], m;
set<string> s[20];
int main()
{
    string tp;
    while (cin >> tp)
    {
        if (tp == ".")
            break;
        s[tp.size()].insert(tp); // 存到他大小的集合中
        m = max(m, int(tp.size()));
    }
    int i, ans = 0;
    dp[0] = 1; // 初始化
    string n = " ";
    // n = " ";
    // while (cin >> tp)
    // {
    //     n = n + tp; // 将所有的串合成一个
    // }
    cin >> tp;
    n += tp;
    cout << "n = " << n << endl;
    for (i = 1; i < n.size(); i++)
    { // 枚举子串
        for (int j = min(i, m); j >= 1; j--)
        {
            string tt = n.substr(i - j + 1, j); // 截除子串
            if (s[tt.size()].count(tt) == 1 && dp[i - j] == 1)
            {              // 如果合法
                ans = i;   // 必定是最大的
                dp[i] = 1; // 本身也合法
                break;     // 没必要搜下去了
            }
        }
    }
    cout << ans;
}