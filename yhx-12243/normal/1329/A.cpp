#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054;

int n, R;
int l[N];
ll a[N];

int main() {
	int i;
	scanf("%d%d", &R, &n);
	for (i = 1; i <= n; ++i) scanf("%d", l + i);
	for (a[1] = i = 1; i <= n; ++i) a[i + 1] = a[i] + l[i];
	if (a[n + 1] < R + 1) return puts("-1"), 0;
	a[n + 1] = R + 1;
	for (i = n; i; --i)
		a[i] = std::min(a[i], a[i + 1] - 1),
		a[i] = std::min<ll>(a[i], R - l[i] + 1);
	if (a[1] < 1) return puts("-1"), 0;
	for (i = 1; i <= n; ++i)
		printf("%d%c", (int)a[i], i == n ? 10 : 32);
	return 0;
}