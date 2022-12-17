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
const int maxn=105,mod=1e9+7;
int inv[maxn],fac[maxn],len,n,a[maxn],k;
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
inline void getinv()
{
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	FOR(i,2,maxn-1)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline int C(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
struct Matrix
{
	int a[maxn][maxn];
	Matrix(){FOR(i,0,len)FOR(j,0,len)a[i][j]=0;}
	inline Matrix operator*(const Matrix &b)
	{
		Matrix ret;
		FOR(k,0,len)
		{
			FOR(i,0,len)
			{
				FOR(j,0,len)ret.a[i][j]=(ret.a[i][j]+1ll*a[i][k]*b.a[k][j])%mod;
			}
		}
		return ret;
	}
}A,B;
inline void init()
{
	getinv();
}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,1,n)a[i]=gi(),len+=a[i]==1;
}
inline void solve()
{
	int cnt=0;
	FOR(i,n-len+1,n)cnt+=a[i]==1;
	A.a[0][cnt]=1;
	int tt=k;
	FOR(i,0,len)
	{
		int &x=B.a[i][i];
		x=(x+1ll*C(i,1)*C(len-i,1))%mod;
		x=(x+1ll*(n-len)*(n-len-1)/2)%mod;
		x=(x+1ll*C(len-i,1)*C((n-len)-(len-i),1))%mod;
		x=(x+1ll*len*(len-1)/2)%mod;
		if(i>0)
		{
			int &x=B.a[i][i-1];
			x=1ll*C(i,1)*C((n-len)-(len-i),1)%mod;
		}
		if(i<len)
		{
			int &x=B.a[i][i+1];
			x=1ll*C(len-i,1)*C(len-i,1)%mod;
		}
	}
	while(k)
	{
		if(k&1)A=A*B;
		B=B*B;k>>=1;
	}
	int ans=A.a[0][len];
	//cerr<<ans<<endl;
	ans=1ll*ans*qpow(qpow(n*(n-1)/2,tt),mod-2)%mod;
	printf("%d\n",ans);
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