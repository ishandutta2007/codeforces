#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e17;
int n;
ll x[233], y[233], ax, ay, bx, by, sx, sy, t;

ll _abs(ll x) {
	return x < 0 ? -x : x;
}

int main() {
	scanf("%lld %lld %lld %lld %lld %lld", &x[0], &y[0], &ax, &ay, &bx, &by);
	for (int i = 1; i <= 100; i++) {
		if ((inf - bx) / ax < x[i - 1]) break;
		if ((inf - by) / ay < y[i - 1]) break;
		x[i] = 1ll * x[i - 1] * ax + bx;
		y[i] = 1ll * y[i - 1] * ay + by;
		n = i;
	}
	scanf("%lld %lld %lld", &sx, &sy, &t);
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ll tt = _abs(sx - x[i]) + _abs(sy - y[i]);
		if (tt > t) continue;
		tt = t - tt;
		int res = 1;
		bool flag = true;
		for (int j = i - 1; j >= 0; j--) {
			if (tt < _abs(x[j + 1] - x[j]) + _abs(y[j + 1] - y[j])) {
				flag = false;
				break;
			}
			res++, tt -= _abs(x[j + 1] - x[j]) + _abs(y[j + 1] - y[j]);
		}
		if (flag == false || i == n) {
			ans = max(ans, res);
			continue;
		}
		if (tt < _abs(x[0] - x[i + 1]) + _abs(y[0] - y[i + 1])) {
			ans = max(ans, res);
			continue;
		}
		res++, tt -= _abs(x[0] - x[i + 1]) + _abs(y[0] - y[i + 1]);
		for (int j = i + 1; j < n; j++) {
			if (tt < _abs(x[j + 1] - x[j]) + _abs(y[j + 1] - y[j])) {
				break;
			}
			res++, tt -= _abs(x[j + 1] - x[j]) + _abs(y[j + 1] - y[j]);
		}
		ans = max(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}