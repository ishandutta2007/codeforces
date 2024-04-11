#include<cstdio>
const int N=5005,mo=998244353;
int a,b,c,i,j,k,fac[N],vf[N],inv[N],ans,x,y,z;
inline int C(int x,int y){
	return 1ll*fac[x]*vf[y]%mo*vf[x-y]%mo;
}
int main(){
	scanf("%d%d%d",&a,&b,&c);
	vf[1]=inv[1]=*vf=*fac=1;
	for(i=1;i<=a || i<=b || i<=c;++i)fac[i]=1ll*fac[i-1]*i%mo;
	for(i=2;i<=a || i<=b || i<=c;++i)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo,vf[i]=1ll*vf[i-1]*inv[i]%mo;
	for(i=0;i<=a && i<=b;++i)x=(x+1ll*C(a,i)*C(b,i)%mo*fac[i])%mo;
	for(i=0;i<=b && i<=c;++i)y=(y+1ll*C(b,i)*C(c,i)%mo*fac[i])%mo;
	for(i=0;i<=c && i<=a;++i)z=(z+1ll*C(c,i)*C(a,i)%mo*fac[i])%mo;
	ans=1ll*x*y%mo*z%mo;
	printf("%d\n",ans);
	return 0;
}