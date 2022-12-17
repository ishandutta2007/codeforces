#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define pb push_back
#define PII pair<int,int>
#define db double
#define ll long long
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int> 
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int maxn=1e5+5;
int n,m,u,v,d;
ll dis[maxn],last[maxn],tag[maxn];
int son[maxn][2],fa[maxn];
vector<pair<int,int> >e[maxn];
struct node{ll l,r;}a[maxn*20];///O(n+mlogn) 
int cnt,dir[maxn],tim[maxn],s[maxn],t[maxn];///direction time
inline bool operator < (const node &a,const node &b){return a.r>b.r;}
inline void dfs(int u,int f)
{
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==f)continue;
		dis[v]=dis[u]+w;
		last[v]=-dis[v];///attention let the first train start at -dis[v]
		son[u][1]=v;///love edge
		fa[v]=u;
		dfs(v,u);
	}
}
inline bool nroot(int x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
inline void pushr(int u,ll v)
{
	if(!u)return ;
	tag[u]=last[u]=v;
}
inline void pushdown(int u)
{
	if(tag[u])
	{
		pushr(son[u][0],tag[u]);
		pushr(son[u][1],tag[u]);
		tag[u]=0;
	}
}
inline void rotate(int x)
{
	int y=fa[x],z=fa[y],k=son[y][1]==x;
	fa[x]=z;if(nroot(y))son[z][son[z][1]==y]=x;
	son[y][k]=son[x][k^1],fa[son[x][k^1]]=y;
	son[x][k^1]=y,fa[y]=x;
}
inline void pushall(int x)
{
	if(nroot(x))pushall(fa[x]);
	pushdown(x); 
}
inline void splay(int x)
{
	pushall(x);
	while(nroot(x))
	{
		int y=fa[x],z=fa[y];
		if(nroot(y))
		{
			if((son[z][1]==y)^(son[y][1]==x))rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
} 
inline void access(int x,int t)
{
	int u=x;
	for(int y=0;x;y=x,x=fa[x])
	{
		splay(x);
		if(y)
		{
//			cerr<<u<<" "<<x<<" "<<y<<" ["<<last[x]+dis[x]+1<<","<<t+dis[x]<<"]\n";
			a[++cnt]={last[x]+dis[x]+1,t+dis[x]};
			son[x][1]=y;
		}
	}
	splay(u);
	pushr(son[u][0],t);///the lighter
}
inline void init()
{
	
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi(),w=gi();
		e[u].pb({v,w});e[v].pb({u,w});
	}
	dfs(1,0);
}
inline void solve()
{
	FOR(i,1,m)s[i]=gi(),t[i]=gi();
	FOR(i,1,m)
	{
		//int last=cnt;
		access(s[i],t[i]); 
		//FOR(j,last+1,cnt)cerr<<a[j].l<<" "<<a[j].r<<endl;=
	}
	sort(a+1,a+cnt+1,[](node x,node y){return x.l<y.l;});
	priority_queue<node>pq;
	ll now=0,day=a[1].l,ans=0;
	while(1)
	{
		while(now<cnt&&a[now+1].l==day)pq.push(a[++now]);
		if(!pq.empty())
		{
			node x=pq.top();pq.pop();
			if(x.r<day)
			{
				ans=0;
				FOR(j,1,cnt)if(a[j].r<x.r)ans++;
				printf("%lld %lld\n",x.r,ans);return ;
			}
			ans++;
		}
		else if(now<cnt)day=a[now+1].l-1;
		day++;
		if(ans==cnt)break;
	}
	printf("%d %lld\n",-1,ans);
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	init();
	input();
	solve();
	return 0;
}