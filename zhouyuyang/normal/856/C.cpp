#include<bits/stdc++.h>
#define mo 998244353
#define N 2005
using namespace std;
int T,p=0,np=1,n,toto,totj,tp;
int a[N],fac[N],b[N],ou[N],ji[N];
int c[233],dp[2][N][11];
void wa(int p){
	tp=0;
	for (;a[p];c[++tp]=a[p]%10,a[p]/=10);
	b[p]=tp&1;
	reverse(c+1,c+tp+1);
	for (int i=1;i<=tp;i++)
		a[p]+=(i&1?c[i]:-c[i]);
	a[p]=(a[p]%11+11)%11;
}
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d",&T); fac[0]=1;
	for (int i=1;i<=2000;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	for (;T--;){
		scanf("%d",&n);
		toto=totj=0;
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]),wa(i);
		for (int i=1;i<=n;i++)
			if (b[i]) ji[++totj]=i;
			else ou[++toto]=i;
		int totJ=(totj+1)/2;
		for (int i=0;i<=n;i++)
			for (int j=0;j<11;j++)
				dp[p][i][j]=dp[np][i][j]=0;
		dp[np][0][0]=1;
		for (int i=1;i<=totj;i++,swap(p,np))
			for (int j=0;j<=i&&j<=totJ;j++)
				for (int k=0;k<11;k++)
					if (dp[np][j][k]){
						int s=dp[np][j][k]; dp[np][j][k]=0;
						upd(dp[p][j+1][(k+a[ji[i]])%11],s);
						upd(dp[p][j][(k+11-a[ji[i]])%11],s);
					}
		for (int i=0;i<11;i++)
			c[i]=1ll*dp[np][totJ][i]*fac[totJ]%mo*fac[totj-totJ]%mo;
		for (int i=0;i<=n;i++)
			for (int j=0;j<11;j++)
				dp[p][i][j]=dp[np][i][j]=0;
		for (int i=0;i<11;i++)
			dp[np][totJ][i]=c[i];
		for (int i=1;i<=toto;i++,swap(p,np))
			for (int j=totJ;j<=totJ+i;j++) 
				for (int k=0;k<11;k++)
					if (dp[np][j][k]){
						int s=dp[np][j][k]; dp[np][j][k]=0;
						upd(dp[p][j][(k+a[ou[i]])%11],1ll*s*(i+totj-j)%mo);
						upd(dp[p][j+1][(k+11-a[ou[i]])%11],1ll*s*j%mo);
					}
		int ans=0;
		for (int i=totJ;i<=n;i++)
			upd(ans,dp[np][i][0]);
		printf("%d\n",ans);
	}
}