#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 20005;
int n, a[N];
bool f[M];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int sum = accumulate(a + 1, a + n + 1, 0);
	if (!f[sum]) {
		int pos = 1;
		while (a[pos] % 2 == 0)
			++pos;
		printf("%d\n", n - 1);
		for (int i = 1; i <= n; ++i)
			if (i != pos) printf("%d ", i);
		puts("");
	} else {
		printf("%d\n", n);
		for (int i = 1; i <= n; ++i)
			printf("%d ", i);
		puts("");
	}
}
int main() {
	for (int i = 2; i < M; ++i)
		for (int j = i + i; j < M; j += i)
			f[j] = true;
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}