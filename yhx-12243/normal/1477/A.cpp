#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054;

int n;
ll x[N];

void work() {
	int i; ll X, d = 0;
	cin >> n >> X;
	for (i = 0; i < n; ++i) cin >> x[i];
	for (i = 1; i < n; ++i) d = std::__gcd(d, x[i] - x[0]);
	d = llabs(d);
	cout << ((d ? (X - x[0]) % d : X != x[0]) ? "NO\n" : "YES\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}