#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;
const ll INF64 = 0x3f3f3f3f3f3f3f3fll;

int n, z01, z10;
ll I, w0[N], w1[N];
char s[N];

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

int main() {
	int i, j, c0, c1, c = 0; ll ans = INF64;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> s >> z01 >> z10, n = strlen(s);
	if (z01 > z10) {
		std::swap(z01, z10);
		for (i = 0; i < n; ++i) if (s[i] != '?') s[i] ^= 1;
	}
	c0 = c1 = 0;
	for (i = 0; i < n; ++i)
		if (s[i] == '0') I += (ll)c1 * z10, ++c0;
		else if (s[i] == '1') I += (ll)c0 * z01, ++c1;
		else w0[i] += (ll)c1 * z10, w1[i] += (ll)c0 * z01, ++c;
	c0 = c1 = 0;
	for (i = n - 1; i >= 0; --i)
		if (s[i] == '0') ++c0;
		else if (s[i] == '1') ++c1;
		else w0[i] += (ll)c1 * z01, w1[i] += (ll)c0 * z10;
	for (i = 1; i < n; ++i) w0[i] += w0[i - 1];
	for (i = n - 1; i >= 0; --i) w1[i] += w1[i + 1];
	down(ans, w0[n - 1]), down(ans, w1[0]);
	for (j = i = 0; i + 1 < n; ++i)
		j += s[i] == '?',
		down(ans, w0[i] + w1[i + 1] + (ll)z01 * j * (c - j));
	cout << I + ans << '\n';
	return 0;
}