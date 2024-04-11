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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=4e5+5;
int n,m,a[maxn],cnt;
char t[maxn];
set<int>S[maxn];
vector<vector<int>>id;
inline void input()
{
	n=gi(),m=gi();
	id.resize(n+1);
	FOR(i,1,n)id[i].resize(m+1);
	FOR(i,1,n)
	{
		scanf("%s",t+1);
		FOR(j,1,m)if(t[j]=='#')S[j].insert(i),id[i][j]=++cnt;
	}
	FOR(i,1,m)a[i]=gi();
}
vector<int>e[maxn];
int scc[maxn],d[maxn],scc_cnt,dfn[maxn],low[maxn],tot;
stack<int>stk;
inline void tarjan(int u)
{
	stk.push(u);
	dfn[u]=low[u]=++tot;
	for(int v:e[u])
	{
		if(scc[v])continue;
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		++scc_cnt;
		//cerr<<":"<<u<<' '<<scc_cnt<<endl;
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
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(id[i][j]==0)continue;
			int x=id[i][j];
			if(S[j].count(i-1))e[x].pb(id[i-1][j]);
			auto it=S[j].upper_bound(i);
			if(it!=S[j].end())e[x].pb(id[*it][j]);
			if(j>1)
			{
				it=S[j-1].lower_bound(i);
				if(it!=S[j-1].end())e[x].pb(id[*it][j-1]);
			}
			if(j<m)
			{
				it=S[j+1].lower_bound(i);
				if(it!=S[j+1].end())e[x].pb(id[*it][j+1]);
			}
		}
	}
	//FOR(i,1,n)FOR(j,1,m)printf("id[%d][%d]=%d\n",i,j,id[i][j]);
	//FOR(i,1,cnt)for(int j:e[i])printf("%d %d\n",i,j);
	FOR(i,1,cnt)if(!dfn[i])tarjan(i);
	//FOR(i,1,cnt)printf("%d %d\n",dfn[i],low[i]);
	//FOR(i,1,cnt)printf("scc[%d]=%d\n",i,scc[i]);
	FOR(u,1,cnt)
	{
		for(int x:e[u])
		{
			if(scc[u]==scc[x])continue;
			else d[scc[x]]++;
		}
	}
	int ans=0;
	FOR(i,1,scc_cnt)ans+=d[i]==0;
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}