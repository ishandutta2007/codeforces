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
const int maxn=3e5+5;
struct node
{
	ll a;ll b;
}a[maxn];
int n;
inline void init()
{

}
inline void input()
{
	scanf("%d",&n);
	FOR(i,1,n)scanf("%lld",&a[i].a);
}
struct Splay
{
	ll val[maxn],tag[maxn];
	int root,cnt,siz[maxn];
	int fa[maxn],son[maxn][2];
	inline void pushup(int u){siz[u]=siz[son[u][0]]+siz[son[u][1]]+1;}
	inline void pushr(int u,ll x)
	{
		val[u]+=x;
		tag[u]+=x;
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
		son[z][son[z][1]==y]=x;
		fa[x]=z;son[y][k]=son[x][k^1];
		fa[son[x][k^1]]=y,son[x][k^1]=y;
		fa[y]=x;
		pushup(y),pushup(x);
	}
	inline void pushall(int x)
	{
		if(fa[x])pushall(fa[x]);
		pushdown(x);
	}
	inline void splay(int x)
	{
		pushall(x);
		while(fa[x]!=0)
		{
			int y=fa[x],z=fa[y];
			if(z!=0)
			{
				if((son[z][1]==y)^(son[y][1]==x))rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		root=x;
	}
	inline void insert(node x)
	{
		int now=root,k=1;
		while(1)
		{
			pushdown(now);
			if(now!=0)siz[now]++;
			if(val[now]<=x.a*(k+siz[son[now][0]])+x.b)
			{
				if(son[now][0])now=son[now][0];
				else {son[now][0]=++cnt;break;}
			}
			else 
			{
				k+=now==0?0:siz[son[now][0]]+1;
				if(son[now][1])now=son[now][1];
				else {son[now][1]=++cnt;break;}
			}
		} 
		fa[cnt]=now;
		val[cnt]=(x.a*k)+x.b;
		siz[cnt]=1;
		splay(cnt);
	}
	inline void dfs(int u,ll &sum,ll &ans)
	{
		if(!u)return ;
		pushdown(u);
		dfs(son[u][0],sum,ans);
		sum+=val[u];
		ans=max(ans,sum);
		dfs(son[u][1],sum,ans);
	}
}tree;
inline void solve()
{
	FOR(i,1,n)
	{
		tree.insert(a[i]);
		tree.pushr(tree.son[tree.root][1],a[i].a);
	}
	ll temp=0,ans=0;
	tree.dfs(tree.root,temp,ans);
	printf("%lld\n",ans);
}
int main()
{
//	freopen("value.in","r",stdin);
//	freopen("value.out","w",stdout);
	init();
	input();
	solve();
	return 0;
}