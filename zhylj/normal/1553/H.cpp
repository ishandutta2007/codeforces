#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;

const int K = 19, N = (1 << K) + 5, Inf = 0x3f3f3f3f;

int f[N], minv[N], maxv[N];

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	memset(f, 0x3f, sizeof(f));
	memset(minv, 0x3f, sizeof(minv));
	memset(maxv, ~0x3f, sizeof(maxv));
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		minv[x] = maxv[x] = 0;
	}
	for(int i = 0; i < k; ++i) {
		for(int x = 0; x < 1 << k; ++x) if(~(x >> i) & 1) {
			int y = x + (1 << i), tf = std::min(f[x], f[y]), tmx, tmy;
			f[x] = std::min(tf, minv[y] - maxv[x] + (1 << i));
			f[y] = std::min(tf, minv[x] - maxv[y] + (1 << i));
			tmx = std::min(minv[x], minv[y] + (1 << i));
			tmy = std::min(minv[x] + (1 << i), minv[y]);
			minv[x] = tmx; minv[y] = tmy;
			tmx = std::max(maxv[x], maxv[y] + (1 << i));
			tmy = std::max(maxv[x] + (1 << i), maxv[y]);
			maxv[x] = tmx; maxv[y] = tmy;
		}
	}
	for(int i = 0; i < 1 << k; ++i)
		printf("%d ", f[i]);
	printf("\n");
	return 0;
}