#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
using namespace std;

typedef long long ll;
const int maxn = 2e5;
int n, k, a[maxn + 5], b[maxn + 5];

int main() {
	scanf("%d %d", &n, &k);
	ll c = 0;
	rep(i, 0, k - 1) {
		scanf("%d %d", &a[i], &b[i]);
		c += b[i];
	}
	if (c > n) {
		puts("-1");
	} else if (c < n) {
		puts("1");
	} else {
		int res = 0;
		rep(i, 0, k - 1) {
			res = (res + ll(a[i]) * b[i]) % n;
		}
		int num = 1ll * n * (n - 1) / 2 % n;
		puts(res == num ? "1" : "-1");
	}
	return 0;
}