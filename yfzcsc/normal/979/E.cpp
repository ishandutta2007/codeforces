#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 201000
using namespace std;
typedef long long ll;
int dp[maxn][2][2][2],n,p,a[maxn],pw[maxn];
void upd(int& x,ll y){
	x=(x+y)%mod;
}
int main(){
	scanf("%d%d",&n,&p),pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=1ll*pw[i-1]*2%mod;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	dp[0][0][0][0]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<2;++j)//white %2==1 exist?
			for(int k=0;k<2;++k)//black %2==1 exist?
				for(int l=0;l<2;++l)if(dp[i][j][k][l]){
					int val=dp[i][j][k][l];
					if(a[i+1]==0||a[i+1]==-1){
						int x0=0,x1=0;
						if(k==0)x0=pw[i],x1=0;
						else x0=pw[i-1],x1=pw[i-1];
						upd(dp[i+1][j|0][k][l^0],1ll*val*x1);
						upd(dp[i+1][j|1][k][l^1],1ll*val*x0);
					}
					if(a[i+1]==1||a[i+1]==-1){
						int x0=0,x1=0;
						if(j==0)x0=pw[i],x1=0;
						else x0=pw[i-1],x1=pw[i-1];
						upd(dp[i+1][j][k|0][l^0],1ll*val*x1);
						upd(dp[i+1][j][k|1][l^1],1ll*val*x0);
					}
				}
	int ans=0;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			ans=(ans+dp[n][i][j][p])%mod;
	printf("%d",ans);
}