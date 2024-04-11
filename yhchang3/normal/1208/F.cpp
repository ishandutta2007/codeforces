#include<bits/stdc++.h>
using namespace std;

int a[1000010];
int dp[1<<21][21];


void dfs(int x,int k){
	if(k==-1)	return;
	if(dp[x][k]>1)	return;
	dp[x][k]++;
	dfs(x,k-1);
	if(x&(1<<k))
		dfs(x^(1<<k),k);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=n;i>=1;i--){
		if(i<n-1){
			int res=0;
			int pre=0;
			for(int j=20;j>=0;j--)
				if(a[i]&(1<<j))
					res|=1<<j;
				else if(dp[pre|1<<j][0]>1){
					pre|=1<<j;
					res|=1<<j;
				}
			ans=max(ans,res);
		}
		dfs(a[i],20);
	}
	cout<<ans<<endl;
}