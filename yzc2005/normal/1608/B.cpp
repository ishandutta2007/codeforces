#include <bits/stdc++.h>
using namespace std;
int n, a, b, p[100005];
void solve() {
	scanf("%d%d%d", &n, &a, &b);
	if (a + b > n - 2 || max(a, b) > (n - 1) / 2 || abs(a - b) > 1) {
		puts("-1");
		return;
	}
	bool rev = false;
	if (a > b) {
		swap(a, b);
		rev = true;
	}
	++a, ++b;
	if (a == b) {
		int x = 1, y = 2 * a;
		for (int i = 1; i <= 2 * a; ++i) {
			if (i & 1) {
				p[i] = x++;
			} else {
				p[i] = y--;
			}
		}
		iota(p + 2 * a + 1, p + n + 1, 2 * a + 1);
	} else {
		int x = 1, y = 2 * a + 1;
		for (int i = 1; i <= 2 * a + 1; ++i) {
			if (i & 1) {
				p[i] = y--;
			} else {
				p[i] = x++;
			}
		}
		iota(p + 2 * a + 2, p + n + 1, 2 * a + 2);
	}
	if (rev) {
		for (int i = 1; i <= n; ++i) {
			p[i] = n - p[i] + 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", p[i], " \n"[i == n]);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}