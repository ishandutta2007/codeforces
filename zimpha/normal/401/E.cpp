#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;

vector<int> d[MAXN];
LL n, m, l, r, p;

LL calc(LL low, LL high, LL m) {
	high /= m; low = (low + m - 1) / m;
	return ((high - low + 1) * (n + 1) - m * ((high * (high + 1) - low * (low - 1)) / 2)) % p;
}

int main() {
	cin >> n >> m >> l >> r >> p;
	for (int i = 1; i <= m; ++ i) d[i].clear();
	for (int i = 2; i <= m; ++ i)
		if (!d[i].size()) {
			for (int j = i; j <= m; j += i) d[j].push_back(i);
		}
	LL low = l, high = r, ans = 0;
	for (LL w = 1; w <= m && w <= r; ++ w) {
		while (low > 1 && l * l - w * w <= (low - 1) * (low - 1)) low --;
		while (r * r - w * w < high * high) high --;
		if (low <= high && low <= n) {
			LL ret = 0, s = d[w].size();
			for (int mask = 0; mask < (1 << s); ++ mask) {
				LL cof = 1, mul = 1;
				for (int i = mask, j = 0; j < s; ++ j, i >>= 1) {
					if (i & 1) mul *= d[w][j], cof *= -1;
				}
				ret += cof * calc(low, min(high, n), mul);
			}
			ans = (ans + ret * (m - w + 1)) % p;
			if (ans < 0) ans += p;
		}
	}
	if (l <= 1 && r >= 1) ans = (2 * ans + m * (n + 1) + n * (m + 1)) % p;
	else ans = 2 * ans % p;
	cout << ans << endl;
	return 0;
}