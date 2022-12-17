//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
//#define gc ((p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++)
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e6+5;
int n,p[maxn];
int now[maxn][2];
vector<int>e[maxn];
int fa[maxn],scc[maxn],tot,low[maxn],dfn[maxn],cnt,ans[maxn],siz[maxn];
int nans[maxn];
inline void init()
{
	FOR(i,1,n*2)nans[i]=p[i]=0,e[i].clear(),fa[i]=0;
	FOR(i,1,n*2)now[i][0]=now[i][1]=ans[i]=siz[i]=0;
	FOR(i,1,n*2)scc[i]=dfn[i]=low[i]=0;tot=0;
}
inline void input()
{
	 n=gi();
}
inline int change(int x){return x>n?x-n:x+n;}
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
stack<int>stk;
inline void dfs(int u)
{
	dfn[u]=low[u]=++tot;stk.push(u);
	FOR(t,0,sz(e[u])-1)
	{
		int v=e[u][t];
		if(scc[v])continue;
		if(!dfn[v])dfs(v),low[u]=min(low[u],low[v]);
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		cnt++;
		while(1)
		{
			int x=stk.top();stk.pop();
			scc[x]=cnt;
			if(x==u)break;
		}
	}
}
ll sum=0;
inline void solve()
{
	if(n%2==0)
	{
		printf("First\n");
		fflush(stdout);
		FOR(i,1,n)printf("%d ",i);
		FOR(i,1,n)printf("%d ",i);
		printf("\n");
		fflush(stdout);
		return ; 
	}
	printf("Second\n");
	fflush(stdout);
	FOR(i,1,2*n)p[i]=gi();
	FOR(i,1,2*n)now[p[i]][0]?now[p[i]][1]=i:now[p[i]][0]=i;
	fflush(stdout);
	FOR(i,1,n)
	{
		int x=change(now[i][0]),y=change(now[i][1]);
		if(now[i][1]==change(now[i][0]))continue;
		e[now[i][0]].pb(y),e[now[i][1]].pb(x);
	}	
	FOR(i,1,2*n)if(!dfn[i])dfs(i);
	//FOR(i,1,2*n)printf("scc[%d]=%d\n",i,scc[i]);
	//FOR(i,1,n)assert(scc[i]!=scc[i+n]);
	FOR(i,1,2*n)fa[i]=i;
	FOR(i,1,n)scc[i]<scc[i+n]?ans[i]=1:ans[i+n]=1;
	FOR(i,1,2*n)if(ans[i])sum+=i;
	//FOR(i,1,2*n)if(ans[i])printf("%d ",i);puts("");
	//printf("%lld\n",sum);
	//assert(sum%n==0);///assert
	if(sum%(2*n)!=0)
	{
		FOR(i,1,n)
		{
			int x=get(p[i]),y=get(p[i+n]);
			if(x!=y)fa[x]=y;
		}
		FOR(i,1,n)siz[get(i)]++;
		//FOR(i,1,n)printf("siz[%d]=%d\n",i,siz[i]);
		int cur=-1;
		FOR(i,1,n)if(get(i)==i&&siz[i]%2==1){cur=i;break;}
		//assert(cur!=-1);///assert
		FOR(i,1,n)if(get(i)==cur)
		{
			if(ans[now[i][0]])ans[now[i][0]]=0,ans[now[i][1]]=1;
			else ans[now[i][1]]=0,ans[now[i][0]]=1;
		}
		sum=0;FOR(i,1,2*n)sum+=ans[i]?i:0;
	}
	//assert(sum%(2*n)==0);///assert
	FOR(i,1,2*n)if(ans[i])printf("%d ",i);puts("");
	fflush(stdout);
}
int main()
{
//	freopen("pair.in","r",stdin);
//	freopen("pair.out","w",stdout);
	init();
	input();
	solve();
	return 0;
}