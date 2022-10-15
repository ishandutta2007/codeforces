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
const int maxn=5e3+5;
const int mod=998244353;
int n;
int a[maxn],lim[maxn];
int f[maxn],sum[maxn];
int fac[maxn],inv[maxn];
void prework()
{
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int main()
{
	generate_n(a+1,n=read(),read);
	sort(a+1,a+n+1);
	if(a[n]<a[n-1]*2){puts("0");return 0;}
	for(int i=1;i<=n;i++)
	{
		lim[i]=lim[i-1];
		while(a[lim[i]+1]*2<=a[i])lim[i]++;
	}
	prework();
	f[0]=1;sum[0]=fac[n-1];
	for(int i=1;i<=n;i++)
	{
		f[i]=(ll)sum[lim[i]]*inv[n-lim[i]-1]%mod;
		sum[i]=(sum[i-1]+(ll)f[i]*fac[n-lim[i]-2]%mod)%mod;
	}
	printf("%d\n",f[n]);
	return 0;
}