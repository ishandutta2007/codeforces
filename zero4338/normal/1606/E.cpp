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
const int maxn=505;
const int mod=998244353;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,x;
int ans;
int fac[maxn],inv[maxn];
void prework()
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int C(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int f[maxn][maxn];
int main()
{
	n=read();x=read();
	prework();
	for(int i=2;i<=n;i++)
		for(int j=1;j<=x;j++)
		{
			if(j<=i-1)f[i][j]=(qpow(j,i)-qpow(j-1,i)+mod)%mod;
			else for(int k=2;k<=i;k++)f[i][j]=(f[i][j]+(ll)f[k][j-i+1]*C(i,k)%mod*qpow(i-1,i-k)%mod)%mod;
		}
	for(int i=1;i<=x;i++)ans=(ans+f[n][i])%mod;
	printf("%d\n",ans);
	return 0;
}