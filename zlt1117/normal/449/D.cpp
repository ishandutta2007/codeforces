//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int mod=1e9+7,maxn=(1<<20)+5;
int n,maxx,lim=1;
int S[maxn],a[maxn];
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*x*ret%mod;
		x=1ll*x*x%mod,k>>=1;
	}
	return ret;
}
inline void FWT(int *a,int n)
{
	for(int l=1;l<n;l<<=1)
	{
		for(int i=0;i<n;i+=l<<1)
		{
			for(int j=0;j<l;++j)
			{
				a[i+j]=(a[i+j]+a[i+j+l])%mod;
			}
		}
	}
}
inline void IFWT(int *a,int n)
{
	for(int l=1;l<n;l<<=1)
	{
		for(int i=0;i<n;i+=l<<1)
		{
			for(int j=0;j<l;++j)
			{
				a[i+j]=(a[i+j]-a[i+j+l]+mod)%mod;
			}
		}
	}
}
inline void init()
{

}
int tn;
inline void input()
{
	tn=n=gi();
	FOR(i,1,n)
	{
		a[i]=gi();
		maxx=max(maxx,a[i]);
		S[a[i]]++;
	}
	while(lim<=maxx)lim<<=1;
	n=lim;
}
inline void solve()
{
	FWT(S,n);
	FOR(i,0,n-1)S[i]=qpow(2,S[i])-1;
	IFWT(S,n);
	printf("%d\n",S[0]);
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