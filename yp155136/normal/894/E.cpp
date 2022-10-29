#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef long long LL;
typedef pair<int,LL> pii;  //{to,weight}
const int N = 1000006;

#define F first
#define S second

vector<int> G[N],revG[N];
vector<pii> ori_G[N];

vector<pii> scc_G[N];

LL get_w(LL w)
{
    LL L=0,R=100000;
    while (R-L != 1)
    {
        LL mid=(L+R)>>1;
        if (w - mid*(mid+1)/2 >= 0) L=mid;
        else R=mid;
    }
    return w + L*w - ( (L)*(L+1)*(2*L+1)/6 + (L*(L+1))/2 )/2;
}

bool vis[N];

int stamp;
int get_stamp[N];
LL dp[N];

void dfs1(int now)
{
    vis[now] = 1;
    for(int i:revG[now])
    {
        if(!vis[i]) dfs1(i);
    }
    get_stamp[++stamp] = now;
}

int scc_id[N];

void dfs2(int now,int scc)
{
    vis[now] = 1;
    scc_id[now] = scc;
    for (int i:G[now])
    {
        if(!vis[i]) dfs2(i,scc);
    }
}

LL dfs(int now)
{
    if (vis[now]) return dp[now];
    vis[now] = 1;
    LL tmp=0;
    for (pii i:scc_G[now])
    {
        tmp = max(tmp,dfs(i.first)+i.second);
    }
    dp[now] += tmp;
    return dp[now];
}

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        G[x].push_back(y);
        revG[y].push_back(x);
        ori_G[x].push_back(make_pair(y,z));
    }
    stamp=0;
    for (int i=1;n>=i;i++)
    {
        if (!vis[i]) dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    int scc=0;
    for (int i=n;i>=1;i--)
    {
        if (!vis[ get_stamp[i] ]) dfs2(get_stamp[i],++scc);
    }
    for (int i=1;n>=i;i++)
    {
        for (pii p:ori_G[i])
        {
            int from=i,to=p.first;
            LL weight = p.second;
            if (scc_id[from] != scc_id[to])
            {
                scc_G[ scc_id[from] ].push_back(make_pair( scc_id[to],weight ));
            }
            else
            {
                dp[ scc_id[from] ] += get_w(weight);
            }
        }
    }
    memset(vis,0,sizeof(vis));
    int s;
    scanf("%d",&s);
    printf("%lld\n",dfs( scc_id[s] ));
}