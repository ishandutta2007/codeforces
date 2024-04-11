#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[100100],dp[510][510];
set<int> st;
int dfs(int l,int r){
	if(l==r)return 1;
	if(l>r)return 1;
	if(~dp[l][r])return dp[l][r];
	dp[l][r]=0;
	int z=min_element(a+l,a+r+1)-a;
	int sum1=0,sum2=0;
	for(int i=z;i<=r;++i){
		sum1=(sum1+1ll*dfs(z+1,i)%mod*dfs(i+1,r))%mod;
	}
	
	for(int i=z;i>=l;--i){
		sum2=(sum2+1ll*dfs(i,z-1)%mod*dfs(l,i-1))%mod;
	}
	return dp[l][r]=1ll*sum1*sum2%mod;
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		st.insert(a[i]);
	}
	if(st.size()!=n){
		puts("0");
		return 0;
	}
	printf("%d",dfs(1,n)); 
}