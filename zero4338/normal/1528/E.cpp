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
const int maxn=1e6+5;
const int mod=998244353;
const int i2=499122177;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n;
int ans;
int f[maxn],sum[maxn],g[maxn];
int inv[15];
int C(int n,int m)
{
	int ret=1;
	for(int i=n;i>=n-m+1;i--)ret=(ll)ret*i%mod;
	for(int i=1;i<=m;i++)ret=(ll)ret*inv[i]%mod;
	return ret;
}
int main()
{
	n=read();
	f[0]=1;sum[0]=1;
	inv[1]=1;for(int i=2;i<=10;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)f[i]=((ll)f[i-1]+(i>=2?(ll)f[i-1]*sum[i-2]%mod:0)+(ll)(f[i-1]+1)*f[i-1]%mod*i2%mod)%mod,sum[i]=(sum[i-1]+f[i])%mod;
	for(int i=1;i<=n;i++)g[i]=(f[i]-f[i-1]+mod)%mod;
	for(int i=0;i<=n-1;i++)ans=(ans+(ll)(f[i]-1)*g[n-i-1]%mod)%mod;
	int tmp=((ll)f[n]+f[n-1]+C(f[n-1],2)*2%mod+C(f[n-1],3)+(ll)(f[n-1]+C(f[n-1],2))*sum[n-2]%mod+(ll)f[n-1]*(sum[n-2]+1)%mod*sum[n-2]%mod*i2%mod)%mod;
	ans=((ll)ans+tmp*2-1)%mod;
	printf("%d\n",ans);
	return 0;

}