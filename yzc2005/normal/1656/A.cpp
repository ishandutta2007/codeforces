#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int i = max_element(a + 1, a + n + 1) - a;
	int j = min_element(a + 1, a + n + 1) - a;
	printf("%d %d\n", i, j);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}