#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int n,m,dp[2][3][3],a[1010000],p=0,np=1,b[1001000];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[a[i]]++;
	for(int i=0;i<2;++i)for(int j=0;j<3;++j)for(int k=0;k<3;++k)
		dp[i][j][k]=-inf;
	dp[np][0][0]=0;
	int ans=0;
	for(int i=1;i<=m;++i,swap(p,np)){
		for(int j=0;j<3;++j)for(int k=0;k<3;++k)if(dp[np][j][k]>=0){
			int t=min(b[i]-j-k,min(b[i+1]-k,b[i+2]));
			for(int l=0;l<3&&l<=t;++l){
				dp[p][k][l]=max(dp[p][k][l],dp[np][j][k]+l+(b[i]-j-k-l)/3);
			}
			dp[np][j][k]=-inf;
//			printf("{%d,%d}",j,k);
		}
	}
	int sans=-inf;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			sans=max(sans,ans+dp[np][i][j]);
	printf("%d",sans);
}