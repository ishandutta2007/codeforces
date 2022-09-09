#include<iostream>
const int mo=998244353,N=2005;
int n,cp[N][N],scc[N],f[N],C[N][N],p,mi1[N],mi2[N],a,b,i,j;
inline int pow(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)y&1?ans=1ll*ans*x%mo:0;return ans;}
int main(){
	std::cin>>n>>a>>b;p=1ll*a*pow(b,mo-2)%mo;
	for(i=*mi1=*mi2=1;i<=n;++i)mi1[i]=1ll*mi1[i-1]*p%mo,mi2[i]=1ll*mi2[i-1]*(mo+1-p)%mo;
	for(i=2,cp[1][0]=cp[1][1]=1;i<=n;++i)
		for(*cp[i]=j=1;j<=i;++j)cp[i][j]=(1ll*cp[i-1][j]*mi2[j]+1ll*cp[i-1][j-1]*mi1[i-j])%mo;
	for(i=2,scc[1]=1;i<=n;++i)
		for(j=scc[i]=1;j<i;++j)scc[i]=(scc[i]+mo-1ll*scc[j]*cp[i][j]%mo)%mo;
	for(i=2;i<=n;++i){
		a=1+mo-scc[i];b=1ll*scc[i]*(i*(i-1)>>1)%mo;
		for(j=1;j<i;++j)b=(b+1ll*cp[i][j]*scc[j]%mo*((i-j)*j+(j*(j-1)>>1)+f[i-j]+f[j])%mo)%mo;
		f[i]=1ll*pow(a,mo-2)*b%mo;
	}
	return std::cout<<f[n],0;
}