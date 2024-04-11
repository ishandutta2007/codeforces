#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int T, n, a[maxn + 3], b[maxn + 3];

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
		for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
	}
	return 0;
}