#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], b[N];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	bool f = true;
	for (int i = 1; i <= n; ++i) {
		f &= (a[i] == b[i] || a[i] == b[i] - 1);
	}
	puts(f ? "YES" : "NO");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}