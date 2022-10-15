#include <bits/stdc++.h>

const int kMaxN = 5e3 + 5;
const int kInf = 0x3f3f3f3f;

int a[kMaxN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m, k, ans = 0;
		scanf("%d%d%d", &n, &m, &k);
		if(k >= m) k = m - 1;
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);
		for(int i = 0; i <= k; ++i) {
			int l = i + 1, r = n - (k - i), w = m - k - 1, tmp = kInf;
			//printf("l = %d, r = %d, w = %d\n", l, r, w);
			for(int j = l; j <= l + w; ++j) {
				int nr = r - w + j - l;
				//printf("(%d, %d) %d %d\n", j, nr, a[j], a[nr]);
				tmp = std::min(tmp, std::max(a[nr], a[j]));
			}
			ans = std::max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}