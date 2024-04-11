#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 36, mod = 998244353;

int n, m, seg;
int a[N], b[N], all[N * N], itv[N * N];
int inv[N], def_int[N * N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}

struct poly : std::array <int, N> {
	inline poly & operator += (const int x) {return add(front(), x), *this;}
	inline poly & operator -= (const poly &B) {for (int i = 0; i < N; ++i) sub(at(i), B[i]); return *this;}	
	inline void set(int constant = 0) {fill(0), front() = constant;}
	inline void indef_integrate(int constant = 0) {
		for (int i = N - 1; i; --i) at(i) = (ll)at(i - 1) * inv[i] % mod;
		front() = constant;
	}
	inline int operator () (const int x) {
		int ret = 0;
		for (int i = N - 1; i >= 0; --i) ret = ((ll)ret * x + at(i)) % mod;
		return ret;
	}
} f[N * N];

void init() {
	int i;
	for (inv[1] = 1, i = 2; i < N; ++i) inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
}

int main() {
	int i, j, k; double x; init();
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> x, a[i] = min(int(x * 1000000 + .25), 1000000 * (i + 1));
	for (i = n - 1; i; --i) down(a[i - 1], a[i]);
	for (i = 0; i < n; ++i) b[i] = a[i] % 1000000;
	b[n] = 0, std::sort(b, b + (n + 1)), m = std::unique(b, b + (n + 1)) - b;
	b[m] = 1000000, seg = n * m, all[seg] = n * 1000000;
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j)
		all[i * m + j] = i * 1000000 + b[j], itv[i * m + j] = (b[j + 1] - b[j]) * 616898040ll % mod;
	for (j = i = 0; i < n; ++i) {
		for (; j < seg && all[j] < a[i]; ++j);
		assert(a[i] == all[j]), b[i] = j;
	}
	for (i = *b - 1; i >= 0; --i) f[i].set(1);
	for (i = 0; i < n; ++i)
		for (j = b[i] - 1; j >= 0; --j) {
			for (k = j - 1; k >= j - m && k >= 0; --k) f[j] += def_int[k];
			if (j >= m) f[j] -= f[j - m];
			f[j].indef_integrate(), def_int[j] = f[j](itv[j]);
		}
	cout << int(std::accumulate(def_int, def_int + seg, 0ll) % mod) << '\n';
	return 0;
}