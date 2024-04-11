#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define mem(a, x) memset(a, x, sizeof a)
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)

const int K = 10005, N = 55, mod = 1e9 + 7;
int k, dp[K][N], inv[N], ans = 1;
ll n;

inline void addmod(int &a, int b) {a = (a + b) % mod;}
inline void mulmod(int &a, int b) {a = 1ll * a * b % mod;}
inline int add(int a, int b) {return (a + b) % mod;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}

inline void solve(int p, int c) {
	mem(dp, 0); dp[0][c] = 1;
	fu(i, 1, k) fd(j, c, 0) dp[i][j] = add(dp[i][j + 1], mul(dp[i - 1][j], inv[j + 1]));
	int cur = 0, expo = 1;
	fu(i, 0, c) addmod(cur, mul(dp[k][i], expo)), mulmod(expo, p);
	mulmod(ans, cur);
}

int main() {
	cin >> n >> k;
	inv[1] = 1;
	fu(i, 2, N - 1) inv[i] = mul(inv[mod % i], mod - mod / i);
	fu(p, 2, sqrt(n)) {
		int c = 0;
		while(n % p == 0) n /= p, ++c;
		if(c) solve(p, c);
	} 
	if(n > 1) solve(n % mod, 1);
	cout << ans;
}