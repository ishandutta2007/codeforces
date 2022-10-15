#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=1e5+5;
const int maxm=2e5+5;
int n,m,k;
struct graph
{
    int head[maxn],ver[maxm<<1],nxt[maxm<<1],tot;
    void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
    void link(int x,int y){add(x,y);add(y,x);}
    int fa[maxn],dep[maxn];bool vis[maxn];
    bool flag;
    vector<int>dn[2];
    void dfs(int u,int f)
    {
        if(flag)return;
        fa[u]=f;
        vis[u]=1;dep[u]=dep[f]+1;
        dn[dep[u]&1].push_back(u);
        int mn=0;
        for(int i=head[u];i;i=nxt[i])
        {
            if(ver[i]==f)continue;
            if(vis[ver[i]])
            {
                if(!mn||dep[u]-dep[ver[i]]<dep[u]-dep[mn])mn=ver[i];
                if(dep[u]-dep[ver[i]]<=k-1)
                {
                    flag=1;
                    printf("2\n%d\n",dep[u]-dep[ver[i]]+1);
                    int now=u;
                    while(now!=ver[i])
                    {
                        printf("%d ",now);
                        now=fa[now];
                    }
                    printf("%d ",ver[i]);
                    return;
                }
            }
            else dfs(ver[i],u);
            if(flag)return;
        }
        if(mn&&dep[u]-dep[mn]>=k)
        {
            flag=1;
            printf("1\n");
            int now=u,np=k/2+(k&1);
            while(np)
            {
                np--;
                printf("%d ",now);
                now=fa[fa[now]];
            }
            return;
        }
    }
}o;
int main()
{
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++)o.link(read(),read());
    o.dfs(1,0);
    if(!o.flag)
    {
        int np=k/2+(k&1);
        printf("1\n");
        if(o.dn[0].size()>=np)for(int i=0;i<np;i++)printf("%d ",o.dn[0][i]);
        else for(int i=0;i<np;i++)printf("%d ",o.dn[1][i]);
    }
    return 0;
}