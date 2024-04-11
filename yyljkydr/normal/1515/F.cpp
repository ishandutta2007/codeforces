#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int n,m,X,fa[N],u[N],v[N],use[N];

ll sz[N];

vector<int>e[N];

typedef pair<ll,int> pii;
#define fs first
#define sd second
#define mp make_pair

queue<int>q;

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d%d%d",&n,&m,&X);
	for(int i=1;i<=n;i++)
		scanf("%lld",&sz[i]),fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		e[u[i]].push_back(i);
		e[v[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
		q.push(i);
	vector<int>ans;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		int fx=find(x);
		if(fx!=x)
			continue;
		if(sz[fx]<X)
			continue;
		while(e[fx].size()&&use[e[fx].back()])
			e[fx].pop_back();
		if(!e[fx].size())
			continue;
		while(e[fx].size()&&find(u[e[fx].back()])==find(v[e[fx].back()]))
			e[fx].pop_back();
		if(!e[fx].size())
			continue;
		int fu=find(u[e[fx].back()]),fv=find(v[e[fx].back()]);
		use[e[fx].back()]=1;
		ans.push_back(e[fx].back());
		e[fx].pop_back();
		assert(fu!=fv);
		if(e[fu].size()>e[fv].size())
			swap(fu,fv);
		fa[fu]=fv;
		sz[fv]+=sz[fu]-X;
		for(auto x:e[fu])
			e[fv].push_back(x);
		if(sz[fv]>X)
			q.push(fv);
	}
	for(int i=1;i<=m;i++)
	{
		if(use[i])
			continue;
		int fu=find(u[i]),fv=find(v[i]);
		if(fu==fv)
			continue;
		if(sz[fu]+sz[fv]<X)
			continue;
		sz[fu]+=sz[fv]-X;
		fa[fv]=fu;
		ans.push_back(i);
	}
	if(ans.size()!=n-1)
		puts("NO");
	else
	{
		puts("Yes");
		for(auto x:ans)
			printf("%d\n",x);
	}
}