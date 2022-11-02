#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5, mod = 998244353;
int n, k, a[maxn + 3];
ll sum;
bool b[maxn + 3];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = n - k + 1; i <= n; i++) {
		sum += i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] >= n - k + 1) {
			b[i] = true;
		}
	}
	int lst = 0, res = 1;
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			if (lst) {
				res = 1ll * res * (i - lst) % mod;
			}
			lst = i;
		}
	}
	printf("%I64d %d\n", sum, res);
	return 0;
}