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
int n,m,a[maxn];
set<pair<int,int>>col[maxn];///color
set<pair<pair<int,int>,int>>S;///all 
struct intervaltree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=4e5+5;
	ll sum[maxn],tag[maxn],tag2[maxn];
	inline void pushr(int u,int x,ll v)
	{
		sum[u]+=x*v;
		tag[u]+=v;
	}
	inline void pushup(int u)
	{
		sum[u]=sum[ls]+sum[rs];
	}
	inline void pusht(int u,int x,ll v)
	{
		tag2[u]+=v;
		sum[u]+=v*(1+x)*x/2;
	}
	inline void pushdown(int u,int l,int r)
	{
		int mid=(l+r)>>1;
		if(tag[u])
		{
			pushr(ls,mid-l+1,tag[u]);
			pushr(rs,r-mid,tag[u]);
			tag[u]=0;
		}
		if(tag2[u])
		{
			pusht(ls,mid-l+1,tag2[u]);
			pusht(rs,r-mid,tag2[u]);
			pushr(rs,r-mid,tag2[u]*(mid-l+1));
			tag2[u]=0;
		}
	}
	inline void update(int u,int l,int r,int x,int y,ll v)
	{
		if(x<=l&&y>=r)return pushr(u,r-l+1,v);
		int mid=(l+r)>>1;pushdown(u,l,r);
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline void update2(int u,int l,int r,int x,int y,ll v)
	{
		if(x<=l&&y>=r)return pusht(u,r-l+1,v),pushr(u,r-l+1,v*(l-x));
		int mid=(l+r)>>1;pushdown(u,l,r);
		if(x<=mid)update2(ls,l,mid,x,y,v);
		if(y>mid)update2(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline ll query(int u,int l,int r,int x)
	{
		if(l==r)return sum[u];
		int mid=(l+r)>>1;
		pushdown(u,l,r);
		if(x<=mid)return query(ls,l,mid,x);
		else return query(rs,mid+1,r,x);
	}
}tree;
inline void change(int x,int l,int r,int c)
{
	//cerr<<x<<' '<<l<<' '<<r<<endl;
	tree.update(1,1,n,1,n-x,c*(l-x));
	if(n-l+2<=n-x)tree.update2(1,1,n,n-l+2,n-x,-c);
	tree.update(1,1,n,1,l-x,-c*(l-x));
	tree.update2(1,1,n,1,l-x,c);
	if(l<n)tree.update(1,1,n,1,n-l,c*(r-l));
	if(n-r+2<=n-l&&l<n)tree.update2(1,1,n,n-r+2,n-l,-c);
}
int lst[maxn],pre[maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)a[i]=gi(),col[a[i]].insert({i,i}),S.insert({{i,i},a[i]});
	FOR(i,1,n)
	{
		pre[i]=lst[a[i]];
		lst[a[i]]=i;
		change(pre[i],i,i,1);
	}
}
inline void del(int c,pair<int,int>x)
{
	auto y=col[c].upper_bound(x);
	auto z=y;--z;
	change((*z).second,x.first,x.second,-1);
	if(y!=col[c].end())change(x.second,(*y).first,(*y).second,-1);
	if(y!=col[c].end())change((*z).second,(*y).first,(*y).second,1);
}
inline void Debug()
{
	/*for(auto x:S)
	{
		auto y=x.first;auto z=x.second;
		fprintf(stderr,"%d %d %d\n",y.first,y.second,z);
	}*/
	FOR(i,1,n)fprintf(stderr,"ans[%d]=%lld\n",i,tree.query(1,1,n,i));
}
inline void erase(int l,int r)
{
	auto x=S.lower_bound({{l+1,0},0});--x;
	if((*x).first.first!=l)
	{
		auto p=(*x).first;auto c=(*x).second;
		S.erase(x);col[c].erase(p);
		S.insert({{p.first,l-1},c}),col[c].insert({p.first,l-1});
		S.insert({{l,p.second},c}),col[c].insert({l,p.second});
	}
	x=S.lower_bound({{l,0},0});
	while(x!=S.end())
	{
		if((*x).first.second<=r)
		{
			auto x1=(*x).second;auto x2=(*x).first;
			col[(*x).second].erase((*x).first);
			S.erase(x++);del(x1,x2);
		}
		else if((*x).first.first>r)break;
		else
		{
			int c=(*x).second;auto p=(*x).first;
			S.erase(x),col[c].erase(p);auto q=p;
			p.first=r+1;q.second=r;
			S.insert({p,c}),col[c].insert(p);
			del(c,q);
			break;
		}
	}
}
inline void solve()
{
	FOR(i,1,100000)col[i].insert({0,0});
	FOR(i,1,m)
	{
		int typ=gi();
		if(typ==1)
		{
			int l=gi(),r=gi(),x=gi();
			erase(l,r);
			col[x].insert({l,r});S.insert({{l,r},x});
			auto y=col[x].find({l,r});
			auto z=y,q=y;--z;++q;
			if(q!=col[x].end())change((*z).second,(*q).first,(*q).second,-1);
			if(q!=col[x].end())change(r,(*q).first,(*q).second,1);
			change((*z).second,l,r,1);
			//Debug();
		}
		else 	
		{
			int k=gi();
			printf("%lld\n",tree.query(1,1,n,k));
		}
		//cerr<<"start:"<<i<<endl;
		//Debug();
		//cerr<<"end\n";
	}
}
int main()
{
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	input();
	solve();
	return 0;
}
/*
5 5
1 2 3 4 5
2 3
1 1 2 5
2 4
1 2 4 5
2 2

*/