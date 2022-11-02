#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int T, n, k, a[maxn + 3];

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d %d", &n, &k);
		bool fl = false;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), fl |= a[i] == k, a[i] = a[i] >= k;
		if (n == 1) { puts(fl ? "Yes" : "No"); continue; }
		int L = -1;
		bool res = false;
		for (int i = 1; i <= n; i++) if (a[i]) {
			if (L != -1 && i - L <= 2) res = true;
			L = i;
		}
		puts(fl && res ? "Yes" : "No");
	}
	return 0;
}