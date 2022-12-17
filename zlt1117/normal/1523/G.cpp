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
const int maxn=1e5+5;
int a[maxn],b[maxn],n,m;
struct intervaltree
{
	static const int maxn=2e7+5;
	int ls[maxn],rs[maxn],minv[maxn],tot;
	intervaltree(){minv[0]=1e9;}
	inline void update(int &u,int l,int r,int x,int v)
	{
		if(!u)u=++tot,minv[u]=1e9;
		if(l==r)return minv[u]=min(minv[u],v),void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls[u],l,mid,x,v);
		else update(rs[u],mid+1,r,x,v);
		minv[u]=min(minv[ls[u]],minv[rs[u]]);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(!u)return 1e9;
		if(x<=l&&y>=r)return minv[u];
		int mid=(l+r)>>1,ret=1e9;
		if(x<=mid)ret=query(ls[u],l,mid,x,y);
		if(y>mid)ret=min(ret,query(rs[u],mid+1,r,x,y));
		return ret;
	}
}T;
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=4e5+5;
	int rt[maxn];
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		T.update(rt[u],1,n,y,v);
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,y,v);
		else update(rs,mid+1,r,x,y,v);
	}
	inline int query(int u,int l,int r,int x,int y,int a,int b)
	{
		if(x<=l&&y>=r)return T.query(rt[u],1,n,a,b);
		int mid=(l+r)>>1,ret=1e9;
		if(x<=mid)ret=query(ls,l,mid,x,y,a,b);
		if(y>mid)ret=min(ret,query(rs,mid+1,r,x,y,a,b));
		return ret;
	}
}tree;
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)a[i]=gi(),b[i]=gi();
}
int id[maxn];
inline int calc(int l,int r)
{
	if(l>r)return 0;
	int now=tree.query(1,1,n,l,n,1,r);
	if(now==1e9)return 0;
	return calc(l,a[now]-1)+calc(b[now]+1,r)+b[now]-a[now]+1;
}
inline void solve()
{
	FOR(i,1,m)id[i]=i;
	sort(id+1,id+m+1,[&](int x,int y){return b[x]-a[x]>b[y]-a[y];});
	int now=1;
	vector<int>answer;
	for(int i=n;i>=1;--i)
	{
		int p=id[now];
		while(now<=m&&b[p]-a[p]+1==i)
		{
			tree.update(1,1,n,a[p],b[p],p);
			now++;p=id[now];
		}
		answer.pb(calc(1,n));
	}
	reverse(answer.begin(),answer.end());
	for(int x:answer)printf("%d\n",x);
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