//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e6+5;
int n,m;
vector<int>e[maxn];
vector<int>pa,pb;
stack<int>stk;
int dfn[maxn],low[maxn],tot,scc[maxn],scc_cnt;
inline void init()
{
	FOR(i,1,n)e[i].clear();
	pa.clear(),pb.clear();
	FOR(i,1,n)dfn[i]=low[i]=scc[i]=0;
	tot=scc_cnt=0;
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		e[u].pb(v);
	}
}
inline void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	stk.push(u);
	for(int v:e[u])
	{
		if(scc[v])continue;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++scc_cnt;
		while(1)
		{
			int x=stk.top();
			stk.pop();
			scc[x]=scc_cnt;
			if(x==u)break;
		}
	}
}
inline void solve()
{
	FOR(i,1,n)if(!dfn[i])tarjan(i);
	if(scc_cnt==1)puts("NO");
	else
	{
		FOR(i,1,n)
		{
			if(scc[i]==1)pa.pb(i);
			else pb.pb(i);
		}
		printf("YES\n%d %d\n",sz(pa),sz(pb));
		for(int x:pa)printf("%d ",x);
		puts("");
		for(int x:pb)printf("%d ",x);
		puts("");
	}
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}