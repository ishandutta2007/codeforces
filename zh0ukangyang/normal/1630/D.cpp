#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;
int n, m, g, a[N];
ll dp[2], nw[2];
void Main () {
	cin >> n >> m;
	L(i, 1, n) {
		cin >> a[i];
	}
	g = 0;
	L(i, 1, m) {
		int x;
		cin >> x;
		g = __gcd(x, g);
	}
//	cout << "g = " << g  << '\n';
	ll ns = -1e18;
	L(o, 0, 1) {
		ll ret = 0;
		L(i, 1, g) {
			dp[0] = 0, dp[1] = -1e18;
			for (int j = i; j <= n; j += g) {
				L(x, 0, 1) 
					nw[x] = max(dp[x] + a[j], dp[x ^ 1] - a[j]);
				L(x, 0, 1) 
					dp[x] = nw[x];
			}
//			cout << "DP = " << dp[o] << '\n';
			ret += dp[o];
		}
		ns = max(ns, ret);
	}
	cout << ns << '\n';
} 
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}