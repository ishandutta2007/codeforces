#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1005;
const int LMT = 2 * N * N;
int dp[LMT];
int sum[LMT];
const int MOD = 1e9 + 7; 

void add(int &a,int b){
	a += b;
	a %= MOD;
}

void init_dp(int k,int t){
	memset(dp,0,sizeof(dp));
	dp[k * t] = 1;
	int lmt = 2 * k * t;
	for (int i=1;i<=t;i++){
		memset(sum,0,sizeof(sum));
		sum[0] = dp[0];
		for (int j=1;j<=lmt;j++){
			add(sum[j],sum[j-1]+dp[j]);
			//cout << sum[j] << endl;
		}
		for (int j=lmt;j>=0;j--){
			int l = max(1LL,j - k);
			int r = min(lmt,j + k);
			dp[j] = 0; 
			//cout << i << ' ' << j << ' ' << sum[r] - sum[l - 1] << endl;
			add(dp[j],sum[r] - sum[l - 1] + MOD);
		}
	}
//	for (int i=0;i<=lmt;i++){
//		cout << i - lmt / 2 << ' ' << dp[i] << endl;
//	}
}

int got (int a,int b,int vl){
	if (vl < a){
		return 0;
	}else if (vl > b){
		return sum[b];
	}else{
		return sum[vl];
	}
}

int solve(int k,int t,int a,int b){
	int res = 0;
	int lmt = k * t * 2;
	sum[0] = dp[0];
	for (int i=1;i<=lmt;i++){
		sum[i] = 0;
		add(sum[i],sum[i - 1] + dp[i]);
	}
	for (int i=0;i<=lmt;i++){
		//cout << '*' << got(0,lmt,i + a - b - 1) << endl;
		add(res,dp[i] * got(0,lmt,i + a - b - 1) % MOD);
		//cout << res << ' ' << sum[got(0,lmt,i + a - b - 1) ] << endl;
	}
	return res % MOD;
}

#undef int
int main(){
#define int long long
	int k,t,a,b;
	cin >> a >> b >> k >> t;
	init_dp(k,t);
	cout << solve (k,t,a,b) << endl;
	//main();
	return 0;
}