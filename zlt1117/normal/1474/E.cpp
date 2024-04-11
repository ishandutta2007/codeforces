//#pragma GCC optimize(4)
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
int n;
inline void init()
{

}
inline void input()
{
	n=gi();
}
inline void solve()
{
	ll ans=0;
	FOR(i,2,n)ans=ans+max(1ll*(i-1)*(i-1),1ll*(n-i)*(n-i));
	printf("%lld\n",ans);
	if(n%2==0)
	{
		printf("%d ",n/2+1);
		FOR(i,2,n/2)printf("%d ",i-1);
		FOR(i,n/2+1,n-1)printf("%d ",i+1);
		printf("%d\n",n/2);
		printf("%d\n",n-1);
		FOR(i,n/2+1,n-1)printf("%d 1\n",i);
		for(int i=n/2;i>=1;--i)printf("%d %d\n",i,n);
	}
	else
	{
		printf("%d ",n-1);
		FOR(i,1,n/2-1)printf("%d ",i);
		printf("%d ",n);
		FOR(i,n/2+1,n-2)printf("%d ",i);
		printf("%d\n",n/2);
		printf("%d\n",n-1);
		for(int i=n/2;i>=2;--i)printf("%d %d\n",i,n);
		for(int i=n-1;i>=n/2+1;--i)printf("%d %d\n",i,1);
		printf("1 %d\n",n);
		
	}
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