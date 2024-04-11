#include <bits/stdc++.h>
#define popc __builtin_popcount
#define popc64 __builtin_popcountll
#define ctz64 __builtin_ctzll
using std::cin;
using std::cout;

typedef unsigned long long u64;
const int N = 200054;

int n, m, p;
u64 a[N], ans;
char s[70];
std::mt19937 gen;
int w[32768];

inline void check() {
	
}

inline void work(u64 x) {
	static int pos[70];
	int i, j, k, t, c = 0;
	for (; x; x &= x - 1) pos[c++] = ctz64(x);
	memset(w, 0, sizeof w);
	for (i = 0; i < n; ++i) {
		for (t = j = 0; j < c; ++j)
			t |= (a[i] >> pos[j] & 1) << j;
		++w[t];
	}
	for (i = 0; i < c; ++i)
		for (j = 0; j < 1 << c; j += 2 << i)
			for (k = j; k < j + (1 << i); ++k)
				w[k] += w[k + (1 << i)];
	for (i = 0; i < 1 << c; ++i)
		if (2 * w[i] >= n && popc(i) > popc64(ans)) {
			ans = 0;
			for (j = 0; j < c; ++j)
				ans |= u64(i >> j & 1) << pos[j];
		}
}

int main() {
	int i, x;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	gen.seed(std::chrono::steady_clock::now().time_since_epoch().count());
	cin >> n >> m >> p;
	for (i = 0; i < n; ++i) cin >> s, a[i] = strtoll(s, NULL, 2);
	for (i = 0; i < 25; ++i) x = gen() % n, work(a[x]);
	for (i = m - 1; i >= 0; --i) cout << (ans >> i & 1);
	cout << '\n';
	return 0;
}