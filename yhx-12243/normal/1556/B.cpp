#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 100054;

int n;
int a[N];

void work() {
	int i, j, fst, c[2] = {0}, d[2], ans = INT_MAX, cur;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i], ++c[a[i] &= 1];
	if (abs(c[0] - c[1]) > 1) {cout << -1 << '\n'; return;}
	for (fst = 0; fst < 2; ++fst) {
		d[fst ^ 1] = n / 2, d[fst] = n - d[fst ^ 1];
		if (*c != *d) continue;
		cur = 0;
		for (j = i = 0; i < n; ++i)
			if (a[i] == fst)
				cur += abs(i - j), j += 2;
		ans = std::min(ans, cur);
	}
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}