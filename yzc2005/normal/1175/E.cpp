#include <bits/stdc++.h>
using namespace std;

const int N = 200005, M = 500005, K = 20;
int n, m, q, mx[M], l, r, f[M][K];

inline void ckmax(int &a, int b) {
	if(a < b) a = b;
}

int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> l >> r, ++l, ++r;
		ckmax(mx[l], r);
		ckmax(m, r);
	}
	for(int i = 1; i <= m; ++i) ckmax(mx[i], mx[i - 1]), f[i][0] = mx[i];
	for(int k = 1; k <= 19; ++k)
		for(int i = 1; i <= m; ++i)
			f[i][k] = f[f[i][k - 1]][k - 1];
	while(q--) {
		cin >> l >> r, ++l, ++r;
		int ans = 0, u = l;
		for(int k = 19; ~k; --k) {
			if(f[u][k] >= r) continue;
			u = f[u][k], ans |= 1 << k;
		}
		if(mx[u] < r) puts("-1");
		else printf("%d\n", ans + 1);
	}
	return 0;
}