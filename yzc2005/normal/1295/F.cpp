#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; 
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
} 
inline void add(int &a, int b) {a += b; if(a > mod) a -= mod;}
inline void mul(int &a, int b) {a = 1LL * a * b % mod;} 

int n, l[N], r[N], b[N << 1], cnt;
int f[N][N << 1], g[N][N << 1], inv[N];

inline int pos(int x) {
	return lower_bound(b + 1, b + cnt + 1, x) - b;
}

inline int getinv(int a) {
	int res = 1, b = mod - 2;
	while(b) {
		if(b & 1) mul(res, a);
		mul(a, a), b >>= 1;
	}
	return res;
}

int main() {
	rd(n); 
	inv[1] = 1; 
	fu(i, 2, n) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	fu(i, 1, n) {
		rd(l[i]), rd(r[i]), ++r[i];
		b[++cnt] = l[i], b[++cnt] = r[i];
	}
	sort(b + 1, b + cnt + 1); cnt = unique(b + 1, b + cnt + 1) - b - 1;
	fu(i, 0, cnt) g[0][i] = 1;
	fu(i, 1, n) l[i] = pos(l[i]), r[i] = pos(r[i]);
	fu(i, 1, n) {
		fu(j, l[i], r[i] - 1) {
			int len = b[j + 1] - b[j], cur = 1, c = len;
			fd(k, i - 1, 0) {
				add(f[i][j], 1LL * g[k][j + 1] * c % mod);
				if(l[k] <= j && j + 1 <= r[k]) ++cur, c = 1LL * c * (len + cur - 1) % mod * inv[cur] % mod; else break;
				if(!c) break;
			}
		}
		fd(j, cnt - 1, 0) g[i][j] = g[i][j + 1], add(g[i][j], f[i][j]);
	}
	int ans = g[n][0];
	fu(i, 1, n) mul(ans, getinv(b[r[i]] - b[l[i]]));
	return printf("%d", ans), 0;
}