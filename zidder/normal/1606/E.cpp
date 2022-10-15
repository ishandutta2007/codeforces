#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

long long mod = 998244353;

long long binpow(long long a, long long b){
	return b?binpow(a*a%mod, b>>1)*(b&1?a:1)%mod:1;
}

unordered_map<int, unordered_map<int, long long> > cache;
long long poww(int k, int d){
	if (cache.find(k) != cache.end())
		if (cache[k].find(d) != cache[k].end())
			return cache[k][d];
	return cache[k][d] = binpow(k, d);
}

void solve(int test_ind){
	int n, x;
	cin >> n >> x;
	
	vector<vector<long long> > C(501, vector<long long>(501));
	C[0][0] = 1;
	for (int i=1;i<=500;++i){
		C[i][0] = 1;
		for (int j = 1; j<=i;++j){
			(C[i][j] = C[i-1][j] + C[i-1][j-1]) %= mod;
		}
	}

	vector<vector<long long> > dp(n+1, vector<long long>(x+1));
	dp[0][0] = 1;
    for (int k=2;k<=n;++k){
		for (int j=1;j<=x && j<=k-1;++j)
	    	dp[k][j] = (poww(j, k) - poww(j - 1, k) + mod) % mod;
    }
	for (int i=1;i<=n;++i){
		for (int j=1;j<=x;++j){
			for (int k=0;k<=n-i;++k){
				int d = i + k - 1;
				if (d + j > x || d + j < 0)
					continue;
				long long m = poww(d, k)*C[i+k][k]%mod;
				(dp[i+k][j+d] += m * dp[i][j] % mod) %= mod;
			}
		}
	}

	long long s=0;
	for (int j=1;j<=x;++j)
		(s += dp[n][j]) %= mod;
	cout << s << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}