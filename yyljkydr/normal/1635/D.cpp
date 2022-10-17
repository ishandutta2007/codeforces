#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int f[N],cnt[N];

int n,p,a[N];

map<int,int>vis;

int find(int x)
{
    if(!x)
        return 0;
    if(vis[x])
        return 1;
    return x&1?find(x>>1):(x&2?0:find(x>>2));
}

int get(int x)
{
    for(int i=29;i>=0;i--)
        if(x>>i&1)
            return i;
    assert(0);
    return -1;
}

int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(find(a[i]))
            continue;
        vis[a[i]]=1;
        cnt[get(a[i])]++;
    }
    int ans=0;
    for(int i=0;i<=p-1;i++)
    {
        f[i]=cnt[i];
        if(i>=1)
            f[i]+=f[i-1];
        if(i>=2)
            f[i]+=f[i-2];
        f[i]%=P;
        ans=(ans+f[i])%P;
    }
    printf("%d\n",ans);
}