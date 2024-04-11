#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T,n;

vector<int>g[N],h[N];

int dc,st[N],ed[N],rev[N];

void dfs(int x,int f)
{
	st[x]=++dc;
	rev[dc]=x;
	for(auto v:h[x])
	{
		if(v==f)
			continue;
		dfs(v,x);
	}
	ed[x]=dc;
}

set<int>s;

int ans;

void calc(int x,int f)
{
	auto it=s.lower_bound(st[x]);
	bool ok=0;
	int out=0;
	if(it==s.end()||*it>ed[x])
	{
		ok=1;
		if(it!=s.begin())
		{
			it--;
			if(st[x]<=ed[rev[*it]])
				out=*it,s.erase(it);
		}
		s.insert(st[x]);
	}
	ans=max(ans,(int)s.size());
	for(auto v:g[x])
	{
		if(v==f)	
			continue;
		calc(v,x);
	}
	if(ok)
	{
		if(out)
			s.insert(out);
		s.erase(st[x]);
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			g[i].clear(),h[i].clear();
		ans=0;
		for(int i=2;i<=n;i++)
		{
			int u;
			scanf("%d",&u);
			g[u].push_back(i);
		}
		for(int i=2;i<=n;i++)
		{
			int u,v;
			scanf("%d",&u);
			h[u].push_back(i);
		}
		dfs(1,0);
		calc(1,0);
		printf("%d\n",ans);
	}
}