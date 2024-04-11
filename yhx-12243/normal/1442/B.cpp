#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054, mod = 998244353;

int n, m;
int a[N], ia[N], b[N];
int L[N], R[N];
bool deletable[N];

void work() {
	int i, l, r, x, ans = 1;
	cin >> n >> m;
	memset(deletable + 1, true, n), deletable[0] = deletable[n + 1] = false;
	for (i = 1; i <= n; ++i) cin >> a[i], ia[a[i]] = i;
	for (i = 1; i <= m; ++i) cin >> b[i], b[i] = ia[b[i]], deletable[b[i]] = false;
	for (i = 1; i <= n; ++i) L[i] = i - 1, R[i] = i + 1;
	R[0] = 1, L[n + 1] = n;
	for (i = 1; i <= m; ++i) {
		x = b[i], l = L[x], r = R[x];
		ans = ((ll)deletable[l] + deletable[r]) * ans % mod;
		if (!ans) break;
		L[r] = l, R[l] = r;
	}
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}