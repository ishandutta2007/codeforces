#include <bits/stdc++.h>

const int kMaxN = 114;

int a[kMaxN], s, cnt;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n; s = 0, cnt = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			if(a[i] == 0) a[i] = 1, ++cnt;
			s += a[i];
		}
		if(!s) printf("%d\n", cnt + 1);
		else printf("%d\n", cnt);
	}
	return 0;
}