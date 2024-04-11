#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
pair<long long int,bool> dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			if(i>j||j==0)	continue;
			if(i==j){
				dp[i][j]=make_pair((dp[i-1][j].first+(dp[i-1][j].second^1))%mod,dp[i-1][j].second^1);
				continue;
			}
			if(i==0){
				dp[i][j]=make_pair((dp[i][j-1].first+(dp[i][j-1].second^1))%mod,dp[i][j-1].second^1);
				continue;
			}
			if(dp[i-1][j].second&&dp[i][j-1].second)
				dp[i][j]=make_pair((dp[i-1][j].first+dp[i][j-1].first)%mod,false);
			else
				dp[i][j]=make_pair((dp[i-1][j].first+dp[i][j-1].first+1)%mod,true);
		}
	}
	cout<<dp[n][n].first<<endl;
}