#include<bits/stdc++.h>
const int K=5005,mo=1000000007,inv2=(mo+1)>>1;
int s[K][K],n,k,i,j,ans,fac[K],C,mi;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);if(n==1)return puts("1"),0;s[1][1]=1;
	for(i=2;i<=k;++i)
		for(j=1;j<=i;++j)
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mo;
	for(i=*fac=1;i<=k;++i)fac[i]=1ll*fac[i-1]*i%mo;mi=poww(2,n-1);
	for(i=1,C=n;i<=k && i<=n;++i){
		ans=(ans+1ll*s[k][i]*fac[i]%mo*C%mo*mi)%mo;
		mi=1ll*mi*inv2%mo;
		C=1ll*C*(n-i)%mo*poww(i+1,mo-2)%mo;
	}
	printf("%d\n",ans);
	return 0;
}