#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],M[100005],Max[7][N],dp[N][N],ycl[N],b[N],sum,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]); if(M[a[i]])b[i]=M[a[i]]; else{
		M[a[i]]=b[i]=++sum; ycl[sum]=a[i]%7;
	}}
	for(int i=1;i<=n;i++){int zs=a[i]%7;
		for(int j=1;j<=sum;j++)Max[zs][j]=max(dp[b[i]][j]=max(Max[zs][j],max(dp[b[i]][j],max(dp[M[a[i]+1]][j],dp[M[a[i]-1]][j])))+1,Max[zs][j]);
		for(int j=1;j<=sum;j++)Max[ycl[j]][b[i]]=max(Max[ycl[j]][b[i]],dp[j][b[i]]=dp[b[i]][j]);
	}
	for(int i=0;i<7;i++)for(int j=1;j<=sum;j++)ans=max(ans,Max[i][j]);
	cout<<ans<<endl;
}