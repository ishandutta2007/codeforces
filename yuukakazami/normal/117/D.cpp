#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
using namespace std;
typedef long long int64;

int mod;

int64 doit(int64 first, int64 length, int64 delta, int64 need, int64 v) {
//	cout << first << " " << length << " " << delta << " " << need << " " << v << endl;
	if (!need)
		return 0;
	if (first > v)
		return 0;
	if (length == 1) {
		if (need > 0) {
			return (first <= v ? 2 * first : 0) % mod;
		} else {
			return 0;
		}
	}

	int64 oddLength = (length + 1) / 2;
	int64 evenLength = length - oddLength;
	if (need <= oddLength)
		return doit(first, oddLength, delta << 1, need, v);
	int64 ret = 0;
	{
		int64 len = min(oddLength, (v - first) / (delta << 1) + 1) % mod;
		int64 last = first + (len - 1) * ((delta << 1) % mod);
		last %= mod;
		ret = (first + last) % mod * len % mod;
	}
	need -= oddLength;
	if (need > 0)
		ret += doit(first + delta, evenLength, delta << 1, need, v);
	if (ret >= mod)
		ret -= mod;
	return ret;
}

int64 doit(int64 n, int64 r, int64 u) {
	return doit(1, n, 1, r, u);
}

int main() {
	int64 n;
	int m;
	cin >> n >> m >> mod;
	mod <<= 1;
	for (int i = 0; i < m; ++i) {
		int64 l, r, u, v;
		cin >> l >> r >> u >> v;
		int64 ans = (doit(n, r, v) - doit(n, r, u - 1) + mod) % mod;
		ans = (ans + mod - (doit(n, l - 1, v) - doit(n, l - 1, u - 1) + mod) % mod) % mod;
		cout << ans / 2 << endl;
	}
	return 0;
}