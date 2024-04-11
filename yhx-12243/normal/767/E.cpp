#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 100054;

int n, R;
int v[N], coef[N], integral[N];
std::priority_queue <pr> pq;

int main() {
	int i, j, D; ll ans = 0;
	scanf("%d%d", &n, &R);
	for (i = 0; i < n; ++i) scanf("%d", v + i), integral[i] = v[i] / 100, v[i] -= integral[i] * 100;
	for (i = 0; i < n; ++i) scanf("%d", coef + i);
	for (i = 0; i < n; ++i) if (v[i]) {
		pq.emplace((v[i] - 100) * coef[i], i), R -= v[i];
		if (R < 0) std::tie(D, j) = pq.top(), pq.pop(), ans -= D, ++integral[j], v[j] = 0, R += 100;
	}
	printf("%lld\n", ans);
	for (i = 0; i < n; ++i) printf("%d %d\n", integral[i], v[i]);
	return 0;
}