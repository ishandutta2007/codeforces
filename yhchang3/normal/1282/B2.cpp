#include<bits/stdc++.h>
using namespace std;
int a[200001];
long long int dp[200001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,p,k;
		cin>>n>>p>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		dp[0]=0;
		for(int i=1;i<k;i++)
			dp[i]=dp[i-1]+a[i];
		for(int i=k;i<=n;i++)
			dp[i]=dp[i-k]+a[i];
		for(int i=n;i>=0;i--)
			if(dp[i]<=p){
				cout<<i<<'\n';
				break;
			}
	}
}