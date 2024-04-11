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
const int maxn=4e5+5;
int delta=0;
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=1e6+5;
	int maxv[maxn];
	inline void pushup(int u)
	{
		maxv[u]=max(maxv[ls],maxv[rs]);
	}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)return maxv[u]=v,void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return maxv[u];
		int mid=(l+r)>>1,ret=0;
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret=max(ret,query(rs,mid+1,r,x,y));
		return ret;
	}
}tree1,tree2;
set<pair<int,int>>S1,S2;
int n,m,val[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi(),m=gi();
}
inline void solve()
{
	delta=m;
	int M=m+11;
	while(m--)
	{
		int typ=gi();delta--;
		if(typ==1)
		{
			int p=gi(),h=gi();
			val[p]=h+delta;
			S2.insert({p,delta+h});S1.insert({delta+h,p});
			vector<int>v;
			while(!S1.empty()&&(*S1.begin()).first<=delta+h)
			{
				v.pb((*S1.begin()).second);
				int x=(*S1.begin()).second;
				pair<int,int>t=*S1.begin();
				S1.erase(S1.begin());
				swap(t.first,t.second);
				S2.erase(t);
				tree1.update(1,1,M,x,0);
				tree2.update(1,1,M,val[x],0);
			}
			sort(v.begin(),v.end(),[&](int i,int j){return val[i]>val[j];});
			for(int x:v)
			{
				int now=tree1.query(1,1,M,x+1,M)+1;
				tree1.update(1,1,M,x,now);
				tree2.update(1,1,M,val[x],now);
				S1.insert({val[x],x});
				S2.insert({x,val[x]});
			}
		}
		else
		{
			int x=gi();
			vector<int>v;
			FOR(i,1,x)
			{
				int p=(*S2.begin()).first;
				if(i!=x)v.pb(p);
				pair<int,int>t=*S2.begin();
				S2.erase(S2.begin());
				swap(t.first,t.second);
				S1.erase(t);
				tree1.update(1,1,M,p,0);
				tree2.update(1,1,M,val[p],0);
				if(i==x)val[p]=0;
			}
			sort(v.begin(),v.end(),[&](int i,int j){return i>j;});
			for(int x:v)
			{
				int now=tree2.query(1,1,M,val[x]+1,M)+1;
				tree1.update(1,1,M,x,now);
				tree2.update(1,1,M,val[x],now);
				S2.insert({x,val[x]});
				S1.insert({val[x],x});
			}
		}
		printf("%d\n",tree1.maxv[1]);
	}
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