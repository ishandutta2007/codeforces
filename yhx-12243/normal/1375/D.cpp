#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 300054;

int n, m, J = 0;
int a[N];
int x[N];

int mex() {
	static int used[N];
	int i, r = 0; ++J;
	for (i = 1; i <= n; ++i) used[ a[i] ] = J;
	for (; used[r] == J; ++r);
	return r;
}

bool incr() {
	int i;
	for (i = 1; i < n; ++i)
		if (a[i] > a[i + 1]) return false;
	return true;
}

void work() {
	int i, j, k;
	cin >> n, m = 0;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (; !incr(); ) {
		k = mex();
		if (k) a[k] = k, x[m++] = k;
		else {
			for (i = 1; i <= n; ++i) if (a[i] != i) k = i;
			a[k] = 0, x[m++] = k;
		}
	}
	cout << m << '\n';
	for (i = 0; i < m; ++i) cout << x[i] << (i == m - 1 ? '\n' : ' ');
	if (!m) cout.put(10);
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}