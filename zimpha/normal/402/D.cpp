#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXN = 5000 + 10;

set<int> bad;
int a[MAXN], b[MAXN], g[MAXN];

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int calc(int x) {
	int ret = 0;
	for (int i = 2; i * i <= x; ++ i) {
		while (x % i == 0) {
			x /= i;
			if (bad.count(i)) ret --;
			else ret ++;
		}
	}
	if (x > 1) {
		if (bad.count(x)) ret --;
		else ret ++;
	}
	return ret;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	bad.clear();
	LL ans = 0;
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		if (i) g[i] = gcd(g[i - 1], a[i]);
		else g[i] = a[i];
	}
	for (int i = 0; i < m; ++ i) {
		scanf("%d", &b[i]);
		bad.insert(b[i]);
	}
	for (int i = 0; i < n; ++ i) {
		ans += calc(a[i]);
	}
	for (int i = n - 1, d = 1; i >= 0; -- i) {
		g[i] /= d;
		int tmp = calc(g[i]);
		if (tmp < 0) {
			ans -= tmp * (i + 1);
			d *= g[i];
		}
	}
	printf("%I64d\n", ans);
	return 0;
}