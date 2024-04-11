#include <bits/stdc++.h>
using namespace std;

const int N = 300006;

vector<int> G[N];
int e[N];

int dfn[N],low[N];
int stamp=0;
bool is_bridge[N];
bool vis[N];
int xx[N],yy[N];

void dfs(int now,int par)
{
    dfn[now] = low[now] = (++stamp);
    vis[now] = true;
    for (int i:G[now])
    {
        int to = (now^e[i]);
        //cout << "now = " << now << " , to = " << to <<endl;
        if (to == par) continue;
        if (vis[to])
        {
            low[now] = min(low[now],dfn[to]);
        }
        else
        {
            dfs(to,now);
            low[now] = min(low[now],low[to]);
            //cout << "to = " << to << " , now = " << now << " , low = " << low[to] << endl;
            if (low[to] > dfn[now] && now != par)
            {
                is_bridge[i] = true;
            }
            else if (now == par && low[to] != dfn[now])
            {
                is_bridge[i] = true;
            }
        }
    }
}

vector<int> GG[N];

int in_bcc[N];

void dfs2(int now,int id)
{
    vis[now] = true;
    in_bcc[now] = id;
    for (int i:G[now])
    {
        if (is_bridge[i]) continue;
        int to = (now^e[i]);
        if (!vis[to]) dfs2(to,id);
    }
}

int ans = 0;

int dfs3(int now,int par)
{
    vis[now] = true;
    int ret=0;
    int mx=0,mx2=0;
    for (int i:GG[now])
    {
        if (i == par) continue;
        int _ = dfs3(i,now) + 1;
        ret = max(ret,_);
        if (_ > mx)
        {
            mx2 = mx;
            mx = _;
        }
        else if (_ > mx2)
        {
            mx2 = _;
        }
        ans = max(ans,ret);
    }
    ans = max(ans,mx + mx2);
    return ret;
}

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        xx[i] = x;
        yy[i] = y;
        e[i] = (x^y);
        G[x].push_back(i);
        G[y].push_back(i);
    }
    dfs(1,1);
    //cout << "finish" << endl;
    memset(vis,0,sizeof(vis));
    set<int> st;
    for (int i=1;n>=i;i++)
    {
        if (!vis[i])
        {
            dfs2(i,i);
            st.insert(i);
        }
    }
    //cout << "finish 2" << endl;
    memset(vis,0,sizeof(vis));
    for (int i=1;m>=i;i++)
    {
        if (is_bridge[i])
        {
            //cout << "i = " << i << " , u = " << in_bcc[ xx[i] ] << " , v = " << in_bcc[ yy[i] ] <<endl;
            GG[ in_bcc[ xx[i] ] ].push_back( in_bcc[ yy[i] ] );
            GG[ in_bcc[ yy[i] ] ].push_back( in_bcc[ xx[i] ] );
        }
    }
    for (int i:st)
    {
        if (!vis[i]) dfs3(i,i);
    }
    printf("%d\n",ans);
}