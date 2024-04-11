#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=998244353;

int n,m,d[21][N],C[21][21],fac[21],inv[21];

int v[21];

int qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=1ll*ret*a%P;
		b>>=1;
		a=1ll*a*a%P;
	}
	return ret;
}

int main()
{
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[n]=qpow(fac[n],P-2);
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=n;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&d[i][j]);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			v[j]=0;
		for(int j=1;j<=n;j++)
			v[d[j][i]-1]++;
		int s=0,val=1;
		for(int j=0;j<=n;j++)
			val=1ll*val*C[j-s][v[j]]%P*fac[v[j]]%P,s+=v[j];
		ans=(1ll*ans+fac[n]-val%P+P)%P;
	}
	printf("%lld\n",1ll*ans*inv[n]%P);
}