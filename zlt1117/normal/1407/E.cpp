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
#define gi getint()
#define inf 0x3f3f3f3f
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
const int maxn=5e5+5;
struct edge
{
	int v,nxt,w;
	edge(int vv=0,int nn=0,int ww=0){v=vv,nxt=nn,w=ww;}
}e[maxn<<1];
int p[maxn],sz;
inline void add(int u,int v,int w)
{
	e[++sz]=edge(v,p[u],w);
	p[u]=sz;
}
queue<int>q;
bool vis[maxn];
int dis[maxn],n,m,col[maxn];
inline void spfa()
{
	q.push(n);
	vis[n]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		REP(u)
		{
			int v=e[i].v;
			if(vis[v])continue;
			if(!col[v]||col[v]==2-e[i].w)col[v]=2-e[i].w;/// 
			else dis[v]=dis[u]+1,q.push(v),vis[v]=1;
		}
	}
}
int main()
{
	memset(p,-1,sizeof(p));
	n=getint(),m=getint();
	FOR(i,1,m)
	{
		int u=getint(),v=getint(),w=getint();
		add(v,u,w);
	}
	spfa();
	if(vis[1]==0)printf("-1\n");
	else printf("%d\n",dis[1]);
	FOR(i,1,n)printf("%d",col[i]==0?0:col[i]-1);
	printf("\n");
	return 0;
}///