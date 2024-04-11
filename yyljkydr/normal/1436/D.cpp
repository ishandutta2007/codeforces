#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N];

vector<int>g[N];

int lf[N];

long long s[N];

long long ans;

void dfs(int x)
{
	if(!g[x].size())
		lf[x]=1;
	s[x]=a[x];
	for(auto v:g[x])
	{
		dfs(v);
		lf[x]+=lf[v];
		s[x]+=s[v];
	}
	ans=max(ans,(s[x]+lf[x]-1)/lf[x]);
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		g[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1);	
	printf("%lld\n",ans);
}