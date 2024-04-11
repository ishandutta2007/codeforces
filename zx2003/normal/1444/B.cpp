#include<bits/stdc++.h>
const int N=1e6+5,mo=998244353;
int vf[N],fac[N],inv[N];
inline int C(int n,int m){return 1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
int n,a[N],i,ans;
int main(){
	for(int i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d",&n);
	for(i=1;i<=n*2;++i)scanf("%d",a+i);
	std::sort(a+1,a+n*2+1);
	for(i=1;i<=n;++i)ans=(ans+a[i+n]-a[i])%mo;
	ans=1ll*ans*C(2*n,n)%mo;
	printf("%d\n",ans);
}