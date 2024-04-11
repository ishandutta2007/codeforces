#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200006;
const LL mod = 1e9 + 7;

vector<int> G[N],revG[N];

void add_edge(int x,int y)
{
    G[x].push_back(y);
    revG[y].push_back(x);
}

bool vis[N];
int get_stamp[N];
int stamp;

void dfs1(int now)
{
    vis[now]=1;
    for (int i:revG[now])
    {
        if (!vis[i]) dfs1(i);
    }
    get_stamp[++stamp] = now;
}

int scc_sz[N];
int scc_id[N];
int val[N];

void dfs2(int now,int scc)
{
    vis[now]=1;
    for (int i:G[now])
    {
        if (!vis[i]) dfs2(i,scc);
    }
    scc_sz[scc]++;
    scc_id[now] = scc;
    val[scc] = now;
}

vector<int> scc_G[N];
int deg[N];


bool _[N];

int dfs3(int now)
{
    vis[now]=1;
    if (_[val[now]]) return 0;
    int ret=1;
    for (int i:scc_G[now])
    {
        if (!vis[i])
        {
            ret += dfs3(i);
        }
    }
    return ret;
}

LL solve(LL x)
{
    //cout << "x = "<<x<<endl;
    if (scc_sz[x] != 1) return 1+1;
    else return max(dfs3(x),1);
}

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if (x==y) _[x] = 1;
        add_edge(x,y);
    }
    n<<=1;
    stamp=0;
    for (int i=1;n>=i;i++)
    {
        if (!vis[i]) dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    int scc=0;
    for (int i=n;i>=1;i--)
    {
        if (!vis[ get_stamp[i] ]) dfs2( get_stamp[i],++scc);
    }
    for (int i=1;n>=i;i++)
    {
        for (int j:G[i])
        {
            if (scc_id[i] != scc_id[j])
            {
                //scc_G[ scc_id[i] ].push_back(scc_id[j]);
                //cout << "scc i = "<<scc_id[i]<<" , j = "<<scc_id[j]<<endl;
                scc_G[ scc_id[j] ].push_back(scc_id[i]);
                deg[ scc_id[i] ]++;
            }
        }
    }
    memset(vis,0,sizeof(vis));
    LL ans=1;
    for (int i=1;scc>=i;i++)
    {
        if (deg[i] == 0)
        {
            ans *= solve(i);
            ans %= mod;
        }
    }
    printf("%lld\n",ans);
}