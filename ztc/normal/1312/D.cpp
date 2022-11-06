#include<stdio.h>
#define mod 998244353
int n,m,fac[200002],ifac[200002];
int main(){
	scanf("%d%d",&n,&m);
	if(n==2)return printf("0")&0;
	fac[0]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=m;i++)ifac[i]=mod-1ull*ifac[mod%i]*(mod/i)%mod;
	for(int i=1;i<=m;i++)
		fac[i]=1ull*fac[i-1]*i%mod,
		ifac[i]=1ull*ifac[i-1]*ifac[i]%mod;
	int ans=1ull*fac[m]*ifac[n-1]%mod*ifac[m-n+1]%mod;
	ans=1ull*ans*(n-2)%mod;
	for(int i=1;i<=n-3;i++)ans=ans*2%mod;
	printf("%d",ans);
}