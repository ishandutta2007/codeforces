#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054, mod = 998244353;

struct portal {
	int x, y, s;
	friend std::istream & operator >> (std::istream &in, portal &B) {return in >> B.x >> B.y >> B.s;}
} a[N];

int n;
int f[N], F[N];

int main() {
	int i, j, X, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	X = a[n - 1].x + 1;
	for (i = 0; i < n; ++i) {
		j = std::partition_point(a, a + n, [i] (const portal &P) {return P.x <= a[i].y;}) - a;
		f[i] = (F[i] - F[j] + mod) % mod;
		f[i] = (f[i] + a[i].x - a[i].y) % mod;
		F[i + 1] = (F[i] + f[i]) % mod;
		if (a[i].s) ans = (ans + f[i]) % mod;
	}
	cout << (ans + X) % mod << '\n';
	return 0;
}