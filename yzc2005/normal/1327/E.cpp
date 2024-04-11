#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 200005, mod = 998244353;
int n, p[N];

int main() {
	scanf("%d", &n);
	p[0] = 1; fu(i, 1, n) p[i] = 1ll * p[i - 1] * 10 % mod;
	if(n == 1) puts("10"), exit(0);
	fu(i, 1, n) {
		if(i == n) {
			puts("10");
			continue;
		}
		int ans = 0;
		ans = (ans + 1ll * (n - i - 1) * p[n - i - 1] % mod * 9 % mod * 9 % mod) % mod;
		ans = (ans + 1ll * 2 * p[n - i] % mod * 9 % mod) % mod;
		printf("%d ", ans);
	}
	return 0;
}