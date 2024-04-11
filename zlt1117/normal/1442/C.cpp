#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define int long long
#define ll long long
#define rd (rand()<<16^rand())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5,mod=998244353;
inline ll qpow(ll x,ll k)
{
	ll ret=1;
	while(k)
	{
		if(k&1)ret=(ret*x)%mod;
		k>>=1,x=(x*x)%mod;
	}
	return ret;
}
struct node
{
	int rev,tim;
	node(){rev=tim=0x3f3f3f3f3f3f3f3f;}
	inline bool operator<(const node &b)const
	{
		if(rev<=50&&b.rev<=50)
		{
			ll c1=(1LL<<rev)-1+tim;
			ll c2=(1LL<<b.rev)-1+b.tim;
			return c1<c2;
		}
		else 
		{
			if(rev<b.rev)return 1;
			else if(rev>b.rev)return 0;
			else return tim<b.tim;
		}
	}
}dis[maxn][30];
struct node2
{
	node dis;
	int x;
	node2(node a,int xx=0){dis=a,x=xx;}
	inline bool operator<(const node2 &b)const
	{
		return !(dis<b.dis);
	}
};
priority_queue<node2>pq;
struct edge
{
	int v,nxt,typ;
	edge(int vv=0,int nn=0,int tt=0){v=vv,nxt=nn,typ=tt;}
}e[maxn<<1];
int p[maxn],sz,n,m;
inline void add(int u,int v,int typ)
{
	e[++sz]=edge(v,p[u],typ);
	p[u]=sz;
}
inline void init()
{
	memset(p,-1,sizeof(p));
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		add(u,v,0);add(v,u,1);
	}
}
bool vis[maxn][30];
inline void dijkstra(int u)
{
	node x;dis[1][0].rev=dis[1][0].tim=0;
	x.rev=0,x.tim=0;
	pq.push(node2(x,u));
	while(!pq.empty())
	{
		x=pq.top().dis;u=pq.top().x;
		pq.pop();
		REP(u)
		{
			int v=e[i].v;
			int val=min(28,x.rev)+(x.rev>=28?(x.rev&1):0);
			node now=dis[u][val];
			if(e[i].typ^(now.rev&1))
			{
				now.rev++;now.tim++;
				val=min(28,now.rev)+((now.rev>=28)?(now.rev&1):0);
				if(now<dis[v][val])dis[v][val]=now,pq.push(node2(dis[v][val],v));
			}
			else
			{
				now.tim++;
				val=min(28,now.rev)+((now.rev>=28)?(now.rev&1):0);
				if(now<dis[v][val])dis[v][val]=now,pq.push(node2(dis[v][val],v));
			}
		}
	}
}
inline void solve()
{
	dijkstra(1);
	FOR(i,1,29)if(dis[n][i]<dis[n][0])swap(dis[n][0],dis[n][i]);
	ll ans=qpow(2,dis[n][0].rev)-1;
	ans=ans+dis[n][0].tim;
	ans%=mod;
	printf("%lld\n",ans);
}
signed main()
{
	init();
	input();
	solve();
	return 0;
}