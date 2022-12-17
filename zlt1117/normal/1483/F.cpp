#pragma GCC optimize("Ofast")
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
const int maxn=1e6+5;
string s[maxn];
int n,dfn[maxn],low[maxn],tot,son[maxn][26],fa[maxn];
int counter;
namespace BIT
{
	int c[maxn];
	inline void update(int x,int v){while(x<=counter)c[x]+=v,x+=x&-x;}
	inline int query(int x){int ret=0;while(x)ret+=c[x],x-=x&-x;return ret;}
}
vector<int>e[maxn];
int ed[maxn],cur[maxn];///the last substring of the suffix
vector<int>pos[maxn];
inline void insert(string s,int id)
{
	int now=0;
	FOR(i,0,sz(s)-1)
	{
		if(!son[now][s[i]-'a'])son[now][s[i]-'a']=++tot;
		now=son[now][s[i]-'a'];
		pos[id].pb(now);
	}
	ed[now]=id;
}
inline void getfail()
{
	queue<int>q;
	FOR(i,0,25)if(son[0][i])q.push(son[0][i]);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		FOR(i,0,25)
		{
			if(son[u][i])fa[son[u][i]]=son[fa[u]][i],q.push(son[u][i]);
			else son[u][i]=son[fa[u]][i];
		}
		e[fa[u]].pb(u);
	}
}
inline void dfs(int u,int las)
{
	dfn[u]=++counter;
	if(ed[u])las=ed[u];
	cur[u]=las;///the last string that has tag
	for(auto v:e[u])
	{
		dfs(v,las);
	}
	low[u]=counter;
}
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)cin>>s[i],insert(s[i],i);
	getfail();
}
int cnt[maxn],ans;
inline void solve()
{
	dfs(0,0);
	FOR(i,1,n)
	{
		vector<int>temp;
		for(auto x:pos[i])BIT::update(dfn[x],1);
		int pre=1e9;
		for(int j=sz(pos[i])-1;j>=0;--j)
		{
			int nowp=j==sz(pos[i])-1?cur[fa[pos[i][j]]]:cur[pos[i][j]];///do not position myslef
			int l=j-sz(s[nowp])+1;
			if(pre>l)pre=l,cnt[nowp]++,temp.pb(nowp);
		}
		cnt[0]=0;
		for(auto x:temp)
		{
			if(cnt[x]==0)continue;
			int now=BIT::query(low[pos[x].back()])-BIT::query(dfn[pos[x].back()]-1);
			if(now==cnt[x])ans++;
			cnt[x]=0;
		}
		for(auto x:pos[i])BIT::update(dfn[x],-1);
	}
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}