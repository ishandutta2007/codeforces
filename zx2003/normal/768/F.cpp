#include<cstdio>
#include<algorithm>
#include<iostream>
const int N=100005,mo=1000000007;
int fac[N],inv[N],vf[N],f,w,h;
inline int pow(int x,int y){
	register int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;
}
inline int C(int x,int y){
	return 1ll*fac[x]*vf[y]%mo*vf[x-y]%mo;
}
inline int calc(int h){
	register int i=1,ans=0;
	for(;i*h+i<=w;++i){
		if(i<=f)ans=(ans+2ll*C(f-1,i-1)*C(w-i*h-1,i-1))%mo;
		if(f>=i-1 && i>1)ans=(ans+1ll*C(f-1,i-2)*C(w-i*h-1,i-1))%mo;
		if(i<f)ans=(ans+1ll*C(f-1,i)*C(w-i*h-1,i-1))%mo;
	}
	return ans;
}
int main(){
	register int i;
	scanf("%d%d%d",&f,&w,&h);
	if(f==0)return puts(w>h?"1":"0"),0;
	if(w==0)return puts("1"),0;
	*fac=fac[1]=*inv=*vf=inv[1]=vf[1]=1;
	for(i=2;i<=f || i<=w;++i)
		fac[i]=1ll*fac[i-1]*i%mo,inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo,vf[i]=1ll*vf[i-1]*inv[i]%mo;
	return std::cout<<1ll*calc(h)*pow(calc(0),mo-2)%mo<<'\n',0; 
}