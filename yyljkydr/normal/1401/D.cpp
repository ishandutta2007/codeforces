#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=1e9+7;

int T;

vector<long long>a,b;

vector<int>g[N];

int n,m;

int pr[N];

int sz[N];

void dfs(int x,int f)
{
    sz[x]=1;
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
        sz[x]+=sz[v];
    }
    if(f)
        a.push_back(1ll*sz[x]*(n-sz[x]));
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        a.clear(),b.clear();
        dfs(1,0);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            scanf("%d",&pr[i]);
        sort(pr+1,pr+m+1,greater<int>());
        if(m>=n-1)
        {
            long long s=1;
            for(int i=1;i<=m-(n-2);i++)
                s=s*pr[i]%P;
            b.push_back(s);
            for(int i=m-(n-2)+1;i<=m;i++)
                b.push_back(pr[i]);
        }
        else
        {
            for(int i=1;i<=m;i++)
                b.push_back(pr[i]);
            for(int i=m+1;i<=n-1;i++)
                b.push_back(1);
        }
        sort(a.begin(),a.end(),greater<long long>());
        for(auto &x:a)
            x%=P;
        for(auto &x:b)
            x%=P;
        int ans=0;
        assert(a.size()==b.size()&&a.size()==n-1);
        for(int i=0;i<n-1;i++)
            ans=(ans+1ll*a[i]*b[i]%P)%P;
        printf("%d\n",ans);
    }
}