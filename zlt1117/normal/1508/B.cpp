//#pragma GCC optimize("Ofast")
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
ll n,k,f[64];
inline void init()
{
	
}
inline void input()
{
	scanf("%lld%lld",&n,&k);
}
inline void solve()
{
	if(n<=62&&(1LL<<(n-1))<k)return puts("-1"),void();
	for(int i=n-1;i>=0;--i)
	{
		if(k>f[i]&&i<=62)
		{
			int j=i;k-=f[i];j--;
			while(j>=1&&k>f[j])k-=f[j],j--;
			FOR(kk,j,i)printf("%lld ",n-kk);
			i=j;
		}
		else printf("%lld ",n-i);
	}
	printf("\n");
}
int main()
{
	int T=1;
	T=gi();
	f[0]=1;FOR(i,1,62)f[i]=1LL<<(i-1);
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}