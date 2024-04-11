#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;

void work() {
	ll n, m = 0;
	cin >> n;
	if ((n % 2050)) {cout << "-1\n"; return;}
	for (n /= 2050; n; n /= 10) m += n % 10;
	cout << m << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}