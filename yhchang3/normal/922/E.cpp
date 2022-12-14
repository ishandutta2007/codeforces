#include<bits/stdc++.h>
using namespace std;

int cnt[1010], cost[1010];

long long int dp[1010][10010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,w,b,x;
	cin>>n>>w>>b>>x;
	for(int i=1;i<=n;i++)
		cin >> cnt[i];
	for(int i=1;i<=n;i++)
		cin >> cost[i];
	memset(dp,-1,sizeof dp);
	dp[0][0] = w;
	int tot = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=tot;j++){
			for(int k=0;k<=cnt[i];k++){
				if(dp[i-1][j] >= 0){
					dp[i][j+k] = max(dp[i][j+k], min(dp[i-1][j] + x, w + 1LL * j * b) - 1LL * cost[i] * k);
				}
			}
		}
		tot += cnt[i];
	}
	for(int i=tot;i>=0;i--)
		if(dp[n][i]>=0){
			cout << i << endl;
			break;
		}
}