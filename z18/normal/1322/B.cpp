#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn = 4e5, maxm = 1 << 25;
int n, a[maxn + 3], bit[maxm + 3], cur, tot, mx;

void add(int x, int y) {
	x++, cur += y;
	for (int i = x; i <= maxm; i += i & -i) bit[i] += y;
}

int sum(int x) {
	int y = 0;
	if (x >= tot) y = cur, x -= tot;
	x++;
	for (int i = x; i; i ^= i & -i) y += bit[i];
	return y;
}
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = 0;
	for (int k = 0; k < 25; k++) {
		tot = (1 << (k + 1)), mx = tot - 1;
		ll su = 0;
		for (int i = 1, x; i <= n; i++) {
			x = a[i] & mx;
			su += sum(mx - x + tot);
			su -= sum((1 << k) - 1 - x + tot);
			add(x, 1);
		}
		for (int i = 1, x; i <= n; i++) {
			x = a[i] & mx;
			add(x, -1);
		}
		ans |= (su & 1) << k;
	}
	printf("%d\n", ans);
	return 0;
}