#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,q,s,d;

int a[N];

struct Edge{
    int x,y;
};

bool operator <(const Edge &u,const Edge &v)
{
    if(abs(a[u.y]-a[u.x]-d)!=abs(a[v.y]-a[v.x]-d))
        return abs(a[u.y]-a[u.x]-d)<abs(a[v.y]-a[v.x]-d);
    if(u.x!=v.x)
        return u.x<v.x;
    return u.y<v.y;
}

set<Edge>can;
set<Edge>vis;

vector<int>g[N];

int fa[N],ans[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

void Add(int x,int y)
{
    if(x<1||y>n||x==y||vis.count(Edge{x,y}))
        return;
    can.insert(Edge{x,y});
    vis.insert(Edge{x,y});
}

int main()
{
    scanf("%d%d%d%d",&n,&q,&s,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),fa[i]=i,g[i].push_back(i);
    for(int i=1;i<=n;i++)
    {
        int p;
        if(i!=1)
        {
            p=lower_bound(a+1,a+i,a[i]-d)-a;
            Add(p,i);
            if(a[i]-a[p]!=d)
            {
                p--;
                Add(p,i);
            }
        }
    }
    int tot=n;
    while(tot!=1)
    {
        auto [x,y]=*can.begin();
        can.erase(can.begin());
        int fx=find(x),fy=find(y);
        int w=abs(a[y]-a[x]-d);
        if(fx!=fy)
        {
            if(g[fx].size()<g[fy].size())
                swap(fx,fy);
            int fs=find(s);
            if(fs==fx)
            {
                for(auto u:g[fy])
                    ans[u]=w;
            }
            else if(fs==fy)
            {
                for(auto u:g[fx])
                    ans[u]=w;
            }
            for(auto x:g[fy])
                g[fx].push_back(x);
            fa[fy]=fx;
            tot--;
            Add(x,y-1);
            Add(x,y+1);
            Add(x+1,y);
            Add(x-1,y);
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        puts(ans[x]<=y?"YES":"NO");
    }
}