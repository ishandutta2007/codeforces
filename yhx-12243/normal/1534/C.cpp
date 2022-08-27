#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 400054;

int n;
int a[N], b[N];
int p[N];
bool used[N];

void work() {
	int i, j, u, v, ans = 1;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i], used[i] = false;
	for (i = 1; i <= n; ++i) cin >> b[i], p[a[i]] = b[i];
	for (i = 1; i <= n; ++i) if (!used[i]) {
		ans = ans * 2 % 1000000007;
		for (j = i; !used[j]; j = p[j]) used[j] = true;
	}
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}