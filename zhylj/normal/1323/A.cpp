#include <bits/stdc++.h>

typedef long long ll;

const int kN = 105;

int a[kN];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n; int cnt = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			if(a[i] % 2 == 0) cnt = i;
		}
		if(cnt) printf("1\n%d\n", cnt);
		else {
			if(n == 1) printf("-1\n");
			else printf("2\n%d %d\n", 1, 2);
		}
	}
	return 0;
}