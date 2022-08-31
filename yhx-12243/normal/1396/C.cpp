#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 1000054;

int n, r1, r2, r3, d;
int a[N];
ll norm[N], laser[N];
ll pre[N], suf[N];

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

int main() {
	int i; ll base, ans;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> r1 >> r2 >> r3 >> d, base = (n - 1ll) * d;
	for (i = 1; i <= n; ++i)
		cin >> a[i], norm[i] = (ll)r1 * a[i] + r3,
		laser[i] = std::min<ll>(r1 + r2, r1 * (a[i] + 2ll)),
		assert(laser[i] <= norm[i]);
	for (i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + norm[i];
		if (i > 1)
			down(pre[i], pre[i - 2] + 2 * d + laser[i - 1] + laser[i]);
		if (i > 2)
			down(pre[i], pre[i - 3] + 4ll * d + laser[i - 2] + laser[i - 1] + laser[i]);
	}
	ans = pre[n], suf[n] = norm[n];
	for (i = n - 1; i; --i) suf[i] = suf[i + 1] + d + laser[i], down(ans, pre[i - 1] + suf[i]);
	cout << base + ans << '\n';
	return 0;
}