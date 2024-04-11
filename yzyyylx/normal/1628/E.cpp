#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define PP pair<ll,P>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 1000000
#define B 18
#define N 600100
#define M 1000000007
using namespace std;

ll T,n,nn,m,tt,fa[N],num[N],dfn[N],in[N],deep[N],lca[N][20];
PP bn[N];
struct Node
{
	ll ls,rs,cg;
	bool ok;
	P num,pi;
	inline void chg(ll u)
	{
		cg=u;
		if(u==1) ok=1,num=pi;
		if(u==-1) ok=0,num=mp(INF,0ll);
	}
}node[N];
vector<ll>to[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
ll ff(ll u){return u==fa[u]?u:fa[u]=ff(fa[u]);}
inline P mg(P u,P v){return mp(min(u.fi,v.fi),max(u.se,v.se));}
void dfs(ll now)
{
	ll i,t;
	dfn[++tt]=now;
	in[now]=tt;
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i];
		lca[t][0]=now;
		deep[t]=deep[now]+1;
		dfs(t);
	}
}

inline ll Lca(ll u,ll v)
{
//	cout<<" "<<u<<" "<<v<<endl;
	if(deep[u]<deep[v]) swap(u,v);
	ll i;
	for(i=B;deep[u]!=deep[v];i--) if(deep[lca[u][i]]>=deep[v]) u=lca[u][i];
	if(u==v) return u;
	for(i=B;i>=0;i--) if(lca[u][i]!=lca[v][i]) u=lca[u][i],v=lca[v][i];
	return lca[u][0];
}

inline void up(ll now)
{
	ll L=node[now].ls,R=node[now].rs;
	node[now].num=mg(node[L].num,node[R].num);
}

inline void down(ll now)
{
	ll L=node[now].ls,R=node[now].rs;
	if(node[now].cg)
	{
		node[L].chg(node[now].cg);
		node[R].chg(node[now].cg);
		node[now].cg=0;
	}
}

void build(ll now,ll l,ll r)
{
	if(l==r)
	{
		node[now].pi=mp(in[l],in[l]);
		node[now].num=mp(INF,0ll);
		return;
	}
	ll mid=((l+r)>>1);
	node[now].ls=++tt;
	build(tt,l,mid);
	node[now].rs=++tt;
	build(tt,mid+1,r);
	node[now].pi=mg(node[node[now].ls].pi,node[node[now].rs].pi);
	up(now);
}

void chg(ll now,ll l,ll r,ll u,ll v,ll w)
{
	if(u<=l && r<=v)
	{
		node[now].chg(w);
		return;
	}
	down(now);
	ll mid=((l+r)>>1);
	if(u<=mid) chg(node[now].ls,l,mid,u,v,w);
	if(mid<v) chg(node[now].rs,mid+1,r,u,v,w);
	up(now);
}

P ask(ll now,ll l,ll r,ll u,ll v)
{
	if(u>v) return mp(INF,0ll);
	if(u<=l && r<=v) return node[now].num;
	down(now);
	ll mid=((l+r)>>1);
	P res=mp(INF,0ll);
	if(u<=mid) res=mg(res,ask(node[now].ls,l,mid,u,v));
	if(mid<v) res=mg(res,ask(node[now].rs,mid+1,r,u,v));
	return res;
}

int main()
{
	ll i,j,k,o,p,q,a,b,now;
	cin>>n>>m;
	for(i=1;i<=(n<<1);i++) fa[i]=i;
	for(i=1;i<n;i++) scanf("%lld%lld%lld",&bn[i].se.fi,&bn[i].se.se,&bn[i].fi);
	sort(bn+1,bn+n),tt=n;
	for(i=1;i<n;i++)
	{
		tt++;
		to[tt].push_back(ff(bn[i].se.fi));
		to[tt].push_back(ff(bn[i].se.se));
		fa[ff(bn[i].se.fi)]=fa[ff(bn[i].se.se)]=tt;
		num[tt]=bn[i].fi;
	}
	nn=tt,tt=0;
	/*
	for(i=1;i<=nn;i++)
	{
		cout<<i<<" "<<num[i]<<":";
		for(j=0;j<to[i].size();j++)
		{
			cout<<to[i][j]<<" ";
		}
		puts("");
	}
	return 0;
	//*/
	
	deep[nn]=1;
	dfs(nn);
	for(j=1;j<=B;j++)
	{
		for(i=1;i<=nn;i++)
		{
			lca[i][j]=lca[lca[i][j-1]][j-1];
		}
	}
//	for(i=1;i<=nn;i++) cout<<in[i]<<" ";return 0; 
//	cout<<Lca(mp(in[2],in[3]));return 0;
	
	build(tt=1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&o);
		if(o==1)
		{
			scanf("%lld%lld",&p,&q);
			chg(1,1,n,p,q,1);
		}
		else if(o==2)
		{
			scanf("%lld%lld",&p,&q);
			chg(1,1,n,p,q,-1);
		}
		else
		{
			scanf("%lld",&p);
			P ans=mg(ask(1,1,n,1,p-1),ask(1,1,n,p+1,n));
//			cout<<" "<<ans.fi<<" "<<ans.se<<endl;
			if(ans==mp(INF,0ll)) puts("-1");
			else printf("%lld\n",num[Lca(p,Lca(dfn[ans.fi],dfn[ans.se]))]);
		}
	}
}
/*
8 8
1 2 1
1 3 2
1 4 2
3 5 5
5 6 9
4 7 3
1 8 3

2 5 5
2 5 8
2 1 5
2 2 5
1 3 4
1 4 4
2 4 6
3 2

*/