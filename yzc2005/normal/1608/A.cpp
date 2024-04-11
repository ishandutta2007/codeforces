#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = n; i < 2 * n; ++i) {
		printf("%d ", i);
	}
	puts("");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}