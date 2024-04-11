#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n;
vector<int> G[maxn];

int cnt[maxn];

void dfs(int i,int fa=0,int dep=0)  {
    ++cnt[dep];
    for (int j:G[i])    {
        if (fa==j) continue;
        dfs(j,i,dep^1);
    }
}

int main()  {
    scanf("%d",&n);
    for (int k=1;k<n;++k)   {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1);

    printf("%d\n",min(cnt[0],cnt[1])-1);

    return 0;
}