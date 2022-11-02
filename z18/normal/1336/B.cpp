#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
using namespace std;

typedef long long ll;
const int maxn = 1e5;
int T, n, m, k, a[maxn + 3], b[maxn + 3], c[maxn + 3];

ll sqr(int x) {
	return 1ll * x * x;
}

ll Solve(int a[], int n, int b[], int m, int c[], int k) {
	ll ans = 3e18;
	rep(i, 1, n) {
		int x = lower_bound(b + 1, b + m + 1, a[i]) - b;
		int y = upper_bound(c + 1, c + k + 1, a[i]) - (c + 1);
		if (x <= m && y >= 1) {
			int A = a[i], B = b[x], C = c[y];
			ans = min(ans, sqr(A - B) + sqr(B - C) + sqr(C - A));
		}
	}
	return ans;
}

ll solve(int a[], int n, int b[], int m, int c[], int k) {
	return min(Solve(a, n, b, m, c, k), Solve(a, n, c, k, b, m));
}

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d %d %d", &n, &m, &k);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, m) scanf("%d", &b[i]);
		rep(i, 1, k) scanf("%d", &c[i]);
		sort(a + 1, a + n + 1), n = unique(a + 1, a + n + 1) - (a + 1);
		sort(b + 1, b + m + 1), m = unique(b + 1, b + m + 1) - (b + 1);
		sort(c + 1, c + k + 1), k = unique(c + 1, c + k + 1) - (c + 1);
		printf("%lld\n", min(min(solve(a, n, b, m, c, k), solve(b, m, c, k, a, n)), solve(c, k, a, n, b, m)));
	}
	return 0;
}