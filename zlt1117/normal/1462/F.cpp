#pragma GCC optimize(4)
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
const int maxn=4e5+5;
int n,a[maxn],b[maxn],c[maxn],d[maxn],V,temp[maxn],tot;
inline void update(int *c,int x)
{
	while(x<=V)
	{
		c[x]++;
		x+=x&-x;
	}
}
inline int query(int *c,int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=x&-x;
	}
	return ret;
}
inline void init()
{
	tot=0;
	FOR(i,0,V)a[i]=c[i]=d[i]=temp[i]=0;
}
inline void input()
{
	n=gi();V=n*2;
	FOR(i,1,n)a[i]=gi(),b[i]=gi(),temp[++tot]=a[i],temp[++tot]=b[i];
	sort(temp+1,temp+tot+1);
	tot=unique(temp+1,temp+tot+1)-temp-1;
	FOR(i,1,n)a[i]=lower_bound(temp+1,temp+tot+1,a[i])-temp,b[i]=lower_bound(temp+1,temp+tot+1,b[i])-temp;
}
inline void solve()
{
	FOR(i,1,n)
	{
		update(c,a[i]);
		update(d,b[i]);
	}
	int ans=n;
	FOR(i,1,n)
	{
		int now=0;
		now+=n-query(c,b[i]);
		now+=query(d,a[i]-1);
		ans=min(ans,now);
	}
	printf("%d\n",ans);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}///