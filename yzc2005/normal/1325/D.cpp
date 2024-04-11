#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

typedef long long ll;
ll a, b, ans[1000005], n;

int main() {
	rd(a), rd(b), b -= a;
	ll _b = b;
	if(b < 0) puts("-1"), exit(0);
	if(a) ans[n = 1] = a;
	fd(i, 62, 0) {
		ll cur = b >> i;
		if(cur & 1) --cur; 
		b -= cur << i;
		if(a >> i & 1) {
			ckmax(n, cur + 1);
			fu(j, 2, cur + 1) ans[j] |= 1ll << i;
		} else {
			ckmax(n, cur);
			fu(j, 1, cur) ans[j] |= 1ll << i;
		}
	}
	ll x = 0, y = 0;
	fu(i, 1, n) x ^= ans[i], y += ans[i];
	if(x != a || y != a + _b) puts("-1"), exit(0);
	printf("%lld\n", n);
	fu(i, 1, n) printf("%lld ", ans[i]);
}