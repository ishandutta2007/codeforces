#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int s[N];
int x[N],y[N];
int e[N];
int ans[N];

vector<int> G[N];

bool vis[N];

void dfs(int now)
{
    vis[now] = true;
    for (int i:G[now])
    {
        int to = (now^e[i]);
        if (vis[to]) continue;
        dfs(to);
        s[now] += s[to];
        if (x[i] == now) ans[i] = s[to];
        else ans[i] = -s[to];
    }
}

int main ()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&s[i]);
        sum += s[i];
    }
    if (sum)
    {
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    int m;
    scanf("%d",&m);
    for (int i=1;m>=i;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        e[i] = (x[i]^y[i]);
        G[ x[i] ].push_back(i);
        G[ y[i] ].push_back(i);
    }
    dfs(1);
    for (int i=1;m>=i;i++)
    {
        printf("%d\n",ans[i]);
    }
}