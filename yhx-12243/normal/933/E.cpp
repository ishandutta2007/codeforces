#include <bits/stdc++.h>

typedef long long ll;
const int N = 300054;

int n;
int a[N], from[N];
int cnt = 0, ans[N];
ll f[N];

inline bool down(ll &x, const ll y) {return x > y ? x = y, 1 : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

inline void push(int l) {int w = min(a[l], a[l + 1]); if (w) ans[cnt++] = l, a[l] -= w, a[l + 1] -= w;}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	f[1] = a[1], f[2] = a[2];
	for (i = 3; i <= n; ++i) {
		f[i] = f[i - 2] + a[i], from[i] = i - 2;
		if (down(f[i], f[i - 3] + max(a[i - 1], a[i])))
			from[i] = i - 3;
	}
	for (i = n - (f[n - 1] < f[n]); i; push(i), i = from[i])
		for (j = i - 1; j > from[i]; --j) push(j);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; ++i) printf("%d\n", ans[i]);
	return 0;
}