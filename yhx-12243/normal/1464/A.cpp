#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int n, m;
int p[N], q[N];
bool used[N];

void work() {
	int i, u, v, x, ans = 0;
	cin >> n >> m;
	memset(p, 0, (n + 1) << 2), memset(used, false, n + 1);
	memset(q, 0, (n + 1) << 2);
	for (i = 0; i < m; ++i) cin >> u >> v, p[u] = v, ans += u != v, q[v] = u;
	for (i = 1; i <= n; ++i) if (!q[i]) for (x = i; x; x = p[x]) used[x] = true;
	for (i = 1; i <= n; ++i) if (p[i] && p[i] != i && !used[i]) {
		for (x = i; x && !used[x]; x = p[x]) used[x] = true;
		if (x) ++ans;
	}
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}