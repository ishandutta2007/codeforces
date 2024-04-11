#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, a[maxn + 3], b[maxn + 3], p[maxn + 3];
int bit[maxn + 3];

void add(int x) {
	for (int i = x; i; i ^= i & -i) {
		bit[i]++;
	}
}

int sum(int x) {
	int y = 0;
	for (int i = x; i <= n; i += i & -i) {
		y += bit[i];
	}
	return y;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	reverse(a + 1, a + n + 1);
	reverse(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		p[a[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (sum(p[b[i]])) {
			ans++;
		}
		add(p[b[i]]);
	}
	printf("%d\n", ans);
	return 0;
}