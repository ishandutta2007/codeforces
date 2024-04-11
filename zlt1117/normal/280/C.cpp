#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<stack>
#include<cmath>
#define LL long long
using namespace std;
struct edge{
	int nxt,v;
	edge(int vv=0,int nn=0){v=vv,nxt=nn;}
}e[200010];
int p[100010],tot;
inline void add(int x,int y)
{
	tot++;
	e[tot]=edge(y,p[x]);
	p[x]=tot;
}
int n,a,b,d[100010];
inline void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	for(int i=p[x];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,x);
	}
}
int main()
{
	memset(p,-1,sizeof(p));
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),add(a,b),add(b,a);
	d[1]=1;
	dfs(1,0);
	double ans=0.0;
	for(int i=1;i<=n;i++) ans+=1.0/d[i];
	printf("%.10lf",ans);
	return 0;
}