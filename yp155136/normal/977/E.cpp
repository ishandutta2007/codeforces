#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

vector<int> G[N];

#define SZ(x) ((int)(x).size())

vector<int> vv;

bool vis[N];

void dfs(int now)
{
    vis[now] = true;
    vv.push_back(now);
    for (int i:G[now])
    {
        if (!vis[i]) dfs(i);
    }
}

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int tot=0;
    for (int i=1;n>=i;i++)
    {
        if (!vis[i])
        {
            vv.clear();
            dfs(i);
            bool can=true;
            for (int j:vv)
            {
                can &= (SZ(G[j]) == 2);
            }
            tot += can;
        }
    }
    printf("%d\n",tot);
}