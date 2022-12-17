#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
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
const int maxn=2e5+5;
int n,a[maxn];
vector<int>v[maxn];
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=8e5+105;
	int minv[maxn],maxv[maxn],tag[maxn],pos1[maxn],pos2[maxn];///prefix_sum
	inline void build(int u,int l,int r)
	{
		tag[u]=0,pos1[u]=0,pos2[u]=0;
		if(l==r)return pos1[u]=l,pos2[u]=l,maxv[u]=minv[u]=l,void();
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	inline void pushdown(int u,int l,int r)
	{
		if(tag[u])
		{
			tag[ls]+=tag[u];
			tag[rs]+=tag[u];
			maxv[ls]+=tag[u];
			maxv[rs]+=tag[u];
			minv[ls]+=tag[u];
			minv[rs]+=tag[u];
			tag[u]=0;
		}
	}
	inline void pushup(int u)
	{
		if(minv[ls]<minv[rs])minv[u]=minv[ls],pos1[u]=pos1[ls];
		else minv[u]=minv[rs],pos1[u]=pos1[rs];
		if(maxv[ls]>maxv[rs])maxv[u]=maxv[ls],pos2[u]=pos2[ls];
		else maxv[u]=maxv[rs],pos2[u]=pos2[rs];
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)return maxv[u]+=v,minv[u]+=v,tag[u]+=v,void();
		int mid=(l+r)>>1;
		pushdown(u,l,r);
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline pair<int,int> query1(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return pair<int,int>(minv[u],pos1[u]);
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(y<=mid)return query1(ls,l,mid,x,y);
		if(x>mid)return query1(rs,mid+1,r,x,y);
		return min(query1(ls,l,mid,x,y),query1(rs,mid+1,r,x,y));
	}
	inline pair<int,int> query2(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return pair<int,int>(maxv[u],pos2[u]);
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(y<=mid)return query2(ls,l,mid,x,y);
		if(x>mid)return query2(rs,mid+1,r,x,y);
		return max(query2(ls,l,mid,x,y),query2(rs,mid+1,r,x,y));
	}
	#undef ls
	#undef rs
}tree;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),v[a[i]].pb(i);
}
int ans[maxn],id[maxn];
inline void solve()
{
	FOR(i,1,n)id[i]=i;
	sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
	tree.build(1,0,n);
	FOR(i,1,n)///-1
	{
		int x=id[i];
		if(a[id[i]]!=a[id[i-1]])for(int x:v[a[id[i]]])tree.update(1,0,n,x,n,-2);
		tree.update(1,0,n,x,n,2);
		auto lp=tree.query2(1,0,n,0,x-1),rp=tree.query1(1,0,n,x,n);
		//int len=rp.second-lp.second+1;
		int val=rp.first-lp.first;
		assert(val<=1);
		ans[x]=max(ans[x],(-val+1)/2);
		tree.update(1,0,n,x,n,-2);
	}
	tree.build(1,0,n);
	FOR(i,1,n)///1
	{
		int x=id[i];
		if(a[id[i]]!=a[id[i-1]]&&i!=1)for(int x:v[a[id[i-1]]])tree.update(1,0,n,x,n,-2);
		tree.update(1,0,n,x,n,-2);
		auto lp=tree.query1(1,0,n,0,x-1),rp=tree.query2(1,0,n,x,n);
		//int len=rp.second-lp.second+1;
		int val=rp.first-lp.first;
		assert(val>=-1);
		ans[x]=max(ans[x],(val+2)/2);
		tree.update(1,0,n,x,n,2);
	}
	FOR(i,1,n)printf("%d ",ans[i]);
	puts("");
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}