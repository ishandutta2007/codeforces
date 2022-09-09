#include<bits/stdc++.h>
const int N=3005,mo=1e9+7;
int n,p[N],i,j,f[N][N],D,inv[N],ans,x,m;
int main(){
	for(i=2,inv[1]=1;i<N;++i)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	scanf("%d%d",&n,&D);m=n+2;
	for(i=1;i<n;++i)scanf("%d",p+i+1);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)f[i][j]=1;
	for(i=n;i;--i){
		for(j=1;j<m;++j)f[i][j+1]=(f[i][j+1]+f[i][j])%mo;
		for(j=1;j<=m;++j)f[p[i]][j]=1ll*f[p[i]][j]*f[i][j]%mo;
	}
	for(i=1;i<=m;++i){
		x=f[1][i];
		for(j=1;j<=m;++j)if(j!=i)x=1ll*(D+mo-j)*(i>j?inv[i-j]:mo-inv[j-i])%mo*x%mo;
		ans=(ans+x)%mo;
	}
	printf("%d\n",ans);
}