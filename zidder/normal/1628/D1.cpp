#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD, p/2)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

void solve(int test_ind){
	int n, m, k;
	cin >> n >> m >> k;
	// m out of n is addition
	// f(n, m) = MAX_X[MIN(f(n-1, m) - X, f(n-1, m-1) + X)]
	// f(n, m) = [f(n-1, m) + f(n-1, m-1)] / 2
	// f(0, 0) = 0
	// f(n, 0) = 0
	// f(n, n) = k * n
	long long inv2 = bininv(2);
	vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
	for (int i=1;i<=n;++i){
		dp[i][i] = k * 1ll * i % MOD;
		dp[i][0] = 0;
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<i;++j){
			dp[i][j] = (dp[i-1][j] + 0ll + dp[i-1][j-1]) % MOD * inv2 % MOD;
		}
	}

	cout << dp[n][m] << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}