#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

typedef std::bitset <1000> bitset;

int n, B;
int m, b[1000];
bitset a;

int main() {
	int i, x;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n, B = sqrt(n);
	for (i = 0; i < n; ++i) a.set(i, i % B);
	for (; (int)a.count() >= B; ) {
		for (m = 0, i = a._Find_first(); i != 1000; i = a._Find_next(i))
			if (b[m++] = i, m == B) break;
		cout << m;
		for (i = 0; i < m; ++i) cout << ' ' << b[i], a.reset(b[i]);
		cout << endl, cin >> x;
		for (i = 0; i < m; ++i, ++x %= n) a.set(x, x % B);
	}
	return cout << '0' << endl, 0;
}