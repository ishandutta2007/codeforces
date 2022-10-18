#include <bits/stdc++.h>

using namespace std;

const int N=105;

int mark[N],hi[N],pa[N];
vector<int> adj[N];
vector<int> v;
int n,k;

void dfs0(int x)
{
	for(int i:adj[x])
	{
		hi[i]=hi[x]+1;
		dfs0(i);
	}
}

void dfs(int x)
{
	v.push_back(x);
	for(int i:adj[x])
		if(mark[i]==1)
			dfs(i);
	for(int i:adj[x])
		if(mark[i]==2)
			dfs(i);
	if(mark[x]==1) v.push_back(pa[x]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			adj[i].clear(); mark[i]=0;
		}
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&pa[i]);
			adj[pa[i]].push_back(i);
		}
		hi[1]=1;
		dfs0(1);
		int ans=0,ansi=-1;
		for(int i=1;i<=n;i++)
		{
			if(hi[i]>ans&&hi[i]<=k)
			{
				ans=hi[i]; ansi=i;
			}
		}
		int cur=k-1;
		while(ansi!=1)
		{
			mark[ansi]=2; cur--;
			ansi=pa[ansi];
		}
		mark[1]=2;
		queue<int> q;
		q.push(1);
		while(q.size()&&cur)
		{
			int x=q.front(); q.pop();
			if(!mark[x])
			{
				mark[x]=1;
				cur--;
			}
			for(int i:adj[x])
				q.push(i);
		}
		dfs(1);
		printf("%d\n",(int)v.size()-1);
		for(int i:v)
			printf("%d ",i);
		puts(""); v.clear();
	}
}