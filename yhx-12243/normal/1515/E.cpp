#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef unsigned long long u64;
const int N = 432;

int n, mod;
int f[N][N], C[N][N];
int pw2[N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void fma(int &x, const int y, const int z) {x = (x + (u64)y * z) % mod;}

int main() {
	int i, j, k;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> mod;
	for (*pw2 = i = 1; i <= n; ++i) pw2[i] = pw2[i - 1] * 2 % mod;
	for (i = 0; i <= n; ++i) C[0][i] = 1;
	for (i = 1; i <= n; ++i)
		for (*C[i] = j = 1; j <= n; ++j) add(C[i][j] = C[i][j - 1], C[i - 1][j]);
	f[0][0] = 1;
	for (i = 0; i < n; ++i)
		for (j = 0; 2 * j <= i; ++j) if (f[i][j])
			for (k = 1; i + k + 1 <= n + 1; ++k)
				fma(f[i + k + 1][j + 1], f[i][j], (u64)pw2[k - 1] * C[i - j][k] % mod);
	cout << std::accumulate(f[n + 1], f[n + 1] + (n + 2), 0ll) % mod << '\n';
	return 0;
}