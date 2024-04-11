#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define mk make_pair
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
const int maxn=3e5+5;
int n,m;
int id[maxn],l[maxn],r[maxn];
vector<pair<int,int>>v[maxn];
int temp[maxn<<1],tot;
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)id[i]=gi(),l[i]=gi(),r[i]=gi(),temp[++tot]=l[i],temp[++tot]=r[i]+1;
	sort(temp+1,temp+tot+1);tot=unique(temp+1,temp+tot+1)-temp-1;
	FOR(i,1,m)l[i]=lower_bound(temp+1,temp+tot+1,l[i])-temp;
	FOR(i,1,m)r[i]=lower_bound(temp+1,temp+tot+1,r[i]+1)-temp;
	FOR(i,1,m)v[id[i]].pb({l[i],r[i]});
}
int dp[maxn],lst[maxn];
bool vis[maxn];
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=2.4e6+5;
	int maxv[maxn],tag[maxn];
	inline void pushup(int u)
	{
		if(dp[maxv[ls]]>dp[maxv[rs]])maxv[u]=maxv[ls];
		else maxv[u]=maxv[rs];
	}
	inline void pushdown(int u)
	{
		if(dp[tag[u]]>dp[maxv[ls]])maxv[ls]=tag[u];
		if(dp[tag[u]]>dp[maxv[rs]])maxv[rs]=tag[u];
		if(dp[tag[u]]>dp[tag[ls]])tag[ls]=tag[u];
		if(dp[tag[u]]>dp[tag[rs]])tag[rs]=tag[u];
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)return tag[u]=dp[v]>dp[tag[u]]?v:tag[u],maxv[u]=dp[v]>dp[maxv[u]]?v:maxv[u],void();
		int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return maxv[u];
		int mid=(l+r)>>1,ret=0;
		pushdown(u);
		if(x<=mid)	
		{
			int nowval=query(ls,l,mid,x,y);
			if(dp[nowval]>dp[ret])ret=nowval;
		}
		if(y>mid)
		{
			int nowval=query(rs,mid+1,r,x,y);
			if(dp[nowval]>dp[ret])ret=nowval;
		}
		return ret;
	}
}tree;
inline void solve()
{
	pair<int,int>best={-1,0};
	FOR(i,1,n)
	{
		for(auto [l,r]:v[i])
		{
			int v=tree.query(1,1,tot,l,r-1);
			if(dp[v]+1>dp[i])lst[i]=v,dp[i]=dp[v]+1;
			//cerr<<i<<' '<<l<<' '<<r<<endl;
		}
		best=max(best,{dp[i],i});
		for(auto [l,r]:v[i])tree.update(1,1,tot,l,r-1,i);
		//printf("dp[%d]=%d,lst[%d]=%d\n",i,dp[i],i,lst[i]);
	}
	printf("%d\n",n-best.first);
	int u=best.second;
	while(u)vis[u]=1,u=lst[u];
	FOR(i,1,n)if(!vis[i])printf("%d ",i);
	puts("");
}
int main()
{
	input();
	solve();
	return 0;
}