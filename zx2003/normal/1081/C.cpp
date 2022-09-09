#include<bits/stdc++.h>
const int N=2005,mo=998244353;
int C[N][N],n,m,k,i,j,ans;
int main(){
	for(i=**C=1;i<N;++i)for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	scanf("%d%d%d",&n,&m,&k);
	ans=1ll*m*C[n-1][k]%mo;for(i=1;i<=k;++i)ans=1ll*ans*(m-1)%mo;printf("%d\n",ans);
	return 0;
}