#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; 
int n, m, a[N], b[N], c[N];
bool v[N];
void solve() {
	scanf("%d%d", &n, &m);
	memset(v + 1, false, n);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &a[i], &b[i], &c[i]), v[b[i]] = true;
	for (int i = 1; i <= n; ++i) {
		if (!v[i]) {
			for (int j = 1; j <= n; ++j)
				if (i != j) printf("%d %d\n", j, i);
			return;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}