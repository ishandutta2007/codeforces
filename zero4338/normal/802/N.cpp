#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=2205;
const int inf=2e9+10;
int n,k;
int a[maxn],b[maxn];
struct network_flow
{
    static const int maxm=1e5;
    int s,t;
    int maxflow;ll mincost;
    int head[maxn],ver[maxm],nxt[maxm],val[maxm],cost[maxm],tot=1;
    void add(int x,int y,int z,int c){ver[++tot]=y;val[tot]=z;cost[tot]=c;nxt[tot]=head[x];head[x]=tot;}
    void link(int x,int y,int z,int c){add(x,y,z,c);add(y,x,0,-c);}
    int incf[maxn],dis[maxn],pre[maxn];bool v[maxn];
    queue<int>q;
    bool spfa()
    {
        for(int i=1;i<=n+3;i++)dis[i]=inf;
        for(int i=1;i<=n+3;i++)v[i]=0;
        q.push(s);v[s]=1;dis[s]=0;incf[s]=maxn;
        while(!q.empty())
        {
            int x=q.front();q.pop();v[x]=0;
            for(int i=head[x];i;i=nxt[i])
            {
                if(val[i]&&(ll)dis[ver[i]]>(ll)dis[x]+cost[i])
                {
                    dis[ver[i]]=dis[x]+cost[i];
                    incf[ver[i]]=min(incf[x],val[i]);
                    pre[ver[i]]=i;
                    if(!v[ver[i]]){q.push(ver[i]);v[ver[i]]=1;}
                }
            }
        }
        return dis[t]!=inf;
    }
    void update()
    {
        int x=t;
        while(x!=s)
        {
            int i=pre[x];
            val[i]-=incf[t];
            val[i^1]+=incf[t];
            x=ver[i^1];
        }
        maxflow+=incf[t];
        mincost=mincost+incf[t]*dis[t];
    }
    void solve(){while(spfa())update();}
}o;
int main()
{
    n=read();k=read();
    o.s=n+1;o.t=n+2;
    for(int i=1;i<=n;i++)o.link(o.s,i,1,read());
    for(int i=1;i<=n;i++)o.link(i,o.t,1,read());
    for(int i=1;i<=n-1;i++)o.link(i,i+1,maxn,0);
    o.t=n+3;o.link(n+2,o.t,k,0);
    o.solve();
    printf("%lld",o.mincost);
    return 0;
}