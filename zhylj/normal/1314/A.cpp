#include <bits/stdc++.h>

typedef long long ll;

const int kN = 2e5 + 5;
const int kInf = 0x3f3f3f3f;

ll a[kN], t[kN]; int idx[kN], n;

bool cmp(const int &x, const int &y) {
	return a[x] != a[y] ? a[x] < a[y] : t[x] > t[y];
}

std::priority_queue<ll> que;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
	for(int i = 1; i <= n; ++i) scanf("%lld", t + i), idx[i] = i;
	idx[n + 1] = n + 1; a[n + 1] = kInf;
	std::sort(idx + 1, idx + n + 1, cmp);
	ll tot = 0, ans = 0;
	for(int i = 1; i <= n; ++i) {
		int v = idx[i];
		que.push(t[v]); tot += t[v];
		//printf("%lld %lld\n", t[idx[i]], a[idx[i]]);
		for(int j = a[idx[i]]; j < a[idx[i + 1]] && !que.empty(); ++j) {
			ll top = que.top(); que.pop();
			//printf("%d\n", top);
			tot -= top;
			ans += tot;
		}
	}
	printf("%lld", ans);
	return 0;
}