#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 5e5;
int T, n, m;
ull a[maxn + 3], b[maxn + 3], num[maxn + 3], cur;
pair<ull, int> P[maxn + 3];

ull get() {
	cur ^= cur >> 12;
	cur ^= cur << 25;
	cur ^= cur >> 27;
	return cur;
}

ull gcd(ull a, ull b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	srand(time(0) ^ (ull) (new char));
	for (int i = 0; i < 64; i++) {
		cur |= ((ull) (rand() & 1)) << i;
	}
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%I64u", &num[i]);
		}
		for (int i = 1; i <= n; i++) {
			a[i] = get(), b[i] = 0;
		}
		for (int i = 1, u, v; i <= m; i++) {
			scanf("%d %d", &u, &v);
			b[v] ^= a[u];
		}
		for (int i = 1; i <= n; i++) {
			P[i] = make_pair(b[i], i);
		}
		sort(P + 1, P + n + 1);
		ull ans = 0;
		for (int i = 1, l = 1; i <= n; i += l, l = 1) {
			ull sum = num[P[i].second];
			while (i + l <= n && P[i + l].first == P[i].first) sum += num[P[i + l].second], l++;
			if (P[i].first != 0) ans = gcd(ans, sum);
		}
		printf("%I64u\n", ans);
	}
	return 0;
}