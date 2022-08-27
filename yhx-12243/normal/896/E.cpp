#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054;

int n, q;
int a[N];

int main() {
	int i, op, l, r, x, s = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> q;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (; q; --q)
		if (cin >> op >> l >> r >> x, op == 1) {
			for (; l <= r; ++l) if (a[l] > x) a[l] -= x;
		} else {
			for (s = 0; l <= r; ++l) s += a[l] == x;
			cout << s << '\n';
		}
	return 0;
}