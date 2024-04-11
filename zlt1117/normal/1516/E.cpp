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
inline void chkmax(int &x,int y){if(x<y)x=y;}
inline void chkmin(int &x,int y){if(x>y)x=y;}
const int maxn=405,mod=1e9+7;
int f[maxn][maxn],g[maxn][maxn],n,k,ans[maxn],c[maxn][maxn];
inline void init()
{

}
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,0,2*k)
	{
		f[i][0]=1;c[i][0]=1;
		FOR(j,1,i)f[i][j]=(1ll*f[i-1][j-1]*(i-1)+f[i-1][j])%mod,c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
}
inline int C(int n,int m)
{
	int ret=1,inv=1;
	for(int i=n;i>=n-m+1;--i)ret=1ll*ret*i%mod;
	FOR(i,1,m)inv=1ll*inv*i%mod;
	return 1ll*ret*qpow(inv,mod-2)%mod;
}
inline void solve()
{
	FOR(i,0,2*k)
	{
		FOR(j,0,i)
		{
			int &ans=g[i][j];
			FOR(x,0,i)
			{
				int now=x&1?mod-1:1;
				ans=(ans+1ll*now*f[i-x][j]%mod*c[i][x])%mod;
			}
		}
	}
	FOR(x,1,k)
	{
		int ans=0;
		FOR(i,0,min(n,2*x))
		{
			int now=0;
			FOR(j,0,x/2)now=(now+g[i][x-2*j])%mod;
			ans=(ans+1ll*now*C(n,i))%mod;
		}
		printf("%d ",ans);
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