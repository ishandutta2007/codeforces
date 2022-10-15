#include <bits/stdc++.h>

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d%d", &n, &k);
		if(n % 2 == k % 2) {
			int ans = 0;
			for(int i = 1; i <= k && ans <= n; ++i)
				ans += (i - 1) * 2 + 1;
			if(ans <= n) printf("YES\n");
			else printf("NO\n");
		} else printf("NO\n");
	}
	return 0;
}