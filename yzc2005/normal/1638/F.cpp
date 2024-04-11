#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, stk[N], pos[N];
long long a[N], c[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	long long ans = 0;
	for (int o = 1; o <= n; ++o) {
		long long x = a[o];
		int l = o, r = o;
		for (; l > 1 && a[l - 1] >= x; --l);
		for (; r < n && a[r + 1] >= x; ++r);
		for (int i = l; i <= r; ++i)
			a[i] -= x;
		int top = 0;
		for (int i = 1; i <= n; ++i) {
			for (; top && a[stk[top]] > a[i]; --top)
				ans = max(ans, (r - l + 1) * x + a[stk[top]] * (i - pos[stk[top]] - 1));
			pos[i] = stk[top];
			stk[++top] = i;
		}
		for (; top; --top)
			ans = max(ans, (r - l + 1) * x + a[stk[top]] * (n - pos[stk[top]]));
		for (int i = l; i <= r; ++i)
			a[i] += x;
		c[l] = c[r] = 1e12;
		for (int i = l - 1; i; --i)
			c[i] = min(c[i + 1], a[i]);
		for (int i = r + 1; i <= n; ++i)
			c[i] = min(c[i - 1], a[i]);
		for (int i = l - 1, ptr = n; i; --i) {
			if (c[i] > x) continue;
			for (; ptr > r && c[ptr] + c[i] < x; --ptr);
			if (ptr > r) ans = max(ans, (x - c[i]) * (ptr - l + 1) + c[i] * (r - i + 1));
		}
		for (int i = r + 1, ptr = 1; i <= n; ++i) {
			if (c[i] > x) continue;
			for (; ptr < l && c[ptr] + c[i] < x; ++ptr);
			if (ptr < l) ans = max(ans, (x - c[i]) * (r - ptr + 1) + c[i] * (i - l + 1));
		}
	}
	printf("%lld\n", ans);
	return 0;
}