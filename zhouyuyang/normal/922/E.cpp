#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int MAXM=10005,MAXN=1005;
ll n,W,B,X,m,dp[MAXN][MAXM],c[MAXN],cost[MAXN];
int main(){
	scanf("%lld%lld%lld%lld",&n,&W,&B,&X);
	for (int i=1;i<=n;i++)
		scanf("%lld",&c[i]),m+=c[i];
	for (int i=1;i<=n;i++)
		scanf("%Ild",&cost[i]);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=W;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++){
			ll max_mana=W+j*B;
			for (int k=0;k<=min((ll)j,c[i]);k++){
				if (dp[i-1][j-k]==-1) continue;
				ll new_mana=min(B*(j-k)+W,X+dp[i-1][j-k])-k*cost[i];
				if (new_mana<0) continue;
				dp[i][j]=max(dp[i][j],min(max_mana,new_mana));
				ans=max(ans,j);max_mana+=B;
			}
		}
	printf("%d\n",ans);
}