#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100006;

int b[N];

const int INF = 1000000007;

int solve(int a1,int a2,int n)
{
    int cnt=0;
    for (int i=1;n>=i;i++)
    {
        int _ = abs( b[i] - ( a1 + (a2-a1)*(i-1) ) );
        if (_>1) return INF;
        if (_) ++cnt;
    }
    return cnt;
}

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&b[i]);
    }
    if (n <= 2)
    {
        puts("0");
        return 0;
    }
    int ans = INF;
    for (int dx = -1;1>=dx;dx++)
    {
        for (int dy=-1;1>=dy;dy++)
        {
            ans = min(ans,solve(b[1] + dx,b[2] + dy,n));
        }
    }
    if (ans == INF) puts("-1");
    else printf("%d\n",ans);
}