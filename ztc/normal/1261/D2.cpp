#include<stdio.h>
#define inf 998244353
int n,m,a[200022],cnt;
long long ans=0,mul=1;
int fac[200002],ifac[200002],t2[200002];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);a[n+1]=a[1];
	fac[0]=fac[1]=ifac[0]=ifac[1]=t2[0]=1;
	for(int i=2;i<=n;i++)ifac[i]=inf-1ll*ifac[inf%i]*(inf/i)%inf;
	for(int i=2;i<=n;i++)fac[i]=1ll*fac[i-1]*i%inf,ifac[i]=1ll*ifac[i-1]*ifac[i]%inf;
	for(int i=1;i<=n;i++)t2[i]=t2[i-1]*2%inf;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])mul=mul*m%inf;
		else cnt++;
	}for(int i=0,k=1;i<cnt;i++,k=1ll*k*(m-2)%inf){
		int p=cnt-i,cntt=t2[p];
		if(!(p&1))cntt=(-1ll*fac[p]*ifac[p>>1]%inf*ifac[p>>1]%inf+inf+cntt)%inf;
		ans=(ans+1ll*(inf+1>>1)*cntt%inf*k%inf*fac[cnt]%inf*ifac[i]%inf*ifac[p])%inf;
	}printf("%lld",ans*mul%inf);
}