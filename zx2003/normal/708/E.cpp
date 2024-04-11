#include<bits/stdc++.h>
const int N=1505,mo=1e9+7,K=1e5+5;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int vf[K],fac[K],inv[K];
inline int C(int n,int m){return n<m?0:1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
int n,m,a,b,i,j,k,p,f[N],g[N][N],h[N][N],mi1[K],mi2[K],ans;
int main(){
	for(int i=*vf=*fac=1;i<K;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);p=1ll*a*poww(b,mo-2)%mo;
	std::swap(n,m);
	for(i=*mi1=*mi2=1;i<K;++i)mi1[i]=1ll*mi1[i-1]*p%mo,mi2[i]=1ll*mi2[i-1]*(1+mo-p)%mo;
	f[0]=mi2[k];for(i=1;i<=n;++i)f[i]=(f[i-1]+1ll*mi1[i]*mi2[k-i]%mo*C(k,i))%mo;
	for(i=1;i<=n;++i)g[2][i]=1ll*f[i-1]*f[n-i]%mo;
	for(i=1;i<n;++i)h[2][i]=mo-1ll*f[i-1]*f[n-i-1]%mo;
	for(i=3;i<=m;++i){
		a=0;
		for(j=1;j<=n;++j){
			a=(a+(j>1?1ll*f[j-2]*h[i-1][j-1]:0))%mo;
			a=(a+1ll*f[j-1]*g[i-1][j])%mo;
//			if(j<n)h[i][j]=(a+1ll*f[j-1]*g[i-1][j+1])%mo*(mo-f[n-j-1])%mo;
			if(j<n)h[i][j]=1ll*a*(mo-f[n-j-1])%mo;
			g[i][j]=1ll*a*f[n-j]%mo;
		}
		a=0;
		for(j=n;j;--j){
//			if(j<n)h[i][j]=(h[i][j]+(a+1ll*f[n-j-1]*g[i-1][j])%mo*(mo-f[j-1]))%mo;
			a=(a+(j<n?1ll*f[n-j-1]*h[i-1][j]:0))%mo;
			if(j<n)h[i][j]=(h[i][j]+1ll*a*(mo-f[j-1]))%mo;
			g[i][j]=(g[i][j]+1ll*a*f[j-1])%mo;
			a=(a+1ll*f[n-j]*g[i-1][j])%mo;
		}
	}
	if(m==1){
		for(i=1;i<=n;++i)g[m][i]=1;
		for(i=1;i<n;++i)h[m][i]=mo-1;
	}
	for(i=1;i<=n;++i)ans=(ans+1ll*f[i-1]*f[n-i]%mo*g[m][i])%mo;
	for(i=1;i<n;++i)ans=(ans+1ll*f[i-1]*f[n-i-1]%mo*h[m][i])%mo;
	printf("%d\n",ans);
	return 0;
}