#include <bits/stdc++.h>
using namespace std;

int n, p, ans, fac[250005];

int main() {
	cin >> n >> p;
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % p;
	for(int len = 1; len <= n; ++len) ans += 1LL * fac[len] * fac[n - len + 1] % p * (n - len + 1) % p, ans %= p;
	cout << ans;
	return 0;
}