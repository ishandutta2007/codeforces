#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,mo=998244353;
int vf[N],fac[N],inv[N];
inline int C(int n,int m){return 1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
int n,a[N],i,s,b[N],ans=1,tot,zz;
int main(){
	for(int i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]<n)++b[a[i]];
	}
	for(i=0;i<n;++i){
		if(s+=b[i],s>i+1)break;
		ans=(ans+C((i+1)-s+n-1,n-1))%mo;
	}
	if(i==n){
		tot=0;
		memset(b,0,sizeof b);
		for(i=1;i<=n;++i)tot+=a[i],++b[a[i]%n],zz+=a[i]%n;
		ans=0;
		for(i=0;i<n;++i){
			ans=(ans+C((tot-zz)/n+n-1,n-1))%mo;
			zz+=b[i]*n-n;
		}
	}
	printf("%d\n",ans);
	return 0;
}