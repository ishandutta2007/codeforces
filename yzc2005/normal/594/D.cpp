#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define fu(i, a, b) for(rint i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rint i = a, I = (b) - 1; i > I; --i)
#define finish(x) return x, 0;

const int N = 2e5 + 5, M = 1e6 + 5, mod = 1e9 + 7;
inline void addmod(int &a, int b) {a = (a + b) % mod;}
inline void mulmod(int &a, int b) {a = 1LL * a * b % mod;}

int n, m, a[N], ans[N];
int f[M], pr[N], cnt;
int c[N], lst[M], pre[N];

inline void sieve(int mx) {
	fu(i, 2, mx) {
		if(!f[i]) f[i] = i, pr[++cnt] = i;
		fu(j, 1, cnt) {
			if(i * pr[j] > mx || pr[j] > f[i]) break;
			f[i * pr[j]] = pr[j];
		}
	}
}

inline int inv(int a) {
	int res = 1, b = mod - 2;
	while(b) {
		if(b & 1) mulmod(res, a);
		mulmod(a, a), b >>= 1;
	}
	return res;
}

struct Query {
	int id, l, r;
	inline bool operator < (const Query &q1) const{return r < q1.r;}
} q[N];

inline void modify(int pos, int val) {
	while(pos <= n) {
		mulmod(c[pos], val);
		pos += pos & -pos;
	} 
}

inline int query(int pos) {
	int res = 1;
	while(pos) {
		mulmod(res, c[pos]);
		pos -= pos & -pos;
	}
	return res;
}

inline void update(int i) {
	for(int x = a[i], p = f[x]; x > 1; p = f[x]) {
		modify(i, p - 1), modify(i, inv(p));
		if(lst[p]) modify(lst[p], inv(p - 1)), modify(lst[p], p);
		lst[p] = i;
		while(x % p == 0) x /= p;
	}
}

int main() {
	scanf("%d", &n);
	fu(i, 1, n) c[i] = 1;
	pre[0] = 1; 
	fu(i, 1, n) scanf("%d", &a[i]), pre[i] = 1LL * pre[i - 1] * a[i] % mod;
	sieve(*max_element(a + 1, a + n + 1));
	scanf("%d", &m);
	fu(i, 1, m) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i; 
	sort(q + 1, q + m + 1);
	fu(i, 1, m) {
		int l = q[i].l, r = q[i].r;
		fu(j, q[i - 1].r + 1, r) update(j);
		ans[q[i].id] = 1LL * pre[r] * inv(pre[l - 1]) % mod * query(r) % mod * inv(query(l - 1)) % mod;
	}
	fu(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}