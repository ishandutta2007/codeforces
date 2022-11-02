#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N], T;

bool check_(int x) {
	int tot = (n + x) - (n + x)/4;

	if (tot <= x) {
		return 1;
	}

	int A = 100*x + a[n - (tot - x) + 1];
	int B = b[max(1, n - tot + 1)];
	return A >= B;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}

		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}

		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);

		a[n + 1] = b[n + 1] = 0;

		for (int i = n; i; i--) {
			a[i] += a[i + 1];
			b[i] += b[i + 1];
		}

		int l = 0, r = n;

		while (l < r) {
			int mid = (l + r)>>1;

			if (check_(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		printf("%d\n", l);
	}
}