#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	if (k > (n + 1) / 2) {
		puts("-1");
		return;
	} else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				bool f = (i == j && (i % 2 == 1) && ((i + 1) / 2 <= k));
				putchar(f ? 'R' : '.');
			}
			puts("");
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}