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
const int maxn=1505,mod=1e9+7;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,m,p,k;
int A[maxn],preA[maxn];
int f[maxn],L[maxn][maxn],R[maxn][maxn];
int main()
{
	n=read();m=read();p=read();p=(ll)p*qpow(read(),mod-2)%mod;k=read();
	A[0]=1;
	for(int i=1;i<=m;i++)if(i<=k)A[i]=(ll)A[i-1]*qpow(i,mod-2)%mod*(k-i+1)%mod;
	for(int i=0;i<=m;i++)if(i<=k)A[i]=(ll)A[i]*qpow(p,i)%mod*qpow(1-p+mod,k-i)%mod;
	partial_sum(A,A+m+1,preA,[](const int &i,const int &j){return (i+j>=mod)?i+j-mod:i+j;});
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=m;j>=1;j--)
		{
			(sum+=(ll)A[m-j]*L[i-1][j+1]%mod)%=mod;
			L[i][j]=(L[i][j+1]+(ll)A[j-1]*((ll)preA[m-j]*(f[i-1]-R[i-1][j-1]+mod)%mod-sum+mod)%mod)%mod;
		}

		sum=0;
		for(int j=1;j<=m;j++)
		{
			(sum+=(ll)A[j-1]*R[i-1][j-1]%mod)%=mod;
			R[i][j]=(R[i][j-1]+(ll)A[m-j]*((ll)preA[j-1]*(f[i-1]-L[i-1][j+1]+mod)%mod-sum+mod)%mod)%mod;
		}
		f[i]=L[i][1];
	}
	printf("%d\n",f[n]);
	return 0;
}