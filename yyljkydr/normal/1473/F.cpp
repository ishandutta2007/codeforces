#include<bits/stdc++.h>
using namespace std;

const int N=6e3+1e2+7;

int head[N],cnt=1,S,T;

struct Edge{
    int ne,to,w;
}edg[200001];

void build(int u,int v,int w)
{
    ++cnt;
    edg[cnt].to=v;
    edg[cnt].w=w;
    edg[cnt].ne=head[u];
    head[u]=cnt;
    ++cnt;
    edg[cnt].to=u;
    edg[cnt].w=0;
    edg[cnt].ne=head[v];
    head[v]=cnt;
}

queue<int>q;

int d[N];

bool bfs()
{
    fill(d+S,d+T+1,-1);
    d[S]=0;
    q.push(S);
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
        {
            int v=edg[tmp].to;
            if(d[v]==-1&&edg[tmp].w)
            {
                d[v]=d[i]+1;
                q.push(v);
            }
        }
    }
    return d[T]!=-1;
}

int dinic(int i,int mn)
{
    if(!mn||i==T)
        return mn;
    int flow=0,tmpf;
    for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
    {
        int v=edg[tmp].to;
        if(d[v]==d[i]+1&&(tmpf=dinic(v,min(mn,edg[tmp].w)))>0)
        {
            flow+=tmpf;
            mn-=tmpf;
            edg[tmp].w-=tmpf;
            edg[tmp^1].w+=tmpf;
        }
        if(!mn)
            break;
    }
    if(!flow)
        d[i]=-1;
    return flow;
}

int n,a[N],b[N],vis[N];

int main()
{
    scanf("%d",&n);
    S=0,T=n*2+1;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>=0)
        {
            ans+=b[i];
            build(S,i,b[i]);
        }
        else
            build(i,T,-b[i]);
        fill(vis+1,vis+100+1,0);
        for(int j=i-1;j>=1;j--)
            if(a[i]%a[j]==0&&!vis[a[j]])
            {
                build(i,j,0x7fffffff);
                vis[a[j]]=1;
            }
    }
    while(bfs())
        ans-=dinic(S,0x7fffffff);
    printf("%d\n",ans);
}