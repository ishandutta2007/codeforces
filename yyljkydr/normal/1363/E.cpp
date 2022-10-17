#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],b[N],c[N];

int wrong[N],sb[N],sc[N];

int tag[N],fa[N],fix[N];

vector<int>can;

vector<int>g[N];

int la[N];

void dfs(int x,int f,int mn,int p)
{
    la[x]=p;
    if(a[x]<mn)
        mn=a[x],can.push_back(x),tag[x]=1,fa[x]=f,p=x;
    if(b[x]!=c[x])
    {
        sb[x]=b[x],sc[x]=c[x];
        wrong[x]=b[x]!=c[x];
    }
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x,mn,p);
        sb[x]+=sb[v];
        sc[x]+=sc[v];
        wrong[x]+=wrong[v];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,1e9+7,0);
    sort(can.begin(),can.end(),[&](const int &x,const int &y){return a[x]<a[y];});
    long long ans=0;
    for(auto x:can)
    {
        int w=wrong[x];
        int d=abs(sb[x]-sc[x]);
        int y=fa[x];
        ans+=1ll*a[x]*(w-d);
        wrong[x]=d;
        wrong[la[x]]-=(w-d)+fix[x];
        fix[la[x]]+=w-d+fix[x];
    }
    if(wrong[1])
        puts("-1");
    else
        printf("%lld\n",ans);
}