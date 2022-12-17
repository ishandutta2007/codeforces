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
const int maxn=(1<<17)+5,mod=1e9+7;
int n,cnt[maxn],fib[maxn];
int a[18][maxn],b[18][maxn],c[maxn];
int maxv;
inline int count(int x){int ret=0;while(x)ret+=x&1,x>>=1;return ret;}
inline int getlen(int x){int bit=0;while((1<<bit)<=maxv)bit++;return bit;}
inline void fwt_or(int *a,int n,int typ)
{
	for(int l=1;l<n;l<<=1)
	{
		for(int i=0;i<n;i+=l<<1)
		{
			for(int j=0;j<l;++j)
			{
				if(typ==1)a[i+j+l]=(a[i+j+l]+a[i+j])%mod;
				else a[i+j+l]=(a[i+j+l]-a[i+j]+mod)%mod;
			}
		}
	}
}
inline void fwt_and(int *a,int n,int typ)
{
	for(int l=1;l<n;l<<=1)
	{
		for(int i=0;i<n;i+=l<<1)
		{
			for(int j=0;j<l;++j)
			{
				if(typ==1)a[i+j]=(a[i+j+l]+a[i+j])%mod;
				else a[i+j]=(a[i+j]-a[i+j+l]+mod)%mod;
			}
		}
	}
}
inline void fwt_xor(int *a,int n,int typ)
{
	for(int l=1;l<n;l<<=1)
	{
		for(int i=0;i<n;i+=l<<1)
		{
			for(int j=0;j<l;++j)
			{
				int x=a[i+j],y=a[i+j+l];
				if(typ==1)a[i+j]=(x+y)%mod,a[i+j+l]=(x-y+mod)%mod;
				else a[i+j]=1ll*(mod+1)/2*(x+y)%mod,a[i+j+l]=1ll*(mod+1)/2*(x-y+mod)%mod;
			}
		}
	}
}
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n){int x=gi();cnt[x]++;maxv=max(maxv,x);}
	n=getlen(maxv);
}
int A[maxn],B[maxn],C[maxn];
inline void solve()
{
	fib[0]=0;fib[1]=1;
	FOR(i,2,(1<<n)-1)fib[i]=fib[i-1]+fib[i-2],fib[i]%=mod; 
	FOR(i,0,(1<<n)-1)a[count(i)][i]=cnt[i];
	FOR(i,0,n)fwt_or(a[i],(1<<n),1);
	FOR(i,0,n)FOR(j,0,i)FOR(k,0,(1<<n)-1)b[i][k]=(b[i][k]+1ll*a[j][k]*a[i-j][k])%mod;
	FOR(i,0,n)fwt_or(b[i],(1<<n),-1);
	FOR(i,0,(1<<n)-1)A[i]=1ll*fib[i]*b[count(i)][i]%mod;
	FOR(i,0,(1<<n)-1)B[i]=1ll*fib[i]*cnt[i]%mod;
	FOR(i,0,(1<<n)-1)c[i]=cnt[i];
	fwt_xor(c,(1<<n),1);
	FOR(i,0,(1<<n)-1)c[i]=1ll*c[i]*c[i]%mod;
	fwt_xor(c,(1<<n),-1);
	FOR(i,0,(1<<n)-1)C[i]=1ll*fib[i]*c[i]%mod;
	fwt_and(A,(1<<n),1);
	fwt_and(B,(1<<n),1);
	fwt_and(C,(1<<n),1);
	FOR(i,0,(1<<n)-1)A[i]=1ll*A[i]*B[i]%mod*C[i]%mod;
	fwt_and(A,(1<<n),-1);
	int ans=0;
	FOR(i,0,n-1)ans=(ans+A[1<<i])%mod;
	printf("%d\n",ans);
}
int main()
{
	int T=1;
//	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}