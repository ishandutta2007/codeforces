#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int f[60][60],g[60][60],n,m,inv[110],h[60][60];
int qpow(int a,int b){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
		if(b&1)ans=1ll*ans*tmp%mod;
	return ans;
}
int main(){
	for(int i=1;i<=100;++i)inv[i]=qpow(i,mod-2);
	scanf("%d%d",&n,&m);
	f[0][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i+1;++j){
			for(int k=0;k<i;++k){
				for(int l=j;l<=i-k;++l)
					g[i][j]=(g[i][j]+1ll*f[i-k-1][l]*f[k][j])%mod;
				for(int l=j+1;l<=k+1;++l)
					g[i][j]=(g[i][j]+1ll*f[i-k-1][j]*f[k][l])%mod;
			}
//			for(int k=1;k<=i;++k)
//				for(int l=1;l<=j;++l)
//					for(int t=1,z=g[k][l];t*k<=i&&t*l<=j;++t){
//						f[i][j]=(f[i][j]+1ll*z*f[i-k*t][j-l*t])%mod,z=1ll*z*(g[k][l]+t)%mod*inv[t+1]%mod;
//						printf("[%d,%d,%d]",k,l,g[k][l]);
//					}
			memset(h,0,sizeof(h));
			for(int k=0;k<=n;++k)
				for(int l=1;l<=k+1;l++)
					for(int t=1,z=g[i][j];k+t*i<=n;++t)
						h[k+i*t][l+j*t]=(h[k+i*t][l+j*t]+1ll*z*f[k][l])%mod,z=1ll*z*(g[i][j]+t)%mod*inv[t+1]%mod;
			for(int k=0;k<=n;++k)
				for(int l=0;l<=k+1;++l)
					f[k][l]=(f[k][l]+h[k][l])%mod;
//			printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
	printf("%d",f[n][m]);
}