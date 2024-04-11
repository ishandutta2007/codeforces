#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN];
vector<int> e[MAXN];
void dfs(int u,int fa)
{
    for(auto v : e[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        a[u]^=a[v];
    }
}
int dp[MAXN];
bool dfs2(int u,int fa)
{
    bool isok=false;
    dp[u]=(a[u]==a[1]);
    for(auto v : e[u])
    {
        if(v==fa)continue;
        isok|=dfs2(v,u);
        dp[u]|=dp[v];
    }
    int cnt=0;
    for(auto v : e[u]) {
        if(v==fa)continue;
        cnt+=dp[v];
        if(u>1 && a[u]==0) isok|=dp[v];
    }
    isok|=(cnt>1);
    return isok;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            e[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,0);
        bool isok=(a[1]==0);
        if(k>2) isok|=dfs2(1,0);
        printf("%s\n",isok ? "YES" : "NO");
    }
    return 0;
}