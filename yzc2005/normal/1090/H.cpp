#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q, sum[18][N];
char s[N];
int main() {
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; ++i)
		s[i] -= 48;
	for (int i = n; i; --i)
		s[i] ^= s[i - 1];
	for (int k = 1; k < 18; ++k) {
		for (int i = 1; i <= n; ++i) {
			sum[k][i] = (s[i] == 0);
			if (i > 1 << k) sum[k][i] += sum[k][i - (1 << k)];
		}
	}
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int len = r - l + 1, res = 0;
		for (int k = 1; 1 << k < len; ++k) {
			int p1 = l - (1 << (k - 1)) + 1, p2 = p1 + len;
			int c0 = sum[k][p2];
			if (p1 > 0) c0 -= sum[k][p1];
			int c1 = len / (1 << k) - c0;
			res += min(c0, c1);
		}
		printf("%d\n", (res + 1) / 2);
	}
	return 0;
}