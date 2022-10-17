#include <bits/stdc++.h>
using namespace std;
int prv1[65540][16], prv2[65540][16][16];
int trans(char x) {
	if (x >= '0' && x <= '9') return x - '0';
	return x - 'a' + 10;
}
long long read() {
	string s;
	cin >> s;
	long long x = 0;
	for (auto c : s)
		x = x * 16 + trans(c);
	return x;
}
long long f[2][16], g[2][16];
long long calc(long long n) {
	if (n < 0) return 0;
	memset(f, 0, sizeof f);
	f[1][0] = 1;
	for (int i = 15; i >= 4; --i) {
		memset(g, 0, sizeof g);
		for (int t = 0; t < 2; ++t) {
			int lim = t ? (n >> (i * 4) & 15) : 15;
			for (int x = 0; x < 16; ++x)
				for (int cur = 0; cur <= lim; ++cur)
					g[t && (cur == lim)][max(x, cur)] += f[t][x];
		}
		memcpy(f, g, sizeof f);
	}
	long long ans = 0;
	for (int t = 0; t < 2; ++t) {
		for (int x = 0; x < 16; ++x) {
			long long cur = f[t][x];
			if (!cur) continue;
			int lim = !t ? 65535 : (n & 65535);
			if (t == 1) assert(cur == 1);
			for (int y = x; y < 16; ++y)
				ans += cur * prv1[lim][y];
			for (int y = 0; y < x; ++y)
				ans += cur * prv2[lim][y][x];
		}	
	}
	return ans;
}
void solve() {
	long long l = read(), r = read();
	cout << calc(r) - calc(l - 1) << "\n";
}
int main() {
	for (int s = 0; s <= 65535; ++s) {
		if (s) {
			memcpy(prv1[s], prv1[s - 1], sizeof prv1[s]);
			memcpy(prv2[s], prv2[s - 1], sizeof prv2[s]);
		}
		int mx = 0;
		for (int x = s; x; x /= 16)
			mx = max(mx, x % 16);
		if (s >> mx & 1) ++prv1[s][mx];
		for (int x = mx + 1; x < 16; ++x)
			if (s >> x & 1) ++prv2[s][mx][x];
	}
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}