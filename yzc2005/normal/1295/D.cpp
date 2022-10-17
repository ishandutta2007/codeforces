#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(rg int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
#define reset(a) memset(a, 0, sizeof(a))
#define finish(a) return a, 0;
typedef pair<int, int> P;
typedef long long ll;
template <class T> inline void read(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T> inline void ckmin(T &a, T b) {a = min(a, b);}
template <class T> inline void addmod(T &a, T b) {a = (a + b) % mod;}
/*
	x / k = (a / k, (a + m) / k - 1)
*/
 
int T, cnt;
ll a, m, pr[100];
 
inline void work(ll x) {
	cnt = 0;
	ll ans = x, xx = x;
	for(ll p = 2; p * p <= x; ++p) 
		if(xx % p == 0) {
			pr[++cnt] = p;
			while(xx % p == 0) xx /= p;
		}
	if(xx > 1) pr[++cnt] = xx;
}
 
inline ll calc(ll x) {
	ll ans = 0;
	fu(S, 0, (1 << cnt) - 1) {
		int len = 0;
		ll cur = 1;
		fu(j, 0, cnt - 1) if(S >> j & 1) ++len, cur *= pr[j + 1];
		if(len % 2 == 1) ans -= x / cur;
		else ans += x / cur;
	}
	return ans;
}
 
int main() {
	read(T); while(T--) {
		read(a), read(m);
		ll k = __gcd(a, m);
		work(m / k); 
		printf("%lld\n", calc((a + m) / k - 1) - calc(a / k - 1));
	}
	return 0;
}