#include <bits/stdc++.h>
using namespace std;

int t, n, k, a[105];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int m = unique(a + 1, a + n + 1) - a - 1;
		if(m > k) {
			puts("-1");
			continue;
		}
		printf("%d\n", n * k);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= k; ++j)
				printf("%d%c", j > m ? 1 : a[j], (i == n && j == m) ? '\n' : ' ');
	}
}