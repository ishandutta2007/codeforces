#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int n,dp[2][210][2],s[210],a[100100];
void upd(int& x,int y){
	x=(x+y)%mod;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int p=0,np=1;
	dp[np][0][1]=1;
	for(int i=1;i<=n-1;++i,swap(p,np)){
		memset(dp[p],0,sizeof(dp[p]));
		if(a[i]!=-1){
			for(int j=0;j<=200;++j)
				for(int k=0;k<2;++k)if(dp[np][j][k]){
					int val=dp[np][j][k];
					if(k==0&&j<=a[i])upd(dp[p][a[i]][j>=a[i]],val);
					if(k==1)upd(dp[p][a[i]][j>=a[i]],val);
				}	
		} else {
			auto add=[&](int l,int r,int y,int x){
				upd(dp[p][l][y],x);
				upd(dp[p][r+1][y],mod-x);
			};
			for(int j=0;j<=200;++j)
				for(int k=0;k<2;++k)if(dp[np][j][k]){
					int val=dp[np][j][k];
					if(k==0){
						add(j+1,200,0,val);
						add(j,j,1,val);
					} else {
						add(j+1,200,0,val);
						add(1,j,1,val);
					}
				}
			for(int j=0;j<=200;++j)
				for(int k=0;k<2;++k)
					upd(dp[p][j][k],dp[p][j-1][k]);
		}
	}
	int ans=0;
	for(int i=1;i<=200;++i)if((a[n]==-1)||(a[n]==i)){
		upd(ans,dp[np][i][0]);
		for(int j=200;j>=i;--j)
			upd(ans,dp[np][j][1]);
	}
	ans=(ans%mod+mod)%mod;
	printf("%d",ans);
}