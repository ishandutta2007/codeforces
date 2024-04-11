#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
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
const int maxn=3605,mod=998244353;
int n,m,k,x,y;
ll f[maxn][maxn],g[maxn][maxn];///f==>line g==>column
bool visx[maxn],visy[maxn];
ll inv[maxn],fac[maxn];
inline ll C(int x,int y){if(x<y)return 0;return ((fac[x]*inv[y]%mod)*inv[x-y]%mod);}
inline void init()
{
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	FOR(i,2,3600)fac[i]=fac[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,3600)inv[i]=(inv[i]*inv[i-1])%mod;
}
inline void input()
{
	n=gi(),m=gi(),k=gi();
	FOR(i,1,k)
	{
		x=gi(),y=gi();
		visy[x]=1,visx[y]=1;
		x=gi(),y=gi();
		visy[x]=1,visx[y]=1;
	}
}
inline void solve()
{
	int cntx=0,cnty=0;
	int maxv=max(n,m);///we can choose at most this amount
	FOR(i,0,n)f[i][0]=1;///element from 0
	///visx means when we calulate the lines what we cannot place domino 
	FOR(i,1,m)if(!visx[i])cntx++;
	FOR(i,1,n)if(!visy[i])cnty++;
	FOR(i,2,n)///column
	{
		FOR(j,1,maxv)
		{
			f[i][j]=f[i-1][j];
			if(!visy[i]&&!visy[i-1])f[i][j]=(f[i][j]+f[i-2][j-1])%mod;
		}
	}
	FOR(i,0,m)g[i][0]=1;
	FOR(i,2,m)///line
	{
		FOR(j,1,maxv)
		{
			g[i][j]=g[i-1][j];
			if(!visx[i]&&!visx[i-1])g[i][j]=(g[i][j]+g[i-2][j-1])%mod;
		}
	}
	ll ans=0;
	FOR(i,0,maxv)///the line choose i (two blocks)
	{
		FOR(j,0,maxv)///the column choose j (two blocks)
		{
			if(2*i+j<=cntx&&2*j+i<=cnty);else continue;
			ll sum=g[m][i]*f[n][j]%mod;
			sum=(sum*C(cntx-2*i,j)%mod)*C(cnty-2*j,i)%mod;
			sum=sum*(fac[i]*fac[j]%mod)%mod;///choose which line and columns order
			ans=(ans+sum)%mod;
		}
	}
	printf("%lld\n",ans);
}
int main()
{
//	T=gi();
//	while(T--)
//	{
		init();
		input();
		solve();
//	}
	return 0;
}