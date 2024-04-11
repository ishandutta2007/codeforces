#include<bits/stdc++.h>
const int N=2005,mo=998244353;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int fac[N],vf[N],inv[N];
int n,k,l[55],S,f[55][N],i,j,o,p,q,w[2][N],ans;
int main(){
	for(i=*fac=*vf=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%mo,
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,vf[i]=1ll*vf[i-1]*inv[i]%mo;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",l+i),S+=l[i];
	**f=1;
	for(i=1;i<=n;++i){
		int lm=(l[i]-1)/k;
		for(j=0;j<=lm;++j)w[0][j]=1ll*vf[j]*poww(1ll*inv[S]*(l[i]-j*k)%mo,j)%mo;
		for(j=0;j<lm;++j)w[1][j]=1ll*vf[j]*poww(1ll*inv[S]*(l[i]-j*k-k)%mo,j)%mo;
		for(j=n;j>=0;--j)for(p=S/k;p>=0;--p){
			int nv=0;
			for(o=0;o<2 && o<=j;++o)for(q=0;q<=lm-o && q<=p;++q)nv=(nv+1ll*f[j-o][p-q]*w[o][q])%mo;
			f[j][p]=nv;
		}
	}
	ans=0;
	for(i=0;i<=n;++i)for(j=0;j<=S/k && (i+j)*k<S;++j){
		q=1ll*inv[S]*(S-(i+j)*k)%mo;
		if(q==1)continue;
		ans=(ans+1ll*poww(poww(1+mo-q,mo-2),j+1)*(i+j&1?fac[j]:mo-fac[j])%mo*f[i][j])%mo;
	}
	printf("%d\n",ans);
}