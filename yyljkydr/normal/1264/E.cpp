#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1<<30)
#define DSSSS 11111
#define SDDSSDD 111111*4
/*
#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

int n,a,b,c,d;

int ans[N];

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a+b+c+d==1)
	{
		puts("YES");
		if(a)
			puts("0");
		else if(b)
			puts("1");
		else if(c)
			puts("2");
		else if(d)
			puts("3");
	}
	int oa=a,ob=b,oc=c,od=d;
	n=a+b+c+d;
	if(a>b||d>c)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=a*2;i+=2)
		ans[i]=0,ans[i+1]=1;
	b-=a,a=0;
	for(int i=n;i>n-d*2;i-=2)
		ans[i]=3,ans[i-1]=2;
	c-=d,d=0;
	if(c-b>1||b-c>1)
	{
		puts("NO");
		return 0;
	}
	for(int i=oa*2+1;i<=oa*2+min(c,b)*2;i+=2)
		ans[i]=2,ans[i+1]=1;
	int mn=min(b,c);
	b-=mn,c-=mn;
	if(c||b)
	{
		if(b)
		{
			for(int i=oa*2+mn*2+1;i>1;i--)
				ans[i]=ans[i-1];
			ans[1]=1;
		}
		else if(c)
		{
			for(int i=oa*2+mn*2+1;i<n;i++)
				ans[i]=ans[i+1];
			ans[n]=2;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}	 
*/
struct Edge
{
    int u,v,cap,cost,txtxtx;
}edge[SDDSSDD];
int vs,vt,NV,NE,head[DSSSS];
void addEdge(int u,int v,int cap,int cost)
{
    edge[NE].u=u; edge[NE].v=v; edge[NE].cap=cap; edge[NE].cost=cost;
    edge[NE].txtxtx=head[u]; head[u]=NE++;
    edge[NE].u=v; edge[NE].v=u; edge[NE].cap=0; edge[NE].cost=-cost;
    edge[NE].txtxtx=head[v]; head[v]=NE++;
}
int d[DSSSS],pre[DSSSS];
bool vis[DSSSS];
bool SPFA()
{
    for(int i=0; i<NV; ++i)
	{
        d[i]=INF; vis[i]=0;
    }
    d[vs]=0; vis[vs]=0;
    queue<int> que;
    que.push(vs);
    while(!que.empty())
	{
        int u=que.front(); que.pop();
        for(int i=head[u]; i!=-1; i=edge[i].txtxtx)
		{
            int v=edge[i].v;
            if(edge[i].cap && d[v]>d[u]+edge[i].cost
			){
                d[v]=d[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
        vis[u]=0;
    }
    return d[vt]!=INF;
}
int MCMF()
{
    int res=0;
    while(SPFA()){
        int flow=INF,cost=0;
        for(int u=vt; u!=vs; u=edge[pre[u]].u)
            flow=min(flow,edge[pre[u]].cap);
        for(int u=vt; u!=vs; u=edge[pre[u]].u)
		{
            edge[pre[u]].cap-=flow;
            edge[pre[u]^1].cap+=flow;
            cost+=flow*edge[pre[u]].cost;
        }
        res+=cost;
    }
    return res;
}
int ans[111][111],g[1111][1111];

int main()
{
    int n,a,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++)
    		g[i][j]=i==j?0:2;
    for(int i=1,u,v;i<=m;i++)
    	scanf("%d%d",&u,&v),g[u-1][v-1]=1,g[v-1][u-1]=0;
    vs=n*n+n; 
	vt=vs+1; 
	NV=vt+1; 
	NE=0;
    memset(head,-1,sizeof(head));
    for(int i=0;i<n;++i)
	{
        int cost=1;
        for(int j=1;j<=n;++j)
		{
            addEdge(n*n+i,vt,1,cost);
            cost+=2;
        }
    }
    for(int i=0;i<n;++i)
	{
        for(int j=0;j<n;++j)
		{
            a=g[i][j];
            if(i>=j) continue;
            addEdge(vs,i*n+j,1,0);
            if(a==1)
            	addEdge(i*n+j,n*n+i,1,0);
			else if(a==0)
                addEdge(i*n+j,n*n+j,1,0);
            else
			{
                addEdge(i*n+j,n*n+i,1,0);
                addEdge(i*n+j,n*n+j,1,0);
            }
        }
    }
//    printf("%d\n",n*(n-1)*(n-2)/6-(MCMF()-(n-1)*n/2)/2);
    MCMF();
    for(int x=0; x<n; ++x)
	{
        for(int y=x+1; y<n; ++y)
		{
            for(int i=head[x*n+y]; i!=-1; i=edge[i].txtxtx){
                if(i&1 || edge[i].cap) continue;
                if(edge[i].v==x+n*n)
				{
                    ans[x][y]=1; 
					ans[y][x]=0;
                }
				else
				{
                    ans[x][y]=0; 
					ans[y][x]=1;
                }
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j) printf("%d",ans[i][j]);
        putchar('\n');
    }
    return 0;
}