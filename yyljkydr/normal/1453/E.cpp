#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n;

vector<int>g[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii f[N];

void dfs(int x,int fa,int k)
{
    vector<int>vq;
    if(g[x].size()>=2||(!fa&&g[x].size()))
        f[x].sd=1e9;
    else
        return;
    for(auto v:g[x])
    {
        if(v==fa)
            continue;
        dfs(v,x,k);
        f[x].fs=max(f[x].fs,f[v].fs);
        vq.push_back(f[v].sd);
    }
    sort(vq.begin(),vq.end());
    int m=vq.size();
    if(vq.size()==1)
        f[x].sd=vq[0]+1;
    else
    {
        if(vq[m-1]+1>k||vq[m-2]+2>k)
            f[1].fs=1e9;
        if(vq[m-1]+2<=k)
            f[x].sd=vq[0]+1;
        else
            f[x].sd=vq[m-1]+1;
    }
}

bool chk(int w)
{
    for(int i=1;i<=n;i++)
        f[i]=mp(0,0);
    dfs(1,0,w);
    return max(f[1].fs,f[1].sd)<=w;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            g[i].clear(),f[i]=mp(0,0);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int l=-1,r=n;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(chk(mid))
                r=mid;
            else
                l=mid;
        }
        printf("%d\n",r);
    }
}