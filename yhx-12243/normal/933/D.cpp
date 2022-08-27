#include <bits/stdc++.h>
 
typedef long long ll;
const int mod = 1000000007;
 
inline ll prod(std::initializer_list <ll> il) {return std::accumulate(il.begin(), il.end(), 1ll, [] (const ll x, const ll y) {return x * (y % mod) % mod;});}
 
int main() {
	int x, y; ll n, x2, c0, c2, c4, y3, y5, y7, ans;
	scanf("%lld", &n), ans = prod({500000056, n, n + 1, n + 2});
	for (x2 = x = 0; x2 < n; x2 += ++x * 2 - 1) {
		y = sqrt(n - x2);
		c0 = prod({210, n - x2 + 1, n - x2 + 2, n + 2 * x2});
		c2 = (prod({210, x2, -n + x2 - 2}) + 105 * n + 140) % mod;
		c4 = 21 * (2 * x2 - n - 2) % mod;
		y3 = prod({y, 1 + y, 1 + 2 * y});
		y5 = prod({y3, 3 * y * (y + 1ll) - 1});
		y7 = prod({y3, 3 * y * (prod({y, y, y + 2}) - 1) + 1});
		ans = (ans + c0 * y + c2 * y3 + c4 * y5 + 10 * y7) % mod;
	}
	ans += ans >> 63 & mod, printf("%d\n", int(403174606 * ans % mod));
	return 0;
}