#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
typedef long long int64;
int powerMod(int a, int64 e, int mod) {
	if (e == 0)
		return 1;
	if (e % 2 == 0)
		return powerMod(1LL * a * a % mod, e >> 1, mod);
	else
		return 1LL * powerMod(a, e - 1, mod) * a % mod;
}

int get(int k, int64 l, int p) {
	return powerMod(k, powerMod(2, l, p - 1) + p - 1, p);
}

template<class T>
inline T nextInt() {
	T x = 0;
	char ch;
	while (ch = getchar(), ch < '0' || ch > '9')
		;
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0';
	return x;
}

int main() {
	int nT = nextInt<int>();
	for (int i = 0; i < nT; ++i) {
		int k, p;
		int64 l, r;
//		cin >> k >> l >> r >> p;
		k = nextInt<int>(), l = nextInt<int64>(), r = nextInt<int64>(), p = nextInt<int>();
		if (p == 2) {
			printf("%d\n", 1 - k % 2);
			continue;
		}
		int a = get(k, l, p), ans;
		if (a == 0) {
			ans = 1;
		} else if (a == 1) {
			ans = powerMod(2, r - l + 1, p);
		} else {
			ans = 1LL * (get(a, r - l + 1, p) + p - 1) * powerMod(a - 1, p - 2, p) % p;
		}
		if (k % 2 == 1)
			ans = 1LL * ans * powerMod((p + 1) / 2, r - l, p) % p;
//		cout << ans << endl;
		printf("%d\n", ans);
	}
	return 0;
}