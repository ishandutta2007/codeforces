#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long binpow(long long a, long long p, long long M) {
	return p?binpow(a*a%M, p>>1, M)*(p&1?a:1)%M:1;
}

long long bininv(long long a, long long M){
	return binpow(a, M-2, M);
}

int C[500][500];
__int128 dp[500][500];

void solve(int test_ind){
	int n, M;
	cin >> n >> M;
	// last is x => x+1 is not on or x-1 is not on
	// [1, x-1] X [x+2, n] or [1, x-2] X [x+1, n] or [1, x-2] X [x+2, n]
	// n length = sum x (x-1)X(n-x-1), (x-2) X (n-x), (x-2)X(n-x-1)
	// [n, k] = sum x=1 to n sum q [x-1, q] [n-x-1, k-q-1] * C[k-1][q] + [x-2][q] [n-x, k-q-1] * C[k-1][q]
	// [n, k] = ( sum x=1 to n sum q [x-1, q] [n-x-1, k-q-1] + [x-2][q] [n-x, k-q-1] + [x-2][q] [n-x-1, k-q-1] ) / k
	// A = 1 + \int_y A^2(2x^2 + x^3)
	// A'y = A^2 x^2 (2+x)

	// A = 1 / (1 - (x^3+2x^2)y)
	// A' = 1 / (1 - (x^3+2x^2)y)^2 * (x^3 + 2x^2)
	//
	
	// dp[-1][0] = 1;
	// dp[0][0] = 1;
	// [1, 1] = 1
	// [2, 2] = 2
	// [3, 2] = 2
	// [3, 3] = 4
	// [4, 3] = 12
	// [4, 4] = 8
	
	vector<int> fact(500, 1), ifact(500);
	for (int i=1;i<500;++i) fact[i] = fact[i-1] * 1ll * i % M;
	for (int i=0;i<500;++i) ifact[i] = bininv(fact[i], M);

	auto CC = [&](int n, int k) -> int {
		if (k > n || k < 0) return 0;
		return fact[n] * 1ll * ifact[k] % M * 1ll * ifact[n-k] % M;
	};
	for (int i=0;i<500;++i) for (int j=0;j<500;++j) C[i][j] = CC(i, j);

	dp[1][1] = 1;
	dp[2][2] = 2;
	dp[3][2] = 2;
	dp[3][3] = 4;

	for (int i=4;i<=n;++i) {
		for (int k=(i+2)/2;k<=i;++k) {
			dp[i][k] += dp[i-1][k-1];
			dp[i][k] += dp[i-2][k-1];
			dp[i][k] += dp[i-1][k-1];
			dp[i][k] += dp[i-2][k-1];
			for (int x=2;x<=(i+1)/2;++x) {
				long long c = 1 + (i+1-x > x);
				for (int q=x/2;q<=x-1;++q) {
					dp[i][k] += dp[x-1][q] * c * dp[i-x-1][k-q-1] * C[k-1][q];
					dp[i][k] += dp[x-2][q] * c * dp[i-x-1][k-q-1] * C[k-1][q];
					dp[i][k] += dp[x-2][q] * c * dp[i-x][k-q-1] * C[k-1][q];
				}
				dp[i][k] %= M;
			}
			// cout << i << " " << k << " " << dp[i][k] << endl;
		}
	}
	int ans = 0;
	for (int i=0;i<=n;++i) ans = (ans + dp[n][i]) % M;
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}