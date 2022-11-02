#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5, inf = 1e9;
int n, a[maxn + 3], top, st[maxn + 3], num[maxn + 3], b[maxn + 3], ans[maxn + 3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]), a[n + i] = a[i];
	}
	for (int i = n * 2; i > n; i--) {
		while (top && a[st[top]] >= a[i]) {
			top--;
		}
		st[++top] = i;
	}
	bool flag = false;
	for (int i = n; i; i--) {
		int t = (a[i] - 1) / 2;
		int l = top, r = 0, mid;
		while (l > r) {
			mid = (l + r + 1) / 2;
			if (a[st[mid]] <= t) {
				r = mid;
			} else {
				l = mid - 1;
			}
		}
		num[i] = st[l];
		flag |= num[i];
		if (!num[i]) {
			num[i] = inf;
		}
		while (top && a[st[top]] >= a[i]) {
			top--;
		}
		st[++top] = i;
	}
	if (!flag) {
		for (int i = 1; i <= n; i++) {
			printf("%d%c", -1, " \n"[i == n]);
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		b[i] = num[i], b[i + n] = num[i] + n, b[i + 2 * n] = num[i] + 2 * n;
	}
	int x = inf;
	for (int i = 3 * n; i > n; i--) {
		x = min(x, b[i]);
	}
	for (int i = n; i; i--) {
		x = min(x, b[i]);
		ans[i] = x - i;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}