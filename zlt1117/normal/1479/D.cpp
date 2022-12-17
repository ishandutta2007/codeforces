#pragma GCC optimize("Ofast") 
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
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=6e5+5,block=2000;
int n,m,a[maxn];
int u,v;
vector<int>e[maxn];
int dfn[maxn],low[maxn],tot;
int st[maxn],ed[maxn],Log[maxn];
namespace LCA
{
	int tot;
	int st[maxn][20],dep[maxn],fir[maxn];
	inline void dfs(int u,int fa)
	{
		st[++tot][0]=u;fir[u]=tot;
		for(int v:e[u])
		{
			if(v==fa)continue;
			dep[v]=dep[u]+1;
			dfs(v,u);
			st[++tot][0]=u;
		}
	}
	inline int compare(int x,int y){return dep[x]<dep[y]?x:y;}
	inline void prepare()
	{
		FOR(j,1,Log[tot])
		{
			FOR(i,1,tot-(1<<j)+1)
			{
				st[i][j]=compare(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
	}
	inline int LCA(int u,int v)
	{
		u=fir[u],v=fir[v];
		if(u>v)swap(u,v);
		int l=Log[v-u+1];
		return compare(st[u][l],st[v-(1<<l)+1][l]);
	}
}
inline void init()
{
	FOR(i,2,maxn-1)Log[i]=Log[i>>1]+1;
}
inline void dfs(int u,int fa)
{
	st[u]=++tot;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
	}
	ed[u]=++tot;
}
int temp[maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)temp[i]=a[i]=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	LCA::dfs(1,0);
	LCA::prepare();
	dfs(1,0);
}
int bel[maxn];
struct queries
{
	int id,l,r,lca,L,R;
	inline bool operator < (const queries &b)const
	{
		if(bel[l]==bel[b.l])return bel[l]&1?r<b.r:r>b.r;
		else return bel[l]<bel[b.l];
	}
}q[maxn];
int ans[maxn];
int cnt[maxn],l=1,r=0;
int c[maxn];
bool vis[maxn];
int sum=0;
struct Tree
{
	int S[maxn];
	int posl[maxn],tot,posr[maxn];
	int a[maxn];
	inline void init()
	{
		while(posr[tot]<2*n)
		{
			++tot;
			posl[tot]=posr[tot-1]+1;
			posr[tot]=posl[tot]+block-1;
			posr[tot]=min(posr[tot],n*2);
		}
	}
	inline void update(int x,int v)
	{
		if(a[x]>0)S[bel[x]]--;
		a[x]+=v;
		if(a[x]>0)S[bel[x]]++;
	}
	inline int query(int x,int y)
	{
		int bl=bel[x],br=bel[y];
		if(bl==br)
		{
			FOR(i,x,y)if(a[i])return i;
			return -1;
		}
		FOR(i,x,posr[bl])if(a[i])return i;
		FOR(i,posl[br],y)if(a[i])return i;
		bl++,br--;
		FOR(i,bl,br)
		{
			if(S[i]!=0)
			{
				FOR(j,posl[i],posr[i])if(a[j])return j;
			}
		}
		return -1;
	}
}tree;
inline void add(int x)
{
	x=c[x];
	if(cnt[a[x]]%2==1)tree.update(a[x],-1);
	else tree.update(a[x],1);
	if(vis[x])
	{
		cnt[a[x]]--;
		vis[x]=0;
	}
	else
	{
		cnt[a[x]]++;
		vis[x]=1;
	}
}
inline void solve()
{
	tree.init();
	FOR(i,1,n*2)bel[i]=(i-1)/block+1;
	FOR(i,1,n)c[st[i]]=i,c[ed[i]]=i;
	FOR(i,1,m)
	{
		int u=gi(),v=gi(),L=gi(),R=gi();
		if(st[u]>st[v])swap(u,v);
		int lca=LCA::LCA(u,v);
		//cerr<<u<<' '<<v<<' '<<lca<<endl;
		//cerr<<st[u]<<" "<<st[v]<<endl;
		if(lca==u)q[i]={i,st[u],st[v],0,L,R};
		else q[i]={i,ed[u],st[v],st[lca],L,R};
	}
	sort(q+1,q+m+1);
	FOR(i,1,m)
	{
	//	cerr<<q[i].l<<' '<<q[i].r<<endl;
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(l<q[i].l)add(l++);
		while(r>q[i].r)add(r--);
		if(q[i].lca)add(q[i].lca);
		ans[q[i].id]=tree.query(q[i].L,q[i].R);
		//FOR(j,1,n)cerr<<cnt[j]<<' ';
		//cerr<<endl;
		if(q[i].lca)add(q[i].lca);
	}
	FOR(i,1,m)printf("%d\n",ans[i]);
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