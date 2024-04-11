#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
struct edge
{
	int u,v,l;
}e[101000]={};
bool cmp(edge e1,edge e2)
{
	return e1.l<e2.l;
}
int n,m,k,c[505]={},root[101000]={},f[505][505]={},t[101000]={};
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)
	{	
		scanf("%d",&c[i]);
		c[i]+=c[i-1];
	}
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
	sort(e+1,e+m+1,cmp);
}
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
bool check()
{
	int p=1;
	for(int i=1;i<=n;++i)
		root[i]=i;
	while(e[p].l==0)
	{
		int u_root=get_root(e[p].u);
		int v_root=get_root(e[p].v);
		if(u_root != v_root)
			root[u_root]=v_root;
		++p;
	}
	for(int i=1;i<=k;++i)
	{
		int s=get_root(c[i-1]+1);
		t[c[i-1]+1]=i;
		for(int j=c[i-1]+2;j<=c[i];++j)
		{	
			t[j]=i;
			if(get_root(j)!=s)
				return false;
		}
	}
	return true;
}
void work()
{
	for(int i=1;i<=k;++i)
		for(int j=1;j<=k;++j)
			f[i][j]=0x3fffffff;
	for(int i=1;i<=k;++i)
		f[i][i]=0;
	for(int i=1;i<=m;++i)
	{
		e[i].u=t[e[i].u];
		e[i].v=t[e[i].v];
		if(e[i].l<f[e[i].u][e[i].v])
			f[e[i].u][e[i].v]=f[e[i].v][e[i].u]=e[i].l;
	}
	for(int l=1;l<=k;++l)
		for(int i=1;i<=k;++i)
			for(int j=1;j<=k;++j)
			{
				if(i==j || j==l || i==l)
					continue;
				if(f[i][l]+f[l][j]<f[i][j])
					f[i][j]=f[i][l]+f[l][j];
			}
	puts("Yes");
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=k;++j)
			printf("%d ",f[i][j]==0x3fffffff ? -1 : f[i][j]);
		printf("\n");
	}
}
int main()
{	
	init();
	if(check())
		work();
	else
		puts("No");
	return 0;
}