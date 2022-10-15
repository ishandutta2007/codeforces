#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 205;

ll t[kMaxN], l[kMaxN], h[kMaxN];

int main() {
	int q;
	scanf("%d", &q);
	while(q--) {
		int n; ll m;
		scanf("%d%lld", &n, &m);
		ll L = m, R = m;
		for(int i = 1; i <= n; ++i) scanf("%lld%lld%lld", t + i, l + i, h + i);
		bool flag = true;
		for(int i = 1; i <= n; ++i) {
			L -= t[i] - t[i - 1]; R += t[i] - t[i - 1];
			//printf("Cur: %d, L: %lld, R: %lld\n", i, L, R);
			if(std::min(h[i], R) - std::max(l[i], L) >= 0) {
				L = std::max(l[i], L);
				R = std::min(h[i], R);
			} else {
				flag = false;
				break;
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	}
	return 0;
}