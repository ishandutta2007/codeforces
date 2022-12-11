#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct list
{
	int v[1000010];
	int w[1000010];
	int t[1000010];
	int h[500010];
	int n;
	list()
	{
		n=0;
		memset(h,0,sizeof h);
	}
	void add(int x,int y,int z)
	{
		n++;
		v[n]=y;
		w[n]=z;
		t[n]=h[x];
		h[x]=n;
	}
};
list l;
int f[500010];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
int d[500010];
int g[500010];
int ans[500010];
void dfs(int x,int fa)
{
	if(d[x]!=-1)
		g[x]=d[x];
	else
		g[x]=0;
	int i;
	for(i=l.h[x];i;i=l.t[i])
		if(l.v[i]!=fa)
		{
			dfs(l.v[i],x);
			if(~d[l.v[i]]&&g[l.v[i]])
			{
				g[x]^=1;
				ans[l.w[i]]=1;
			}
		}
}
int main()
{
	int s=1;
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
	{
		f[i]=i;
		scanf("%d",&d[i]);
		if(d[i]==-1)
			s=i;
	}
	int x,y;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(find(x)!=find(y))
		{
			l.add(x,y,i);
			l.add(y,x,i);
			f[find(x)]=find(y);
		}
	}
	memset(ans,0,sizeof ans);
	dfs(s,0);
	if(d[s]!=-1&&g[s])
		printf("-1\n");
	else
	{
		int sz=0;
		for(i=1;i<=m;i++)
			if(ans[i])
				sz++;
		printf("%d\n",sz);
		for(i=1;i<=m;i++)
			if(ans[i])
				printf("%d\n",i);
	}
	return 0;
}