#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n;

int a[N];

vector<int>g[N];

int pre[N],pst[N],dfn,fin,pfn,in[N],tot;

bool cmp(int x,int y)
{
	return a[x]<a[y];
}

long long calc(int x,int d)
{
	long long ret=0;
	if(a[x]<=fin)
		ret+=d;
	for(auto v:g[x])
		ret+=calc(v,d+1);
	return ret;
}

void dfs(int x)
{
	in[x]=++tot;
	if(a[x]>fin)
		++dfn;
	pre[x]=dfn+fin;
	sort(g[x].begin(),g[x].end(),cmp);
	for(auto v:g[x])
		dfs(v);
	pst[x]=++pfn;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	int x;
	fin=max(1,a[1]-1);
	long long ans=calc(1,0);
	for(int i=1;i<=n;i++)
		if(a[i]==fin)
			x=i;
	a[0]=1e9;
	while(g[x].size())
	{
		int p=0;
		for(auto v:g[x])
			if(a[v]>a[x]&&a[v]<a[p])
				p=v;
		if(p!=0)
			swap(a[x],a[p]);
		else
			break;
		x=p;
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		if(a[i]<=fin&&a[i]!=pst[i])
		{
			puts("NO");
			return 0;
		}
	for(int i=1;i<=n;i++)
		if(a[i]>fin&&a[i]!=pre[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d%c",in[i]," \n"[i==n]);
}