#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;

void work() {
	int a, b, c, d, n, m; ll diff;
	cin >> a >> b >> c >> d;
	if (a > (ll)b * c) {cout << "-1\n"; return;}
	if (c < d) {cout << a << '\n'; return;}
	n = c / d, diff = (ll)b * d, m = a / diff;
	assert(n >= m);
	cout << (2ll * a - diff * m) * (1ll + m) / 2 << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}