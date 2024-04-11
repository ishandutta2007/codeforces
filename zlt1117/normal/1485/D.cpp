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
const int maxn=505;
int a[maxn][maxn],n,m;
int lcm1;
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)FOR(j,1,m)a[i][j]=gi();
}
inline int qpow(int x,int k)
{
	int ret=1;
	FOR(i,1,k)ret*=x;
	return ret;
}
inline void solve()
{
	lcm1=1;
	FOR(i,1,16)lcm1=1ll*lcm1*i/__gcd(i,lcm1);
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if((i+j)&1)printf("%d ",lcm1);
			else printf("%d ",lcm1+qpow(a[i][j],4));
		}
		printf("\n");
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