#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int head[N],cnt;

struct Edge{
	int ne,to,w;
}edg[N*2+1];

void build(int u,int v,int w)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	edg[cnt].w=w;
	head[u]=cnt;
}

int n,m;

ll d[N][2][2];

struct Node{
	int x,a,b;
	ll w;
	Node(int _x=0,int _a=0,int _b=0,ll _w=0){x=_x,a=_a,b=_b,w=_w;}
};

bool operator <(Node u,Node v)
{
	return u.w>v.w;
}

priority_queue<Node>q;

void dijkstra()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				d[i][j][k]=1e15;
	d[1][0][0]=0;
	q.push(Node(1,0,0,0));
	while(!q.empty())
	{
		Node u=q.top();
		q.pop();
		int x=u.x,a=u.a,b=u.b;
		if(d[x][a][b]!=u.w)
			continue;
		for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(d[v][a][b]>d[x][a][b]+edg[tmp].w)
			{
				d[v][a][b]=d[x][a][b]+edg[tmp].w;
				q.push(Node(v,a,b,d[v][a][b]));
			}
			if(!a&&d[v][a+1][b]>d[x][a][b])
			{
				d[v][a+1][b]=min(d[v][a+1][b],d[x][a][b]);
				q.push(Node(v,a+1,b,d[v][a+1][b]));
			}
			if(!b&&d[v][a][b+1]>d[x][a][b]+edg[tmp].w*2)
			{
				d[v][a][b+1]=min(d[v][a][b+1],d[x][a][b]+edg[tmp].w*2);
				q.push(Node(v,a,b+1,d[v][a][b+1]));
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		build(u,v,w);
		build(v,u,w);
	}
	dijkstra();
	for(int tmp=head[1];tmp;tmp=edg[tmp].ne)
		d[edg[tmp].to][1][1]=min(d[edg[tmp].to][1][1],(ll)edg[tmp].w);
	for(int i=2;i<=n;i++)
		printf("%lld%c",d[i][1][1]," \n"[i==n]);
}