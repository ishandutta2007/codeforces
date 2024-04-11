#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e6+5,mod=1e9+7;
int n,m,k;
int fac[maxn],inv[maxn],inv2[maxn];
void prework()
{
	n=1e6;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
	inv2[0]=1;inv2[1]=inv[2];
	for(int i=2;i<=n;i++)inv2[i]=(ll)inv2[i-1]*inv2[1]%mod;
}
int C(int n,int m){if(n<0||m<0||n<m)return 0;return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	T=read();
	prework();
	while(T--)
	{
		n=read();m=read();k=read();
		if(n==m){printf("%lld\n",(ll)k*n%mod);continue;}
		if(m==1){printf("%lld\n",(ll)k*inv2[n-1]%mod);continue;}
		int ans=0;
		for(int i=1;i<=m;i++)(ans+=(ll)C(n-i-1,m-i)*i%mod*k%mod*inv2[n-i]%mod)%=mod;
		printf("%d\n",ans);
	}
	return 0;
}