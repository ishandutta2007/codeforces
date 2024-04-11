#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int n, a[maxn + 3], b[maxn + 3];

int main() {
	scanf("%d", &n);
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		a[i] = b[i] + mx;
		mx = max(mx, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}