#include <bits/stdc++.h>

const int kMaxN = 2e5 + 5;
const int kInf = 0x3f3f3f3f;

int a[kMaxN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, minn = kInf;
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; ++i) {
			scanf("%d", a + i);
		}
		std::sort(a + 1, a + 2 * n + 1);
		for(int i = 1; i <= 2 * n; ++i) {
			int md = a[i <= n ? n + 1 : n];
			minn = std::min(minn, abs(md - a[i]));
		}
		printf("%d\n", minn);
	}
	return 0;
}