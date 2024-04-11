#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, x, y) for(int i = x; i <= (y); ++i)

const int kN = 4e5 + 5;

int a[kN], b[kN], n, ans = 0;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 0, 28) {
		int tot = 0;
		rep(j, 1, n) b[j] = a[j] % (2 << i);
		std::sort(b + 1, b + n + 1);
		rep(j, 1, n - 1) {
			int L1 = std::lower_bound(b + j + 1, b + n + 1, (1 << i) - b[j]) - b,
				R1 = std::lower_bound(b + j + 1, b + n + 1, (2 << i) - b[j]) - b - 1,
				L2 = std::lower_bound(b + j + 1, b + n + 1, (3 << i) - b[j]) - b;
			tot += R1 - L1 + 1 + n - L2 + 1;
			tot &= 1;
		}
		ans |= tot << i;
	}
	printf("%d", ans);
	return 0;
}