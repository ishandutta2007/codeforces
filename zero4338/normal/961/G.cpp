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
const int maxn=2e5+5;
const int mod=1e9+7;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,k;
int ans;
int w[maxn];
int fac[maxn],inv[maxn];
void prework()
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int C(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int S(int n,int k)
{
	int ret=0;
	for(int i=0;i<=k;i++)
	{
		int val=(ll)C(k,i)*qpow(k-i,n)%mod;
		if(i&1)ret=(ret-val+mod)%mod;
		else ret=(ret+val)%mod;
	}
	return (ll)ret*inv[k]%mod;
}
int main()
{
	n=read();k=read();
	generate_n(w+1,n,read);
	for(int i=1;i<=n;i++)ans=(ans+w[i])%mod;
	int sum=0;
	prework();
	sum=(S(n,k)+(ll)(n-1)*S(n-1,k)%mod)%mod;
	ans=(ll)ans*sum%mod;
	printf("%d\n",ans);
	return 0;
}