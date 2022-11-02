#include<bits/stdc++.h>
#define maxn 200050
#define sz(i)	(c0[i]+c1[i])
using namespace std;
typedef long long LL;

int n;

vector<int> G[maxn];

void init()
{
	scanf("%d",&n);
	for (int k=1;k<n;++k)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

LL len[maxn];
LL c0[maxn],c1[maxn];

LL ans;

void dfs(int i,int fa=0)
{
	++c0[i];
	for (auto j:G[i])
	{
		if (fa==j)	continue;
		dfs(j,i);
		ans+=c0[i]*c0[j]+c1[i]*c1[j];
		ans+=len[i]*sz(j)+len[j]*sz(i)+sz(i)*sz(j);
		len[i]+=len[j]+sz(j);
		c0[i]+=c1[j];
		c1[i]+=c0[j];
	}
}

void solve()
{
	dfs(1);
	printf("%lld\n",ans>>1);
}

int main()
{
	init();
	solve();
	return 0;
}