#include<bits/stdc++.h>
const int N=2e5+5,mo=998244353,iv2=mo+1>>1;
int vf[N],fac[N],inv[N];
inline int C(int n,int m){return 1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
int n,k,h[N],i,m,mi[N],mi2[N],ans;
int main(){
	for(int i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d%d",&n,&k);
	if(k==1){puts("0");return 0;}
	for(i=*mi=*mi2=1;i<N;++i)mi[i]=1ll*mi[i-1]*(k-2)%mo,mi2[i]=2ll*mi2[i-1]%mo;
	for(i=1;i<=n;++i)scanf("%d",h+i);for(i=1;i<=n;++i)m+=h[i]!=h[i%n+1];
	for(i=1;i<=m;++i)
		ans=(ans+1ll*C(m,i)*mi[m-i]%mo*(mi2[i]+(i&1?0:mo-C(i,i/2)))%mo*iv2)%mo;
	for(i=0;i<n-m;++i)ans=1ll*ans*k%mo;
	printf("%d\n",ans);
	return 0;
}