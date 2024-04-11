#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 400005;
int n, d[N];
ll s[N], t[N], m, ans;
inline ll f(int n, int l) {return 1ll * (2 * n - l + 1) * l / 2;}

int main() {
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
		t[i] = t[i - 1] + d[i];
		s[i] = s[i - 1] + f(d[i], d[i]);
		ans = max(ans, f(d[i], min(1ll * d[i], m)));
	}
	for(int i = n + 1; i <= 2 * n; ++i) {
		d[i] = d[i - n];
		t[i] = t[i - 1] + d[i];
		s[i] = s[i - 1] + f(d[i], d[i]);
	}
	for(int i = 1, l = 1; i <= 2 * n; ++i) {
		while(l <= i && t[i] - t[l - 1] > m) ++l;
		ll res = s[i] - s[l - 1], rest = m - (t[i] - t[l - 1]);
		ans = max(ans, res + f(d[l - 1], rest));
	}
	printf("%lld", ans);
}