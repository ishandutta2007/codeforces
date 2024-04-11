#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int N = 100006;
vector<pii> G[N];

int id[N];
bool vis[N];

int KK = -1;

void dfs(int now)
{
    vis[now] = true;
    for (pii p:G[now])
    {
        if (KK != -1) return;
        int to=p.first;
        int w=p.second;
        if (vis[to])
        {
            if (id[to] != id[now] + w)
            {
                KK = abs(id[to] - w - id[now]);
                return;
            }
        }
        else
        {
            id[to] = id[now] + w;
            dfs(to);
        }
    }
}

int K;
bool okay = true;
int ans = 1;
int n,m;

void dfs2(int now)
{
    vis[now] = true;
    for (pii p:G[now])
    {
        int to=p.first;
        int w=p.second;
        if (!vis[to])
        {
            id[to] = id[now] + w;
            dfs2(to);
        }
        else
        {
            if ( ((id[to] - id[now] - w)%K + K )%K != 0  )
            {
                okay = false;
            }
        }
    }
}

void doo(int k)
{
    K = k;
    memset(vis,0,sizeof(vis));
    okay = true;
    for (int i=1;i<=n;++i)
    {
        if (!vis[i])
        {
            dfs2(i);
        }
    }
    if (okay)
    {
        ans = max(ans,k);
    }
}

int main ()
{
    //int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(make_pair(y,1));
        G[y].push_back(make_pair(x,-1));
    }
    memset(id,-1,sizeof(id));
    for (int i=1;i<=n;++i)
    {
        if (!vis[i])
        {
            id[i] = 0;
            dfs(i);
            if (KK != -1) break;
        }
    }
    //cout << "KK = " << KK << endl;
    if (KK == -1)
    {
        printf("%d\n",n);
        return 0;
    }
    //int ans = 1;
    for (int i=1;i*i <= KK;++i)
    {
        if (KK % i == 0)
        {
            doo(i);
            doo(KK/i);
        }
    }
    printf("%d\n",ans);
}