#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if (count(a + 1, a + n + 1, a[1]) == n) {
		puts("YES");
		return;
	}
	if (a[1] >= 2) {
		puts("YES");
	} else {
		if (a[1] == 0) {
			puts(count(a + 1, a + n + 1, 1) ? "NO" : "YES");	
		} else {
			for (int i = 1; i < n; ++i) {
				if (a[i + 1] - a[i] == 1) {
					puts("NO");
					return;
				}
			}
			puts("YES");
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}