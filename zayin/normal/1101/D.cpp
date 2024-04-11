#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
int a[maxn];

vector<int> vert[maxn];

vector<int> G[maxn],M[maxn];

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);

        int t=a[i];
        for (int d=2;d*d<=t;++d)
        {
            if (t%d)    continue;
            vert[d].push_back(i);
            // cout<<"fac:"<<d<<" "<<i<<endl;
            while (t%d==0)  t/=d;
        }
        if (t==1)   continue;
        vert[t].push_back(i);
        // cout<<"fac:"<<t<<" "<<i<<endl;
    }
    for (int k=1;k<n;++k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int fa[maxn];

void dfs(int i)
{
    for (int j:G[i])
    {
        if (fa[i]==j)  continue;
        fa[j]=i;
        dfs(j);
    }
}

int ans;
int dis[maxn];

void calc(int i)
{
    ans=max(ans,dis[i]=1);
    // cout<<"calc:"<<i<<endl;
    for (int j:M[i])
    {
        calc(j);
        ans=max(ans,dis[i]+dis[j]);
        dis[i]=max(dis[i],dis[j]+1);
    }
}

void solve()
{
    dfs(1);
    for (int d=2;d<maxn;++d)
    {
        for (int i:vert[d])
        {
            if (!fa[i]||a[fa[i]]%d) continue;
            M[fa[i]].push_back(i);
            // cout<<fa[i]<<" "<<i<<endl;
        }
        // cout<<endl;

        for (int i:vert[d])
            if (!fa[i]||a[fa[i]]%d)
                calc(i);
        
        for (int i:vert[d])
            M[i].clear();
    }
    printf("%d\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}