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

const int mod = 1e9 + 7, inv2 = 5e8 + 4;
template <class T, class H> inline void addmod(T &a, H b) {a = (a + b) % mod;}
template <class T, class H> inline void mulmod(T &a, H b) {a = 1LL * a * b % mod;}

const int N = 3e5 + 5;
int n, q, x, ans, lstpos[N], inv[N];

struct node {
	int id, val, p, pos;
	inline bool operator < (const node &n1) const {
		if(val == n1.val) return id < n1.id;
		return val < n1.val;
	}
} a[N << 1], b[N << 1];

struct SegmentTree {
	#define ls p << 1
	#define rs p << 1 | 1
	#define mid (l[p] + r[p] >> 1)
	int l[N << 3], r[N << 3], lval[N << 3], rval[N << 3], val[N << 3], len[N << 3];
	inline void pushup(int p) {
		len[p] = len[ls] + len[rs];
		val[p] = ((val[ls] + val[rs]) % mod + 1ll * rval[ls] * lval[rs] % mod) % mod;
		lval[p] = (1ll * lval[rs] * inv[len[ls]] % mod + lval[ls]) % mod;
		rval[p] = (1ll * rval[ls] * inv[len[rs]] % mod + rval[rs]) % mod;
	}
	void build(int p, int L, int R) {
		l[p] = L, r[p] = R;
		if(L == R) return;
		build(ls, L, mid), build(rs, mid + 1, R);
	}
	void modify(int p, int pos, int v) {
		if(l[p] == r[p]) {
			len[p] = (v ? 1 : 0);
			lval[p] = rval[p] = 1ll * v * inv[len[p]] % mod;
			return;
		}
		if(mid >= pos) modify(ls, pos, v);
		else modify(rs, pos, v);
		pushup(p);
	}
} smt; 

int main() {
	rd(n), inv[0] = 1;
	fu(i, 1, n) inv[i] = 1ll * inv[i - 1] * inv2 % mod;
	fu(i, 1, n) rd(a[i].val), a[i].id = i;
	rd(q); fu(i, 1, q) rd(a[n + i].pos), rd(a[n + i].val), a[n + i].id = n + i;
	sort(a + 1, a + n + q + 1);
	fu(i, 1, n + q) b[a[i].id] = a[i], b[a[i].id].p = i;
	smt.build(1, 1, n + q);
	fu(i, 1, n) lstpos[i] = b[i].p, smt.modify(1, b[i].p, b[i].val);
	printf("%d\n", smt.val[1]);
	fu(i, n + 1, n + q) {
		smt.modify(1, lstpos[b[i].pos], 0);
		smt.modify(1, b[i].p, b[i].val);
		lstpos[b[i].pos] = b[i].p;
		printf("%d\n", smt.val[1]);
	}
	return 0;
}