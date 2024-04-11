#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5;
int T,n,p[maxn],sz,a,b,da,db; 
struct edge
{
	int v,nxt;
	edge(int vv=0,int nn=0){v=vv,nxt=nn;}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
int dis[maxn];
inline void dfs(int u,int fa)
{
	REP(u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dis[v]=dis[u]+1;
		dfs(v,u);
	}
}
int main()
{
	T=getint();
	while(T--)
	{
		n=getint();
		sz=0;
		FOR(i,1,n)p[i]=-1;
		a=getint(),b=getint(),da=getint(),db=getint();
		FOR(i,1,n-1)
		{
			int u=getint(),v=getint();
			add(u,v);
			add(v,u);
		}
		FOR(i,1,n)dis[i]=0;
		dfs(b,0);
		int maxpos,maxdis=0;
		if(dis[a]<=da)
		{
			printf("Alice\n");
			continue;
		}
		FOR(i,1,n)if(dis[i]>maxdis)maxpos=i,maxdis=dis[i];
		FOR(i,1,n)dis[i]=0;
		dis[maxpos]=0;
		dfs(maxpos,0);
		FOR(i,1,n)if(dis[i]>maxdis)maxdis=dis[i];
		if(db<=da*2)printf("Alice\n");
		else if(maxdis<=2*da)printf("Alice\n");
		else printf("Bob\n");
		FOR(i,1,n)dis[i]=0;
	}
	return 0;
}