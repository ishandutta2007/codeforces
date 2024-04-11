#include<bits/stdc++.h>
const int N=1e6+5,mo=998244353;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int vf[N],fac[N],inv[N],n,i,ans,x,y,z;
inline int C(int n,int m){return 1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
int main(){
	for(i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d",&n);
	ans=poww((poww(3,n)+mo-3)%mo,n);
	for(i=1;i<=n;++i){
		x=1ll*poww(3,1ll*n*(n-i)%(mo-1))*(poww(3,i)+mo-3)%mo;
		if(i<n)x=(x+3ll*poww((poww(3,n-i)+mo-1)%mo,n))%mo;
		ans=(ans+1ll*(i&1?mo-C(n,i):C(n,i))*x)%mo;
	}
	ans=(poww(3,1ll*n*n%(mo-1))+mo-ans)%mo;
	printf("%d\n",ans);
}