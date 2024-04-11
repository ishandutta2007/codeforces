#include <bits/stdc++.h>

const int kMaxN = 1e5 + 5;
const int kInf = 0x3f3f3f3f;

int a[kMaxN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m = 0, maxn = -kInf, minn = kInf;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
		}
		for(int i = 1; i <= n; ++i) {
			if(a[i] != -1 && (a[i - 1] == -1 || a[i + 1] == -1))
				maxn = std::max(maxn, a[i]), minn = std::min(minn, a[i]);
		}
		int k = (maxn + minn) / 2;
		for(int i = 1; i <= n; ++i)
			if(a[i] == -1) a[i] = k;
		for(int i = 1; i < n; ++i) {
			m = std::max(m, abs(a[i] - a[i + 1]));
		}
		printf("%d %d\n", m, k);
	}
	return 0;
}