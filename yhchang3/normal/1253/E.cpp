#include<bits/stdc++.h>
using namespace std;

int dp[100001];

int x[81],s[81];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>s[i];
	for(int i=1;i<=m;i++)
		dp[i]=i;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			if(x[j]+s[j]>=i)
				dp[i]=min(dp[i],dp[max(0,x[j]-s[j]-1)]);
			else
				dp[i]=min(dp[i],dp[max(0,x[j]+x[j]-i-1)]+i-x[j]-s[j]);
	}	
	cout<<dp[m]<<endl;
}