#include<bits/stdc++.h>
using namespace std;

int dp[101];

long long int solve(long long int x){
	if(x <= 100)	return dp[x];
	if(x%4 == 0){
		return 1 + solve(x - 2);
	}
	else if(x%2 == 0){
		return x - solve(x>>1);
	}
	else	return x - solve(x - 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 1;
	for(int i=2;i<=100;i++){
		dp[i] = i - dp[i-1];
		if(i%2==0)	dp[i] = max(dp[i], i - dp[i>>1]);
	}
	int T;
	cin >> T;
	while(T--){
		long long int x;
		cin >> x;
		cout << solve(x) << '\n';
	}
	
}