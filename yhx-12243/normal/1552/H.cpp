#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

const int N = 260;

int S;
int f[N];

inline int query(int d) {
	int i, j;
	cout << '?' << ' ' << 200 / d * 200 << '\n';
	for (i = d; i <= 200; i += d)
		for (j = 1; j <= 200; ++j)
			cout << i << ' ' << j << ' ';
	return cout << endl, cin >> f[d], f[d];
}

int main() {
	int L, R, M, a;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	S = query(1);
	for (L = 0, R = 7; L < R; )
		M = (L + R + 1) / 2, query(1 << M) << M == S ? L = M : R = M - 1;
	R = L + 1, a = abs((f[1 << R] << R) - S) >> L;
	cout << '!' << ' ' << 2 * (a + S / a - 2) << '\n';
	return 0;
}