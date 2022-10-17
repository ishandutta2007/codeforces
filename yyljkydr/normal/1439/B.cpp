#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m,k,vis[N];

unordered_set<int>g[N];

queue<int>q;

bool chk(int x)
{
	vector<int>ver;
	ver.push_back(x);
	for(auto v:g[x])
		ver.push_back(v);
	for(int i=0;i<ver.size();i++)
		for(int j=i+1;j<ver.size();j++)
			if(g[ver[i]].find(ver[j])==g[ver[i]].end())
				return 0;
	printf("%d\n",2);
	for(auto x:ver)
		printf("%d ",x);
	puts("");
	return 1;
}

int solve()
{
	for(int i=1;i<=n;i++)
		vis[i]=0;
	while(!q.empty())
		q.pop();
	for(int i=1;i<=n;i++)
		if(g[i].size()<k)
		{
			q.push(i),vis[i]=1;
			if(g[i].size()==k-1)
			{
				if(chk(i))
					return 2;
			}
		}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto v:g[x])
		{
			g[v].erase(x);
			if(g[v].size()==k-1)
			{
				q.push(v),vis[v]=1;
				if(chk(v))
					return 2;
			}
		}
		g[x].clear();
	}
	vector<int>ans;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			ans.push_back(i);
	if(ans.size())
	{
		printf("%d %d\n",1,ans.size());
		for(auto x:ans)
			printf("%d ",x);
		puts("");
		return 1;
	}
	return -1;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].insert(v);
			g[v].insert(u);
		}
		if(1ll*k*(k-1)/2>m)
		{
			puts("-1");
			continue;
		}
		int x=solve();
		if(x==-1)
			puts("-1");
	}
}