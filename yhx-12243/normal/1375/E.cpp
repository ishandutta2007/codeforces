#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 1054;

int n, m = 0;
int a[N], ia[N];
int u[N*N], v[N*N];
pr b[N];

int main() {
	int i, x, p, q;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> x, b[i] = pr(x, i);
	std::sort(b + 1, b + (n + 1));
	for (i = 1; i <= n; ++i) a[b[i].second] = i, ia[i] = b[i].second;
	for (; ; ) {
		for (i = 1; i < n; ++i) if (ia[i] > ia[i + 1]) break;
		if (i == n) break;
		p = ia[i + 1], q = ia[i];
		u[m] = p, v[m++] = q;
		a[p] = i, a[q] = i + 1;
		ia[i] = p, ia[i + 1] = q;
	}
	cout << m << '\n';
	for (i = 0; i < m; ++i) cout << u[i] << ' ' << v[i] << '\n';
	return 0;
}