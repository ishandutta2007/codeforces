#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 10006;

int c[N];
int ans;

vector<int> G[N];

void dfs(int now,int par_clr)
{
    if (c[now] != par_clr) ans++;
    for (int i:G[now])
    {
        dfs(i,c[now]);
    }
}

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=2;n>=i;i++)
    {
        int p;
        scanf("%d",&p);
        G[p].push_back(i);
    }
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&c[i]);
    }
    dfs(1,0);
    printf("%d\n",ans);
}