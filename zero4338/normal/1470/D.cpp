#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
int T;
const int maxn=3e5+5;
int n,m;
struct graph
{
    bool vis[maxn],used[maxn];vector<int>to[maxn];
    void link(int x,int y){to[x].push_back(y);to[y].push_back(x);}
    void clear(){for(int i=1;i<=n;i++)vis[i]=used[i]=0,to[i].clear();}    
    void dfs(int u)
    {
        vis[u]=1;
        for(auto i:to[u])if(!vis[i])dfs(i);
    }
    bool judge(){for(int i=1;i<=n;i++)if(!vis[i])return false;return true;}
    vector<int>ans;
    void solve(int u)
    {
        if(!used[u])
        {
            ans.push_back(u);
            used[u]=1;
            for(auto i:to[u])used[i]=1;
        }
        vis[u]=1;
        for(auto i:to[u])
            if(!vis[i])solve(i);
    }
}o;
int main()
{
    T=read();
    while(T--)
    {
        n=read();m=read();o.clear();
        for(int i=1;i<=m;i++)o.link(read(),read());
        o.dfs(1);
        if(!o.judge())printf("NO\n");
        else
        {
            for(int i=1;i<=n;i++)o.vis[i]=0;
            o.ans.clear();
            o.solve(1);
            sort(o.ans.begin(),o.ans.end());
            printf("YES\n%d\n",o.ans.size());
            for(auto i:o.ans)printf("%d ",i);printf("\n");
        }
    }
    return 0;
}