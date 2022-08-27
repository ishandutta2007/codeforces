#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

typedef unsigned long long u64;
const int N = 27;

int n, q;
u64 a[N][N];

int main() {
	int i, j; u64 x, dr, dc;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 2; i <= n; i += 2)
		for (j = 1; j <= n; ++j)
			a[i][j] = 1ull << (i + j - 3);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			cout << a[i][j] << (j == n ? '\n' : ' ');
	cout.flush();
	for (cin >> q; q; --q) {
		cin >> x;
		for (i = j = 1; x && i < n && j < n; ) {
			cout << i << ' ' << j << '\n';
			dr = a[i + 1][j], dc = a[i][j + 1];
			if (dr) assert(!dc), x & dr ? ++i : ++j;
			else assert(dc), x & dc ? ++j : ++i;
			x -= a[i][j];
		}
		for (; i < n; ++i) cout << i << ' ' << j << '\n';
		for (; j < n; ++j) cout << i << ' ' << j << '\n';
		cout << n << ' ' << n << endl;
	}
	return 0;
}