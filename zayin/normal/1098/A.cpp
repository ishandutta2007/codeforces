#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
int fa[maxn];
vector<int> G[maxn];

LL a[maxn];
LL s[maxn];
int d[maxn],sz[maxn];

void init()
{
	scanf("%d",&n);
	for (int i=2;i<=n;++i)
	{
		scanf("%d",fa+i);
		G[fa[i]].push_back(i);
	}
	for (int i=1;i<=n;++i)
		scanf("%lld",s+i);
}

LL ans=0;

int dfs(int i)
{
	d[i]=d[fa[i]]+1;
	for (int j:G[i])
		sz[i]+=dfs(j);
	return ++sz[i];
}

void calc(int i)
{
	if (!(d[i]&1))
	{
		if (!G[i].size())	return ;
		a[i]=1LL<<60;
		for (int j:G[i])
			a[i]=min(a[i],s[j]-s[fa[i]]);
		for (int j:G[i])
			a[j]=s[j]-s[fa[i]]-a[i];
	}
	
	if (a[i]<0)
	{
		puts("-1");
		exit(0);
	}
	ans+=a[i];
	for (int j:G[i])
		calc(j);
}

void solve()
{
	dfs(1);
	a[1]=s[1];
	calc(1);
	printf("%lld\n",ans);
}

int main()
{
	init();
	solve();
	return 0;
}