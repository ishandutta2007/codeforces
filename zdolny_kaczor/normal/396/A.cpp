# include <bits/stdc++.h>
using namespace std;
map <int, int> c;
#define mod MOD
const int MOD = 1e9 + 7;
const int MN = 500;
long long pow(long long a, int b) {
	if (b == 0)
		return 1;
	if (b % 2)
		return pow(a, b - 1) * a % MOD;
	return pow(a * a % MOD, b / 2);
}
long long inv(long long a) {
	return pow(a, mod - 2);
}
long long binom(int a, int b) {
	long long res = 1;
	for (int i = 0; i < b; ++i) {
		res = res * (a - i) % mod * inv(i + 1) % mod;
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		for (int p = 2; p * p <= x; ++p) {
			while (x % p == 0) {
				c[p]++;
				x /= p;
			}
		}
		if (x > 1)
			c[x]++;
	}
	long long res = 1;
	for (auto x : c) {
		res = res * binom(x.second + n - 1, n - 1) % MOD;
	}
	printf("%lld\n", res);
}