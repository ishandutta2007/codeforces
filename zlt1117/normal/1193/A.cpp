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
const int maxn=20,mod=998244353;
int n,m; 
int g[19][(1<<18)],vis[maxn][maxn],f[19][(1<<18)];
inline void FWT(int *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)a[i+j+l]=(a[i+j+l]+a[i+j])%mod;
		}
	}
}
inline void IFWT(int *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)a[i+j+l]=(a[i+j+l]-a[i+j]+mod)%mod;
		}
	}
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();u--,v--;
		vis[u][v]=vis[v][u]=1;
	}
}
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*x*ret%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline void solve()
{
	FOR(i,1,(1<<n)-1)
	{
		vector<int>v;
		FOR(j,0,n-1)if(i>>j&1)v.pb(j);
		bool ok=1;
		for(int a:v)for(int b:v)if(vis[a][b]){ok=0;break;}
		if(ok)g[__builtin_popcount(i)][i]=__builtin_popcount(i)&1?mod-1:1; 
	}
	g[0][0]++;
	FOR(i,0,n)FWT(g[i],n);
	FOR(s,0,(1<<n)-1)
	{
		f[0][s]=qpow(g[0][s],mod-2);
		FOR(i,1,n)
		{
			int now=0;
			FOR(j,0,i-1)now=(now+mod-1ll*g[i-j][s]*f[j][s]%mod)%mod;
			f[i][s]=1ll*f[0][s]*now%mod;
		}
	}
	FOR(i,0,n)IFWT(f[i],n);
	int ans=0;
	ans=(ans+f[n][(1<<n)-1])%mod;
	ans=1ll*ans*m%mod*(mod+1)/2%mod;
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}