#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn = 5000;
int n, a[maxn + 3], oh[maxn + 3], dep[maxn + 3];
multiset<int> S, T;
 
int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x), a[max(x, 1)]++;
	}
	for (int i = 1; i <= maxn; i++) {
		int t = i;
		for (int j = 2; j <= t; j++) {
			while (t % j == 0) {
				t /= j;
				S.insert(j);
			}
		}
		multiset<int>::iterator sit = S.end(), tit = T.end();
		int cnt = 0;
		while (sit != S.begin() && tit != T.begin()) {
			if (*(--sit) != *(--tit)) break;
			cnt++;
		}
		oh[i] = cnt, dep[i] = S.size();
		t = i;
		for (int j = 2; j <= t; j++) {
			while (t % j == 0) {
				t /= j;
				T.insert(j);
			}
		}
	}
	ll ans = 1e18;
	for (int i = 1; i <= maxn; i++) {
		int cur = 114514;
		ll res = 0;
		for (int j = i - 1; j; j--) {
			cur = min(cur, oh[j + 1]);
			res += 1ll * (dep[i] + dep[j] - cur * 2) * a[j];
		}
		cur = 114514;
		for (int j = i + 1; j <= maxn; j++) {
			cur = min(cur, oh[j]);
			res += 1ll * (dep[i] + dep[j] - cur * 2) * a[j];
		}
		ans = min(ans, res);
	}
	for (int i = 1; i < maxn; i++) {
		int x = oh[i + 1];
		int cur = x;
		ll res = 0;
		for (int j = i; j; j--) {
			cur = min(cur, oh[j + 1]);
			res += 1ll * (dep[j] + x - cur * 2) * a[j];
		}
		cur = x;
		for (int j = i + 1; j <= maxn; j++) {
			cur = min(cur, oh[j]);
			res += 1ll * (dep[j] + x - cur * 2) * a[j];
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}