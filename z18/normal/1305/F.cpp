#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;
int n, m;
ll p[maxn + 3], a[maxn + 3], ans;

ll solve(ll k) {
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		ll x = a[i] % k;
		res += a[i] <= k ? k - a[i] : min(x, k - x);
		if (res >= ans) return ans;
	}
	return res;
}

void fen(ll x) {
	m = 0;
	if (x <= 1) return;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			p[++m] = i;
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) p[++m] = x;
}

int main() {
	srand(time(0));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	random_shuffle(a + 1, a + n + 1);
	ans = n;
	ans = solve(2);
	for (int k = 1; k <= min(n, 20); k++) {
		int x = rand() % n + 1;
		for (int t = -1; t <= 1; t++) {
			fen(a[x] + t);
			for (int i = 1; i <= m; i++) ans = min(ans, solve(p[i]));
		}
	}
	printf("%lld\n", ans);
	return 0;
}