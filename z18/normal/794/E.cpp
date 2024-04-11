#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5, inf = 1e9;
int n, mx, a[maxn + 3], f[maxn + 3];

void upd(int &x, int y) {
	x = max(x, y);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for (int i = 2; i < n; i++) {
		upd(f[min(i - 1, n - i) * 2 + 1], min(a[i], max(a[i - 1], a[i + 1])));
	}
	for (int i = 1; i < n; i++) {
		upd(f[min(i, n - i) * 2], max(a[i], a[i + 1]));
	}
	for (int i = n - 2; i >= 2; i--) {
		upd(f[i], f[i + 2]);
	}
	for (int i = n; i >= 2; i--) {
		printf("%d ", f[i]);
	}
	printf("%d\n", mx);
	return 0;
}