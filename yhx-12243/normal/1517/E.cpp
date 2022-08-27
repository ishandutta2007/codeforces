#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054, mod = 998244353;

ll s = 0;
int n;
int a[N];
ll r[N];
ll A[N], B[N];

int solve(int first, int last) {
	int i, j, nA = 0, nB = 0; ll lim = s, ans = 0;
	if (first) lim -= a[1];
	if (last) lim -= a[n];
	r[0] = r[1] = 0;
	for (i = 2; i < n; ++i) r[i] = r[i - 2] + a[i];
	for (i = 0; i < n; i += 2) if ((first == 1 || i != 0) && (last == 0 || i != n - 1)) A[nA++] = r[i];
	for (i = 1; i < n; i += 2) if ((first == 1 || i != 0) && (last == 0 || i != n - 1)) B[nB++] = r[i];
	for (i = 0, j = nB; i < nA; ++i) {
		for (; j > 0 && A[i] + B[j - 1] > lim; --j);
		ans += j;
	}
	return ans % mod;
}

void work() {
	int i, j; ll t = 0, ans = 0;
	cin >> n, s = 0;
	for (i = 1; i <= n; ++i) cin >> a[i], s += a[i];
	s = (s - 1) / 2;
	if (n == 1) ans = 1;
	else {
		for (i = 0; i < 2; ++i) for (j = 0; j < 2; ++j) ans += solve(i, j);
		for (i = n; i; --i) ans += t <= s, t += a[i];
	}
	cout << int(ans % mod) << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}