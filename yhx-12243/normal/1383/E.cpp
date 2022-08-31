#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 1000054, mod = 1000000007;

int n, m = 0;
int a[N], f[N];
char s[N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}

namespace pb_ds {
	int f[N], global = 0;

	inline int get(int i) {return f[i] + global >= mod ? f[i] + global - mod : f[i] + global;}
	inline void add(int x) {::add(global, x);}
	inline void reset(int i) {for (; i >= 0; --i) f[i] = mod - global;}
}

int main() {
	int i, j, cnt; ll cur, ans = 1;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> s, n = strlen(s);
	for (cnt = i = 0; i < n; ++i)
		if (s[i] & 1) a[m++] = cnt, cnt = 0;
		else ++cnt;
	a[m++] = cnt;
	if (!--m) return cout << n << '\n', 0;
	pb_ds::add(1);
	for (i = 1; i < m; ++i) {
		for (cur = j = 0; j <= a[i]; ++j) cur += pb_ds::get(j);
		f[i] = cur % mod, pb_ds::reset(a[i]), pb_ds::add(f[i]), ans += f[i];
	}
	cout << ans % mod * (*a + 1) % mod * (a[m] + 1) % mod << '\n';
	return 0;
}