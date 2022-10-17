#include <bits/stdc++.h>
using namespace std;

int t, n, r, a[100005];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d", &n, &r);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1); n = unique(a + 1, a + n + 1) - a - 1;
		reverse(a + 1, a + n + 1); a[n + 1] = 0;
		for(int i = 1; i <= n; ++i) 
			if(a[i + 1] <= r * i) {
				printf("%d\n", i);
				break;
			}
	}
	return 0;
}