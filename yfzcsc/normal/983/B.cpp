#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii>G[5010];
int dp[5010][5010],b[5010],Q,n,anses[100010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&dp[i][i]),b[i]=dp[i][i];
	for(int i=2;i<=n;++i)
		for(int j=1;j+i-1<=n;j++){
			int l=j,r=j+i-1;
//			dp[l][r]=dp[l][r-1]^dp[l+1][r];
			dp[r][l]=dp[r-1][l]^dp[r][l+1];
		}
	for(int i=1;i<=n;++i)
		for(int j=i-1;j>=1;--j)dp[i][j]=max(dp[i][j],dp[i][j+1]);
	scanf("%d",&Q);
	for(int i=1,l,r;i<=Q;++i)
		scanf("%d%d",&l,&r),G[r].push_back(pii(l,i));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j)b[j]=max(b[j],dp[i][j]);
		for(int j=0;j<G[i].size();++j)
			anses[G[i][j].second]=b[G[i][j].first];
	}
	for(int i=1;i<=Q;++i)printf("%d\n",anses[i]);
}