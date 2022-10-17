#include <bits/stdc++.h>

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, x, od = 0, ev = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &x);
			if(x % 2) ++od;
			else ++ev;
		}
		if(od == 0) printf("NO\n");
		else if(od % 2 == 1) printf("YES\n");
		else if(od % 2 == 0 && ev > 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}