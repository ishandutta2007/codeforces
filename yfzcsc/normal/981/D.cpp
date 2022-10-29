#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,dp[60][60];
ll a[60],s[60],S;
bool pd(ll S){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int k=i-1;k>=0;--k)if((s[i]-s[k]&S)==S)
			for(int j=1;j<=m;++j)dp[i][j]|=dp[k][j-1];
	return dp[n][m]==1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
	for(int i=60;i>=0;--i)
		if(pd(S|(1ll<<i)))S|=1ll<<i;
	printf("%lld",S);
}