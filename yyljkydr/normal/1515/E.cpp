#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=501;

int P,n;

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

int fac[N],inv[N],pw[N];

void pre(int n)
{
	fac[0]=1;
	pw[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%P,pw[i]=pw[i-1]*2%P;
	inv[n]=qpow(fac[n],P-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
	for(int i=0;i<=n;i++)
		(pw[i]*=inv[i+1])%=P;
}

void inc(int &a,int b)
{
	a+=b;
	a>=P?a-=P:0;
}

int f[N][N];

signed main()
{
	scanf("%lld%lld",&n,&P);
	pre(n+10);	
	f[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;i+2+k<=n+1;k++)
				inc(f[i+2+k][j+k+1],f[i][j]*pw[k]%P);
	int ans=0;
	for(int i=0,j=1;i<=n+1;i++,j=j*i%P)
		inc(ans,f[n+1][i]*j%P);
	printf("%lld\n",ans);
}