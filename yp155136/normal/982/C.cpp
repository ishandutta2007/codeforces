#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

vector<int> G[N];

int sz[N];

void dfs(int now,int par)
{
    sz[now] = 1;
    for (int i:G[now])
    {
        if (i==par) continue;
        dfs(i,now);
        sz[now] += sz[i];
    }
}

int main ()
{
    int n;
    scanf("%d",&n);
    if (n&1)
    {
        puts("-1");
        return 0;
    }
    for (int i=1;n>i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int ans=-1;
    dfs(1,1);
    for (int i=1;n>=i;i++)
    {
        ans += (sz[i]%2==0);
    }
    printf("%d\n",ans);
}