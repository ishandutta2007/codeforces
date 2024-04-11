#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define mk make_pair
#define iter set<int>::iterator
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
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=4e5+5;
	int sum[maxn],pos[maxn];
	inline void pushup(int u)
	{
		pos[u]=max(pos[ls],pos[rs]);
		sum[u]=sum[ls]+sum[rs];
	}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)
		{
			sum[u]+=v;
			sum[u]==0?pos[u]=0:pos[u]=l;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline pair<int,int> query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return {sum[u],pos[u]};
		int mid=(l+r)>>1;pair<int,int>ret={0,0};
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)
		{
			auto xx=query(rs,mid+1,r,x,y);
			ret.first+=xx.first,ret.second=max(ret.second,xx.second);
		}
		return ret;
	}
}tree;
const int maxn=1e5+5;
int ans[maxn],n,q,l[maxn],r[maxn],a[maxn];
vector<int>now[maxn];
vector<int>cur,num;
inline void init()
{
	FOR(i,1,max(n,q))now[i].clear();
	FOR(i,1,max(n,q))ans[i]=l[i]=r[i]=a[i]=0;
	cur.clear(),num.clear();
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	q=gi();
	FOR(i,1,q)l[i]=gi(),r[i]=gi();
}
inline void Divide(int step,vector<int>&cur,vector<int>&num,int sum)
{
	if(!sz(cur))return ;
	if(step==-1)
	{
		for(int x:cur)ans[x]=sum;
		return ;
	}
	vector<int>numl,numr;
	for(int x:num){if(a[x]>>step&1)numr.pb(x);else numl.pb(x);}
	for(int x:numl)tree.update(1,1,n,x,1);
	vector<int>curl,curr;
	for(int x:cur)
	{
		auto y=tree.query(1,1,n,l[x],r[x]);
		for(int z:now[x])y.first+=!(a[z]>>step&1);
		if(y.first>=2)
		{
			vector<int>temp=now[x];now[x].clear();
			for(int z:temp)if(!(a[z]>>step&1))now[x].pb(z);
			curl.pb(x);	
		}
		else
		{
			if(y.second)now[x].pb(y.second);
			curr.pb(x);
		}
	}
	for(int x:numl)tree.update(1,1,n,x,-1);
	Divide(step-1,curl,numl,sum);
	Divide(step-1,curr,numr,sum+(1<<step));
}
inline void solve()
{
	FOR(i,1,q)cur.pb(i);
	FOR(i,1,n)num.pb(i);
	Divide(30,cur,num,0);
	FOR(i,1,q)printf("%d\n",ans[i]);
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