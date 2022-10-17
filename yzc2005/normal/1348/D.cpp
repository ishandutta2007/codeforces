#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[40];

int main() {
	for(cin >> t; t; --t) {
		cin >> n;
		cout << (m = __lg(n)) << '\n';
		for(int i = 0; i < m; ++i) n -= (a[i] = 1 << i);
		a[m] = n;
		sort(a, a + m + 1);
		for(int i = 1; i <= m; ++i) cout << a[i] - a[i - 1] << (i == m ? '\n' : ' ');
	}
}