#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define int long long
#define sz(x) (int)(x.size())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e6+5,maxt=1e6;
int n,m,p;
struct node
{
	int a,b,cost;
	inline bool operator<(const node &b)const
	{
		return cost<b.cost;
	}
}a[maxn],b[maxn],c[maxn];
int now[maxn];
struct segentree
{
	static const int maxn=4e6+5;
	#define ls u<<1
	#define rs u<<1|1
	int maxv[maxn],tag[maxn];
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			tag[ls]+=tag[u];
			tag[rs]+=tag[u];
			maxv[ls]+=tag[u];
			maxv[rs]+=tag[u];
			tag[u]=0;
		}
	}
	inline void pushup(int u){maxv[u]=max(maxv[ls],maxv[rs]);}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)
		{
			maxv[u]+=v;
			tag[u]+=v;
			return ;
		}
		else
		{
			pushdown(u);
			int mid=(l+r)>>1;
			if(x<=mid)update(ls,l,mid,x,y,v);
			if(y>mid)update(rs,mid+1,r,x,y,v);
			pushup(u);
		}
	}
}tree;
inline bool cmp(const node &a,const node &b)
{
	return a.a<b.a;
}
inline void init()
{
	memset(now,0x3f,sizeof(now));
}
inline void input()
{
	n=gi(),m=gi(),p=gi();
	FOR(i,1,n)a[i].a=gi(),a[i].cost=gi();
	FOR(i,1,m)b[i].a=gi(),b[i].cost=gi(),now[b[i].a]=min(now[b[i].a],b[i].cost);
	FOR(i,1,p)c[i].a=gi(),c[i].b=gi(),c[i].cost=gi();
	sort(a+1,a+n+1);
	sort(c+1,c+p+1,cmp);
	for(int i=1e6;i>=1;--i)now[i]=min(now[i],now[i+1]),tree.update(1,1,maxt,i,i,-now[i]);
}
inline int getans()
{
	return tree.maxv[1];
}
inline void solve()
{
	int nowval=0,nowc=0,ans=-2e9;
	FOR(i,1,n)
	{
		if(a[i].a>nowval)
		{
			nowval=a[i].a;
			while(c[nowc+1].a<nowval&&nowc<p)
			{
				nowc++;
				tree.update(1,1,maxt,c[nowc].b+1,maxt,c[nowc].cost);
			}
			ans=max(ans,getans()-a[i].cost);
		}
	}
	printf("%lld\n",ans);
}
signed main()
{
	init();
	input();
	solve();
	return 0;
}