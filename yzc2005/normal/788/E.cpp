#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
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

const int mod = 1e9 + 7;
const int N = 100005;
int n, q, cnt, A[N], B[N], pre[N], suf[N], p, t;

struct FenwickTree {
	int s[N];
	inline void add(int p, int v) {
		for(; p <= cnt; p += p & -p) s[p] += v; 
	}
	inline int query(int p) {
		int res = 0;
		for(; p; p -= p & -p) res += s[p];
		return res;
	}
} bit;

const int M = N * 20;
int segcnt, rt[N], ls[M], rs[M], a[M], b[M], c[M], ab[M], bc[M], abc[M];
inline void pushup(int p) {
	a[p] = (a[ls[p]] + a[rs[p]]) % mod;
	b[p] = (b[ls[p]] + b[rs[p]]) % mod;
	c[p] = (c[ls[p]] + c[rs[p]]) % mod;
	ab[p] = ((ab[ls[p]] + ab[rs[p]]) % mod + 1ll * a[ls[p]] * b[rs[p]] % mod) % mod;
	bc[p] = ((bc[ls[p]] + bc[rs[p]]) % mod + 1ll * b[ls[p]] * c[rs[p]] % mod) % mod;
	abc[p] = (((abc[ls[p]] + abc[rs[p]]) % mod + 1ll * ab[ls[p]] * c[rs[p]] % mod) + 1ll * a[ls[p]] * bc[rs[p]]) % mod; 
}
void modify(int &p, int l, int r, int pos, int v) {
	if(!p) p = ++segcnt;
	if(l == r) {
		if(v) a[p] = pre[l], b[p] = 1, c[p] = suf[l];
		else a[p] = b[p] = c[p] = 0;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls[p], l, mid, pos, v);
	else modify(rs[p], mid + 1, r, pos, v);
	pushup(p);
} 

int main() {
	rd(n);
	fu(i, 1, n) rd(A[i]), B[i] = A[i];
	sort(B + 1, B + n + 1); cnt = unique(B + 1, B + n + 1) - B - 1;
	fu(i, 1, n) {
		A[i] = lower_bound(B + 1, B + cnt + 1, A[i]) - B;
		pre[i] = bit.query(A[i]);
		bit.add(A[i], 1);
	}
	memset(bit.s, 0, sizeof(bit.s));
	fd(i, n, 1) {
		suf[i] = bit.query(A[i]);
		bit.add(A[i], 1);
		modify(rt[A[i]], 1, n, i, 1);
	}
	int ans = 0;
	fu(i, 1, cnt) ans = (ans + abc[rt[i]]) % mod;
	for(rd(q); q; --q) {
		rd(t), rd(p);
		ans = (ans - abc[rt[A[p]]]) % mod;
		modify(rt[A[p]], 1, n, p, t - 1);
		ans = (ans + abc[rt[A[p]]]) % mod;
		printf("%d\n", ans = (ans + mod) % mod);
	}
	return 0;
}