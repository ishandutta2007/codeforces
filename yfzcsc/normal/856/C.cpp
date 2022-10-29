#include<bits/stdc++.h>
#define mod 998244353
#define upd(x,y) (x)=((x)+(y))%mod
using namespace std;
int T,dp[2][2010][11],p=0,np=1,a[2010],fac[2010],b[2010],c[100],ou[2010],otp,ji[2010],jtp,tp,n;
void getl(int p){
	tp=0;
	while(a[p])
		c[++tp]=a[p]%10,a[p]/=10;
	b[p]=tp&1;
	reverse(c+1,c+tp+1);
	for(int i=1;i<=tp;++i)
		if(i&1)a[p]+=c[i];
		else a[p]-=c[i];
	a[p]%=11;
	if(a[p]<0)a[p]+=11;
}
int main(){
	scanf("%d",&T),fac[0]=1;
	for(int i=1;i<=2005;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	while(T--){
		scanf("%d",&n),otp=jtp=0;
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]),getl(i);
		for(int i=1;i<=n;++i)
			if(b[i])ji[++jtp]=i;
			else ou[++otp]=i;
		for(int i=0;i<=n;++i)
			for(int j=0;j<11;++j)
				dp[p][i][j]=dp[np][i][j]=0;
		dp[np][0][0]=1;
		for(int i=1;i<=jtp;++i,swap(p,np))
			for(int j=0;j<=i&&j<=(jtp+5)/2;++j)
				for(int k=0;k<11;++k)if(dp[np][j][k]){
					int s=dp[np][j][k];
					upd(dp[p][j+1][(k+a[ji[i]])%11],s);
					upd(dp[p][j][(k-a[ji[i]]+11)%11],s);
					dp[np][j][k]=0;
					
				}
		for(int i=0;i<11;++i)
			c[i]=1ll*dp[np][(jtp+1)/2][i]*fac[(jtp+1)/2]%mod*fac[jtp-(jtp+1)/2]%mod;
		for(int i=0;i<=n;++i)
			for(int j=0;j<11;++j)
				dp[p][i][j]=dp[np][i][j]=0;
		int L=(jtp+1)/2;
		for(int i=0;i<11;++i)
			dp[np][L][i]=c[i];
		for(int i=1;i<=otp;++i,swap(p,np))
			for(int j=L;j<=L+i;j++)
				for(int k=0;k<11;++k)if(dp[np][j][k]){
					int s=dp[np][j][k];
					upd(dp[p][j][(k+a[ou[i]])%11],1ll*s*(i+jtp-j));
					upd(dp[p][j+1][(k-a[ou[i]]+11)%11],1ll*s*j);
					dp[np][j][k]=0;
				}
		int ans=0;
		for(int i=L;i<=n;++i)ans=(ans+dp[np][i][0])%mod;
		printf("%d\n",ans);
	}
}