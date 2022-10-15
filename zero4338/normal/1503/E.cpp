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
const int maxn=2e3+50;
const int mod=998244353;
int n,m;
int ans;
int fac[maxn<<1],inv[maxn<<1];
void prework()
{
	fac[0]=1;for(int i=1;i<=n+m;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;for(int i=2;i<=n+m;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n+m;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int C(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	n=read();m=read();
	if(n>m)swap(n,m);
	prework();
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<m;j++)
		{
			tmp=(tmp+(ll)C(i+j-2,i-1)*C(i-2+m-j,i-2)%mod)%mod;
			ans=(ans+(ll)tmp*C(n-i+m-j,n-i+1)%mod*C(n-i+j,n-i)%mod)%mod;
		}
	}
	for(int i=1;i<=m-1;i++)
	{
		int tmp=0;
		for(int j=n-2;j>=1;j--)
		{
			tmp=(tmp+(ll)C(j+i,j+1)*C(n-j-2+i,n-j-2)%mod)%mod;
			ans=(ans+(ll)C(m+j-i-1,m-i)*C(n+m-i-1-j,m-i-1)%mod*tmp%mod)%mod;
		}
	}
	ans=ans*2%mod;
	printf("%d\n",ans);
	return 0;
}