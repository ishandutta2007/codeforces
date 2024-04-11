#include<bits/stdc++.h>
using namespace std;

#define int long long

const int P=1e9+7,N=501;

int n,k;

int qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int inv[N],fac[N],pw[N][N];

int C(int n,int m)
{
	int ret=1;
	for(int i=n;i>=n-m+1;i--)
		ret=ret*(i+P)%P;
	ret=ret*inv[m]%P;
	return ret;
}

int s2(int n,int m)
{
	int ret=0;
	for(int k=0;k<=m;k++)
		ret=(ret+((m-k)&1?P-1:1)*pw[k][n]%P*inv[k]%P*inv[m-k]%P)%P;
	return ret;
}

int s1(int n,int m)
{
	int ret=0;
	for(int k=0;k<=m;k++)
		ret=(ret+C(m-n,m+k)*C(m+n,m-k)%P*s2(m+k,k)%P)%P;
	return ret;
}

int ans[N];

signed main()
{
	scanf("%lld%lld",&n,&k);
	fac[0]=1;
	for(int i=1;i<N;i++)
		fac[i]=fac[i-1]*i%P;
	inv[N-1]=qpow(fac[N-1],P-2);
	for(int i=N-2;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			pw[i][j]=qpow(i,j);
	for(int i=0;i<=min(n,k);i++)
		ans[i]=s1(n,i);
	for(int i=2;i<=k;i++)
		ans[i]=(ans[i]+ans[i-2])%P;
	for(int i=1;i<=k;i++)
		printf("%lld%c",ans[i]," \n"[i==k]);
}