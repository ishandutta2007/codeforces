#include <bits/stdc++.h>

const int kN = 1e5 + 5;;

bool vis[kN], mrd[kN]; int g[kN];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) vis[i] = mrd[i] = false;
		for(int i = 1; i <= n; ++i) {
			int k; scanf("%d", &k);
			for(int j = 1; j <= k; ++j) scanf("%d", g + j);
			for(int j = 1; j <= k; ++j)
				if(!vis[g[j]]) {
					mrd[i] = vis[g[j]] = true;
					break;
				}
		}
		int d1 = 0, d2 = 0;
		for(int i = 1; i <= n; ++i) {
			if(!vis[i]) d1 = i;
			if(!mrd[i]) d2 = i;
		}
		if(d1 && d2) {
			printf("IMPROVE\n%d %d\n", d2, d1);
		} else printf("OPTIMAL\n");
	}
	return 0;
}