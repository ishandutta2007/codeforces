#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=2e2+5;
int n,m;
int ans;
bool a[maxn][maxn];
struct network_flow
{
    int s,t,maxflow;
    int head[maxn*maxn<<1],cur[maxn*maxn<<1],ver[maxn*maxn<<4],nxt[maxn*maxn<<4],val[maxn*maxn<<4],tot=1;
    void add(int x,int y,int z){ver[++tot]=y;val[tot]=z;nxt[tot]=head[x];head[x]=tot;}
    void link(int x,int y,int z){add(x,y,z);add(y,x,0);}
    int cnt,rg[maxn][maxn],dwn[maxn][maxn];
    void build()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(!a[i][j])continue;
                if(a[i][j+1])rg[i][j]=++cnt;
                if(a[i+1][j])dwn[i][j]=++cnt;
                if(rg[i][j]&&dwn[i][j])link(rg[i][j],dwn[i][j],1);
                if(rg[i][j]&&dwn[i-1][j])link(rg[i][j],dwn[i-1][j],1);
                if(rg[i][j]&&dwn[i-1][j+1])link(rg[i][j],dwn[i-1][j+1],1);
                if(dwn[i][j]&&rg[i][j-1])link(rg[i][j-1],dwn[i][j],1);
            }
        }
        s=0;t=cnt+1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(rg[i][j])link(s,rg[i][j],1);
                if(dwn[i][j])link(dwn[i][j],t,1);
            }
        }
    }
    int q[maxn*maxn<<1],front,tail,d[maxn*maxn<<1];
    bool getd()
    {
        front=0;tail=-1;
        memset(d,0,sizeof(d));
        d[s]=1;q[++tail]=s;cur[s]=head[s];
        while(front<=tail)
        {
            int x=q[front++];
            for(int i=head[x];i;i=nxt[i])
            {
                if(val[i]&&!d[ver[i]])
                {
                    d[ver[i]]=d[x]+1;
                    cur[ver[i]]=head[ver[i]];
                    q[++tail]=ver[i];
                    if(ver[i]==t)return true;
                }
            }
        }
        return false;
    }
    int dinic(int x,int flow)
    {
        if(x==t)return flow;
        int rest=flow,tmp;
        for(int i=cur[x];i&&rest;i=nxt[i])
        {
            if(val[i]&&d[ver[i]]==d[x]+1)
            {
                tmp=dinic(ver[i],min(rest,val[i]));
                if(!tmp)d[ver[i]]=0;
                rest-=tmp;val[i]-=tmp;val[i^1]+=tmp;
            }
            cur[x]=i;
        }
        return flow-rest;
    }
    void solve()
    {
        int flow=0;
        while(getd())
            while(flow=dinic(s,maxn))maxflow+=flow;
    }
}o;
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        char s[maxn];scanf("%s",s+1);
        for(int j=1;j<=m;j++)
        if(s[j]=='#'){ans++;a[i][j]=1;}
    }
    o.build();
    o.solve();
    printf("%d",ans-o.cnt+o.maxflow);
    return 0;
}