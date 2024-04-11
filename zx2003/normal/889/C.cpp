#include<cstdio>
const int N=1000005,mo=1000000007;
int n,k,i,fac[N],ans,s,inv[N],vf[N],f[N],j,sum[N];
inline int C(int x,int y){
	return 1ll*fac[x]*vf[x-y]%mo*vf[y]%mo;
}
int main(){
	scanf("%d%d",&n,&k);if(k+1>=n)return puts("0"),0;
	for(i=2,inv[1]=*fac=*vf=fac[1]=vf[1]=1;i<=n;++i){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
		vf[i]=1ll*vf[i-1]*inv[i]%mo;
	}
	for(f[1]=f[2]=1,i=3,s=k<3?k:2;i<=n;++i){
		f[i]=(f[i]+1ll*s*fac[i-2])%mo;
		s=(s+1ll*f[i]*vf[i-1]%mo+mo-(i>k?1ll*f[i-k]*vf[i-k-1]%mo:0))%mo;
	}
	for(i=1,s=0;i<=n;++i)s=(s+1ll*f[i]*C(n-1,i-1)%mo*fac[n-i]%mo)%mo;
	return printf("%d\n",(fac[n]-s+mo)%mo),0;
}