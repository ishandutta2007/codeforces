#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long INF = 1e18;
const int N = 255, mod = 1e9 + 7;
#define rint register int
#define fu(i, a, b) for(rint i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rint i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(rg int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
#define reset(a) memset(a, 0, sizeof(a))
#define finish(a) a, exit(0)
#define fail puts("NO"), exit(0)
typedef pair<int, int> P;
typedef long long ll;
template <class T> inline void read(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void addmod(T &a, T b) {a = (a + b) % mod;}
template <class T> inline void mulmod(T &a, T b) {a = 1LL * a * b % mod;}
inline int quickpow(int a, int b) {
   int res = 1;
   while(b) {
		if(b & 1) mulmod(res, a);
		mulmod(a, a), b >>= 1;
   }
   return res;
}

int n, k, ans;
int C[N][N];

inline int calc(int i, int j) {
	int u = (n - i) * (n - j);
	int res = 1LL * C[n][i] * C[n][j] % mod * quickpow(k, u) % mod * quickpow(k - 1, n * n - u) % mod;
	if((i + j) & 1) res = -res;
	return res;
}

int main() {
	read(n), read(k);
	fu(i, 0, n) C[i][0] = 1;
	fu(i, 1, n) fu(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	fu(i, 0, n)	fu(j, 0, n) addmod(ans, calc(i, j));
	finish(printf("%d", (ans + mod) % mod)); 
}