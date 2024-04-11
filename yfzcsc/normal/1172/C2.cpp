#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,maxm=3010,mod=998244353;
int n,ri[maxn],a[maxn],wi[maxn],m;
int dp[2][maxm];
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int fen(int x,int y){
	return 1ll*x*qpow(y,mod-2)%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&wi[i]);
	int p=0,np=1;
	dp[np][0]=1;
	int sumadd=0,sumsub=0;
	for(int i=1;i<=n;++i)
		if(a[i])sumadd=(sumadd+wi[i])%mod;
		else sumsub=(sumsub+wi[i])%mod;
	for(int i=1;i<=m;++i,swap(p,np)){
		memset(dp[p],0,sizeof(dp[p]));
		for(int j=0;j<i;++j)if(dp[np][j]){
			int val=dp[np][j];
			dp[p][j+1]=(1ll*val*fen(sumadd+j,sumadd+sumsub+j-(i-1-j))+dp[p][j+1])%mod;
			dp[p][j]=(1ll*val*fen(sumsub-(i-1-j),sumadd+sumsub+j-(i-1-j))+dp[p][j])%mod;
			dp[np][j]=0;
		}
	}
	int ansadd=0,anssub=0;
	for(int i=0;i<=m;++i){
		ansadd=(ansadd+1ll*dp[np][i]*(i+sumadd))%mod;
		anssub=(anssub+1ll*dp[np][i]*(sumsub-(m-i)))%mod;
	}
//	printf("{%d,%d}",ansadd,anssub);
	for(int i=1;i<=n;++i){
		if(a[i]){
			int ans=1ll*ansadd*fen(wi[i],sumadd)%mod;
			printf("%d\n",ans); 
		} else {
			
			int ans=1ll*anssub*fen(wi[i],sumsub)%mod;
			printf("%d\n",ans);
		}
	}
}