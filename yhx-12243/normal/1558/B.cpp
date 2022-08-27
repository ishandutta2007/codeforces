#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef unsigned long long u64;
const int N = 4000054;

int n, mod;
int f[N];

u64 PowerMod(u64 a, int n, u64 c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void fma(int &x, const int y, const int z) {x = (x + (u64)y * z) % mod;}

namespace BIT {
	int x[N];

	int sum(int h) {int s = 0; for (; h > 0; h &= h - 1) ::add(s, x[h]); return s;}
	void add(int h, int v) {for (; h <= n; h |= h - 1, ++h) ::add(x[h], v);}
}

int main() {
	int i, j, ij, sq, sum = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> mod, f[1] = 1;
	for (i = 1; i <= n; ++i) {
		add(f[i], sum), add(f[i], BIT::sum(i));
		for (j = 2, ij = 2 * i; ij <= n; ++j, ij += i) BIT::add(ij, f[i]), BIT::add(ij + j, mod - f[i]);
		add(sum, f[i]);
	}
	cout << f[n] << '\n';
	return 0;
}