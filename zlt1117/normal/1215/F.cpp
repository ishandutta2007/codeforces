#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
//#define gc getchar()
#define iter set<int>::iterator
#define yes(x) (x)
#define no(x) (x+p+M+5)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=2e6+5;
int n,p,M,m,x,y;
int dfn[maxn],low[maxn],scc[maxn],tot,cnt;
vector<int>e[maxn];
stack<int>stk;
inline void tarjan(int u)
{
	dfn[u]=low[u]=++tot,stk.push(u);
	for(int v:e[u])
	{
		if(scc[v])continue;
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++cnt;
		//printf("%d:",cnt);
		while(1)
		{
			int x=stk.top();
			stk.pop();
			scc[x]=cnt;
			//printf("%d ",x);
			if(x==u)break;
		}
		//puts("");
	}
}
inline bool two_SAT()
{
	FOR(i,1,2*(p+M+5))if(!dfn[i])tarjan(i);
	//FOR(i,1,p+M+5)printf("%d %d\n",scc[yes(i)],scc[no(i)]);
	FOR(i,1,p+M)if(scc[yes(i)]==scc[no(i)])return false;
	return true;
}
inline void input()
{
	n=gi(),p=gi(),M=gi(),m=gi();
	FOR(i,1,n)
	{
		int x=gi(),y=gi();
		e[no(x)].pb(yes(y));
		e[no(y)].pb(yes(x));
	}
	FOR(i,1,p)
	{
		int l=gi(),r=gi();
		e[yes(i)].pb(no(p+l));
		e[yes(i)].pb(yes(p+r+1));
		e[yes(p+l)].pb(no(i));
		e[no(p+r+1)].pb(no(i));
	}
	e[yes(p+1)].pb(no(p+1));
	FOR(i,p+1,p+M+1)e[yes(i)].pb(yes(i+1));
	FOR(i,p+1,p+M+1)e[no(i+1)].pb(no(i));
	FOR(i,1,m)
	{
		int x=gi(),y=gi();
		e[yes(x)].pb(no(y));
		e[yes(y)].pb(no(x));
	}
	//FOR(i,1,p)printf("%d %d\n",yes(i),no(i));
}
inline void solve()
{
	if(!two_SAT())puts("-1");
	else
	{
		vector<int>v;
		FOR(i,1,p)if(scc[yes(i)]<scc[no(i)])v.pb(i);
		int k=0;
		FOR(i,1,M)if(scc[yes(i+p+1)]<scc[no(i+p+1)]){k=i;break;}
		printf("%d %d\n",sz(v),k);
		for(int x:v)printf("%d ",x);
		puts("");
	}
}
int main()
{
	input();
	solve();
	return 0;
}