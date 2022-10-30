#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;

LL ppow(LL a,LL n,LL mod)
{
    LL ret=1;
    LL now=a;
    while (n)
    {
        if (n&1)
        {
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        n>>=1;
    }
    return ret;
}

int p[9];

int k;

LL cnt;

void dfs(int now)
{
    if (now == k+1)
    {
        for (int i=1;k>=i;i++)
        {
            bool meet_1 = false;
            int tmp=k+3;
            int now=i;
            while (tmp--)
            {
                now = p[now];
                if (now == 1)
                {
                    meet_1 = true;
                    break;
                }
            }
            if (!meet_1) return;
        }
        cnt++;
        return;
    }
    else
    {
        for (int i=1;k>=i;i++)
        {
            p[now] = i;
            dfs(now+1);
        }
    }
}

int main ()
{
    int n;
    cin >> n >> k;
    LL ans = ppow(n-k,n-k,mod);
    if (!ans) ans=1;
    dfs(1);
    cout << ans*cnt%mod;
}