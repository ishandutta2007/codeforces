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
const int mod=998244353;
const int maxn=1e7+5;
const int maxm=720720;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,x,y,k,M;
int a[maxn],L;
int ans;
int f[17][maxm];
int main()
{
	n=read();a[0]=read();x=read();y=read();k=read();M=read();
	for(int i=1;i<n;i++)a[i]=((ll)a[i-1]*x%M+y)%M;
	int L=1;for(int i=1;i<k;i++)L=L*i/__gcd(L,i);
	for(int i=0;i<n;i++)(ans+=a[i]-a[i]%L)%=mod;
	ans=(ll)ans*qpow(n,k-1)%mod*k%mod;
	for(int i=0;i<n;i++)f[0][a[i]%L]++;
	for(int i=0;i<k-1;i++)
		for(int j=0;j<L;j++)
		{
			(f[i+1][j]+=(ll)(n-1)*f[i][j]%mod)%=mod;
			(f[i+1][j-j%(i+1)]+=f[i][j])%=mod;
		}
	for(int i=0;i<k;i++)
		for(int j=1;j<L;j++)
			(ans+=(ll)j*f[i][j]%mod*qpow(n,k-i-1)%mod)%=mod;
	printf("%d\n",ans);
	return 0;
}