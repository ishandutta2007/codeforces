#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n,m,k;
LL tot;

const int N = 22;

LL a[N][N];

map< LL,LL > mp[N][N];

LL tar1,tar2;
LL ans=0;

void dfs1(int x,int y,LL val,int step)
{
    val ^= a[x][y];
    if (step == tar1)
    {
        mp[x][y][val]++;
        return;
    }
    if (x != n) dfs1(x+1,y,val,step+1);
    if (y != m) dfs1(x,y+1,val,step+1);
}

void dfs2(int x,int y,LL val)
{
    if (mp[x][y].size() != 0)
    {
        ans += mp[x][y][ (val^k) ];
        return;
    }
    val ^= a[x][y];
    if (x != 1) dfs2(x-1,y,val);
    if (y != 1) dfs2(x,y-1,val);
}

int main ()
{
    scanf("%lld %lld %lld",&n,&m,&k);
    for (int i=1;n>=i;i++)
    {
        for (int j=1;m>=j;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    tot = n+m-1;
    tar1 = (tot+1)/2;
    dfs1(1,1,0,1);
    dfs2(n,m,0);
    printf("%lld\n",ans);
}