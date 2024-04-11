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
#define db double
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
int n,a[maxn];
inline int query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	x=gi();
	return x;
//	return a[x];
}
inline void output(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
inline void init()
{

}
inline void input()
{
	n=gi();
//	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	int l=1,r=n;
	while(l<r)
	{
		if(r-l==1)
		{
			int x=query(l);
			int y=query(r);
			if(x<y)output(l);
			else output(r);
		}
		int mid=(l+r)>>1;
		int x=query(mid);
		int val1=query(mid-1);
		int val2=query(mid+1);
		if(x<val1&&x<val2)output(mid);
		if(x>val2)l=mid+1;
		else r=mid-1;
	}
	output(l);
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