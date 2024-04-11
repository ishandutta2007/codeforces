#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=51;

int n,k;

int p[N];

void End(int x)
{
    puts(x?"ACCEPTED":"REJECTED");
    exit(0);
}

int Count(int x)
{
    return __builtin_popcountll(x);
}

int ALL;

void out(int x)
{
    while(x)
        printf("%lld",x&1),x>>=1;
    puts("");
}

void dfs(int mask,int now,int vs)
{
    if(now>k)
    {
        // out(mask);
        mask^=ALL;
        if(mask&(mask+1))
            End(0);
        return;
    }
    int tvs=vs&p[now];
    int zero=Count(tvs)-Count(mask&tvs);
    int nbit=Count(p[now]^tvs);
    for(int i=0;i<=nbit;i++)
    {
        int nz=zero+i;
        int nbt=p[now];
        int nmsk=(mask&(ALL^nbt))^nbt;
        for(int j=0;j<nz;j++)
            nmsk^=(nbt&(-nbt)),nbt^=(nbt&(-nbt));
        dfs(nmsk,now+1,p[now]|vs);
    }
}

signed main()
{
    scanf("%lld%lld",&n,&k);
    if(n==1)
        End(1);
    ALL=(1ll<<n)-1;
    int vis=0;
    for(int i=1;i<=k;i++)
    {
        int q;
        scanf("%lld",&q);
        while(q--)
        {
            int pos;
            scanf("%lld",&pos);
            p[i]|=1ll<<(pos-1);
        }
        vis|=p[i];
    }
    if(vis!=ALL)
        End(0);
    dfs(0,1,0);
    End(1);
}