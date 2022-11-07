#include<stdio.h>
int n,mod,fac[1000002],ans=0;
int main(){
	scanf("%d%d",&n,&mod);
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		ans=(1ll*(n-i+1)*(n-i+1)%mod*fac[i]%mod*fac[n-i]+ans)%mod;
	}printf("%d",ans);
}