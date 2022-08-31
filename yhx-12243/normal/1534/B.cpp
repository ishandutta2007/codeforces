#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 400054;

int n;
int a[N];

void work() {
	int i, w; long long ans = 0;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	a[n + 1] = 0;
	for (i = 1; i <= n; ++i)
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			w = std::max(a[i - 1], a[i + 1]),
			ans += a[i] - w, a[i] = w;
	for (i = 0; i <= n; ++i) ans += abs(a[i + 1] - a[i]);
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}