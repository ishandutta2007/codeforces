//#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdlib>
using namespace std;
const int maxn=1e6+5;
int p[maxn],sz,n,val[maxn],root,sum;
int ok[maxn];
int now[maxn];
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void dfs(int u,int last)
{
	now[u]=val[u];
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		dfs(v,i);
		now[u]+=now[v];
		if(ok[v])
		{
			if(ok[u])
			{
				printf("%d %d\n",ok[u],ok[v]);
				exit(0);
			}
			else ok[u]=ok[v];
		}
	}
	if(now[u]==sum*2&&ok[u]&&sum!=0)
	{
		printf("%d %d\n",last,ok[u]);
		exit(0);
	}
	else if(now[u]==sum)
	{
		ok[u]=last;
	}
}
int main()
{
	memset(p,-1,sizeof(p));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int fa;
		scanf("%d%d",&fa,&val[i]);
		add(fa,i);
		sum+=val[i];
		if(fa==0)root=i;
	}
	if(sum%3!=0)printf("-1\n");
	else
	{
		sum/=3;
		dfs(root,0);
		printf("-1\n");
	}
	return 0;
}