#include <bits/stdc++.h>

const int kMaxN = 1e5 + 5;

int a[kMaxN], f[kMaxN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, x, ma = 0; bool flag = false;
		scanf("%d%d", &n, &x);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", a + i), ma = std::max(ma, a[i]);
			if(x == a[i]) flag = true;
		}
		if(!flag)
			printf("%d\n", std::max((x - 1) / ma + 1, 2));
		else printf("%d\n", 1);
	}
	return 0;
}