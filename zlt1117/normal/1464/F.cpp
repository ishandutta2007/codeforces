//#pragma GCC optimize("Ofast")
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
const int maxn=4e5+5;
int fa[maxn][20],dfn[maxn],tot,tim,low[maxn],Log[maxn],n,q;
int st[maxn][20],fir[maxn],dep[maxn],now[maxn];
vector<int>e[maxn];
inline void dfs(int u)
{
	FOR(i,1,Log[dep[u]])fa[u][i]=fa[fa[u][i-1]][i-1];
	dfn[u]=++tot,st[++tim][0]=u;fir[u]=tim;now[tot]=u;
	for(auto v:e[u])
	{
		if(v==fa[u][0])continue;
		fa[v][0]=u,dep[v]=dep[u]+1;
		dfs(v);
		st[++tim][0]=u;
	}
	low[u]=tot;
}
inline int compare(int u,int v){return dep[u]<dep[v]?u:v;}
inline void prepare()
{
	FOR(i,1,Log[tim])
	{
		FOR(j,1,tim-(1<<i)+1)
		{
			st[j][i]=compare(st[j][i-1],st[j+(1<<(i-1))][i-1]);
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
inline int dist(int a,int b)
{
	if(a==-1||b==-1)return 0;
	return dep[a]+dep[b]-2*dep[LCA(a,b)];
}
struct diam
{
	int u,v;
	inline bool operator < (const diam &b)const
	{
		if(u==-1)return true;
		if(b.u==-1)return false;
		return dist(u,v)<dist(b.u,b.v);
	}
};
inline diam operator + (diam a,diam b)
{
	 diam now=max(a,b);
	 now=max(max(now,{a.u,b.u}),{a.v,b.v});
	 now=max(max(now,{a.u,b.v}),{a.v,b.u});
	 return now;
}
struct segmentree///protest the sum of subtree
{
	#define ls u<<1 
	#define rs u<<1|1
	static const int maxn=8e5+5;
	int sum[maxn];
	inline void pushup(int u){sum[u]=sum[ls]+sum[rs];}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)return sum[u]+=v,void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		int mid=(l+r)>>1,ret=0;
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret+=query(rs,mid+1,r,x,y);
		return ret;
	}
	#undef ls
	#undef rs
}tree1;
struct intervertree///protest the chains in the sutree
{
	#define ls u<<1 
	#define rs u<<1|1
	static const int maxn=8e5+5; 
	diam sum[maxn];
	inline void pushup(int u)
	{
		sum[u]=sum[ls]+sum[rs];
	}
	inline void build(int u,int l,int r)
	{
		sum[u]={-1,-1};
		if(l==r)return ;
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)
		{
			if(v==-1)return sum[u]={-1,-1},void();
			else return sum[u]={now[l],now[l]},void();
		}
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline diam query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		int mid=(l+r)>>1;diam ret={-1,-1};
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret=ret+query(rs,mid+1,r,x,y);
		return ret;
	}
	#undef ls
	#undef rs
}tree2;
int cnt[maxn];///cnt of LCA
multiset<PII,greater<PII> >s;
inline int kth(int u,int k)
{
	if(dep[u]<=k)return 1;
	for(int i=Log[dep[u]];i>=0;--i)
	{
		if(k>=dep[u]-dep[fa[u][i]])
		{
			k-=dep[u]-dep[fa[u][i]];
			u=fa[u][i];
		}
	}
	return u;
}
inline bool work(int d)
{
	if(sz(s)==0)return 0;
	int x=(*s.begin()).second;
	int u=kth(x,d),v=kth(u,d);
	int now=tree1.query(1,1,n,dfn[v],low[v]);
	if(now!=sz(s))return 0;
	diam temp=tree2.query(1,1,n,dfn[v],low[v]);
	if(dist(temp.u,u)>d||dist(temp.v,u)>d)return 0;
	return 1; 
}
inline void init()
{
	FOR(i,2,maxn-1)Log[i]=Log[i>>1]+1;
}
inline void input()
{
	n=gi(),q=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
inline void solve()
{
	dfs(1);
	prepare();
	tree2.build(1,1,n);
	int counter=0;
	FOR(i,1,q)
	{
		int opt=gi();
		if(opt==2)
		{
			int u=gi(),v=gi();
			if(u>v)swap(u,v);
			int lca=LCA(u,v);
			s.erase(s.lower_bound({dep[lca],lca}));
			tree1.update(1,1,n,dfn[u],-1);
			tree1.update(1,1,n,dfn[v],-1);
			tree1.update(1,1,n,dfn[lca],1);
			cnt[lca]--;
			if(cnt[lca]==0)tree2.update(1,1,n,dfn[lca],-1);
		}
		else if(opt==1)
		{
			int u=gi(),v=gi();
			if(u>v)swap(u,v);
			int lca=LCA(u,v);
			s.insert({dep[lca],lca});
			tree1.update(1,1,n,dfn[u],1);
			tree1.update(1,1,n,dfn[v],1);
			tree1.update(1,1,n,dfn[lca],-1);
			cnt[lca]++;
			if(cnt[lca]==1)tree2.update(1,1,n,dfn[lca],1);
		}
		else
		{
			counter++;
			int d=gi();
			printf(work(d)?"Yes\n":"No\n");
//			if(counter==31)
//			{
//				cout<<d<<endl;
//				int x=(*s.begin()).second;
//				int u=kth(x,d),v=kth(u,d);
//				cout<<x<<' '<<u<<' '<<v<<' '<<dfn[v]<<' '<<low[v]<<endl;
//				int now=tree1.query(1,1,n,dfn[v],low[v]);
//				if(now!=sz(s))cout<<"WA 1 "<<sz(s)<<' '<<now<<endl;
//				diam temp=tree2.query(1,1,n,dfn[v],low[v]);
//				if(dist(temp.u,u)>d||dist(temp.v,u)>d)cout<<"WA 2";
//				for(auto xx:s)cout<<xx.u<<' '<<xx.v<<' '<<xx.lca<<' '<<(LCA(xx.u,x)==x||LCA(xx.v,x)==x)<<endl;
//				exit(0);
//			}
		}
	}
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
/*
2 10
4 10
4 11
5 20
6 15
6 17
6 18
12 13
18 20
*/