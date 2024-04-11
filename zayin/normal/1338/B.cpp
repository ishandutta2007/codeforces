#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n;
vector<int> G[maxn];

int ans1=1,ans2;

void dfs(int i,int fa=0,int dep=0)    {
    if (G[i].size()==1&&(dep&1)) ans1=3;
    for (int j:G[i])
        if (fa!=j)
            dfs(j,i,dep+1);
}

int main()  {
    scanf("%d",&n);
    for (int k=1;k<n;++k)   {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int rt;
    for (int i=1;i<=n;++i)
        if (G[i].size()==1)
            rt=i;
    
    dfs(rt);

    for (int i=1;i<=n;++i)  {
        if (G[i].size()==1) continue;
        int cnt=0;
        for (int j:G[i])
            if (G[j].size()==1)
                ++cnt;
        if (cnt)
            ans2+=cnt-1;
    }

    printf("%d %d\n",ans1,n-1-ans2);
    return 0;
}