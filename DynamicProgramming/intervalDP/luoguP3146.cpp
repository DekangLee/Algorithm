#include <iostream>
using namespace std;
struct resInfo
{
    int res;
    int l;
    int r;
    resInfo(int tRes = 0, int tl = 0, int tr = 0) : res(tRes), l(tl), r(tr){};
    resInfo(const resInfo &theRes)
    {
        this->res = theRes.res;
        this->l = theRes.l;
        this->r = theRes.r;
    }
    resInfo operator=(const resInfo &theRes)
    {
        this->res = theRes.res;
        this->l = theRes.l;
        this->r = theRes.r;
        return *this;
    }
};
int a[300];
resInfo dp[300][300];
int n;
resInfo f(int l, int r)
{
    if (l == r)
        return resInfo(a[l], l, r);
    if (dp[l][r].res != 0)
        return dp[l][r];
    resInfo res;
    for (int k = l; k < r; ++k)
    {
        resInfo tres;
        resInfo lRes = f(l, k);
        resInfo rRes = f(k + 1, r);
        if (lRes.res == rRes.res && lRes.r + 1 == rRes.l)
        {
            // 合并条件成立将其合并
            tres.res = lRes.res + 1;
            tres.l = lRes.l;
            tres.r = rRes.r;
        }
        else
        {
            if (lRes.res > rRes.res)
                tres = lRes;
            else
                tres = rRes;
        }
        if (tres.res > res.res)
            res = tres;
    }
    dp[l][r] = res;
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    resInfo ans = f(1, n);
    cout << ans.res << endl;
    // cout << "l = " << ans.l << " r = " << ans.r;
    return 0;
}