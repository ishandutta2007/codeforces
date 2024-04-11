//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5;
int n,a[maxn],pre[maxn],now[maxn];
set<int>s;
struct segmentree
{
	static const int maxn=4e5+5;
	#define ls u<<1
	#define rs u<<1|1
	int minv[maxn];
	inline void pushup(int u){minv[u]=min(minv[ls],minv[rs]);}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r){minv[u]=v;return ;}
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return minv[u];
		int mid=(l+r)>>1,ret=1e9;
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret=min(ret,query(rs,mid+1,r,x,y));
		return ret;
	}
}tree;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),pre[i]=now[a[i]],now[a[i]]=i;
}
inline void solve()
{
	FOR(i,2,n)
	{
		tree.update(1,1,n,a[i-1],i-1);
		int x=pre[i];
		if(a[i]==1){s.insert(2);continue;}
		else s.insert(1);
		int now1=tree.query(1,1,n,1,a[i]-1);
		if(now1>x)s.insert(a[i]);
	}
	tree.update(1,1,n,a[n],n);
	if(a[n]==1)s.insert(2);
	else s.insert(1); 
	FOR(i,2,n+1)
	{
		int x=now[i];
		int now1=tree.query(1,1,n,1,i-1);
		if(now1>x)s.insert(i);
	}
	FOR(i,1,n+2)if(!s.count(i)){printf("%d\n",i);return;}
}
int main()
{
//	freopen("1.in","r",stdin);
	init();
	input();
	solve();
	return 0;
}