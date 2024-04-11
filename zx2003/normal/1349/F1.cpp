#include<bits/stdc++.h>
const int mo=998244353,N=5005;
int n,f[N][N],i,j,ans[N];
int vf[N],fac[N],inv[N];
inline int C(int n,int m){return 1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
int main(){
	for(int i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d",&n);
	f[0][0]=1;
	for(i=1;i<=n;++i)for(j=1;j<=i;++j){
		f[i][j]=(1ll*j*f[i-1][j]+1ll*(i-j+1)*f[i-1][j-1])%mo;
		ans[j]=(ans[j]+1ll*f[i][j]*C(n,i)%mo*fac[n-i])%mo;
	}
	for(i=1;i<=n;++i)printf("%d%c",ans[i],i==n?'\n':' ');
}