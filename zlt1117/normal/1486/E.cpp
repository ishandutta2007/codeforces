#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m;
vector<pair<int,int> >e[maxn];
ll dis[51][maxn];
bool vis[51][maxn];
struct node
{
	int typ,u;ll dis;
	inline bool operator < (const node &b)const
	{
		return dis>b.dis;
	}
};
priority_queue<node>pq;
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi(),w=gi();
		e[u].pb({v,w});
		e[v].pb({u,w});
	}
}
inline void solve()
{
	memset(dis,0x3f,sizeof(dis));
	dis[0][1]=0;
	pq.push({0,1,0});
	while(!pq.empty())
	{
		node x=pq.top();
		pq.pop();
		if(vis[x.typ][x.u])continue;
		vis[x.typ][x.u]=1;
		int u=x.u;
		for(auto xx:e[u])
		{
			int w=xx.second,v=xx.first;
			if(x.typ==0)
			{
				if(dis[w][v]>dis[0][u])
				{
					dis[w][v]=dis[0][u];
					pq.push({w,v,dis[w][v]});
				}
			}
			else
			{
				if(dis[0][v]>dis[x.typ][u]+(w+x.typ)*(w+x.typ))
				{
					dis[0][v]=dis[x.typ][u]+(w+x.typ)*(w+x.typ);
					pq.push({0,v,dis[0][v]});
				}
			}
		}
	}
	FOR(i,1,n)
	{
		if(dis[0][i]>=inf)printf("-1 ");
		else printf("%lld ",dis[0][i]);
	}
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}