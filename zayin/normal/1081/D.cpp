#include<bits/stdc++.h>
#define u(i)    E[i].u
#define v(i)    E[i].v
#define w(i)    E[i].w
#define maxn 100050
#define maxm 100050
using namespace std;

struct Edge
{
    int u,v,w;
    bool operator < (const Edge& E) const   {
        return w<E.w;
    }
}   E[maxm];

int n,m,k;

int vert[maxn];
int fa[maxn],sz[maxn];

void init()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<k;++i)
        scanf("%d",&vert[i]),sz[vert[i]]=1;
    for (int i=0;i<m;++i)
        scanf("%d%d%d",&u(i),&v(i),&w(i));
    sort(E,E+m);
}


int find(int i)
{
    return !fa[i]?i:fa[i]=find(fa[i]);
}

void solve()
{
    int ans;
    for (int i=0;i<m;++i)
    {
        int fu=find(u(i)),fv=find(v(i));
        if (fu==fv) continue;
        fa[fu]=fv;
        sz[fv]+=sz[fu];
        ans=w(i);
        if (sz[fv]==k) break;
    }
    while (k--)
        printf("%d ",ans);
}

int main()
{
    init();
    solve();
    return 0;
}