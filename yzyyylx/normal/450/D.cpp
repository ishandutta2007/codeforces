#include<bits/stdc++.h>
#define ll long long
#define M 1000000000000000000
#define N 100005
using namespace std;

ll n,m,K,p[N],d[N];
bool vis[N];
vector<pair<int,int> > g[N];
queue<int>que;

int main()
{
	int	u,v,x,i,j;
	cin>>n>>m>>K;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&x);
		g[u].push_back(make_pair(v,x));
		g[v].push_back(make_pair(u,x));
	}
	for(i=0;i<=n;i++)
	{
		d[i]=M;
	}
	d[1]=0;
	
	memset(p,0,sizeof(p));
	vis[1]=true;
	que.push(1);
	
	for(i=1;i<=K;i++)
	{
		scanf("%d%d",&u,&x);
		if(d[u]>x)
		{
			d[u]=x;
			p[u]=1;
			if(vis[u]==false)
			{
				vis[u]=true;
				que.push(u);
			}
		}
	}
	
	while(que.empty()==false) 
	{
		u=que.front();
		que.pop();
		vis[u]=false;
		
		for(i=0;i<g[u].size();i++)
		{
			v=g[u][i].first;
			x=g[u][i].second;
			
			if(d[v]>=d[u]+x&&p[v]!=0)
				p[v]=0;
			
			if(d[v]>d[u]+x)
			{
				d[v]=d[u]+x;
				if(vis[v]==false)
				{
					vis[v]=true;
					que.push(v);
				}
			}
		}
	}
	
	for(i=1;i<=n;i++)
		K-=p[i];
	cout<<K;
}