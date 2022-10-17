#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 2e5 + 10;
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
 
struct SegmentTree {
	int l[N << 2], r[N << 2];
	ll val[N << 2], lzy[N << 2];
	#define mid (l[p] + r[p] >> 1)
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	 
	inline void pushup(int p) {
		val[p] = min(val[ls], val[rs]);
	} 
	
	inline void tag(int p, ll v) {
		val[p] += v;
		lzy[p] += v;
	}
	
	inline void pushdown(int p) {
		if(lzy[p]) {
			tag(ls, lzy[p]);
			tag(rs, lzy[p]);
			lzy[p] = 0;
		}
	}
	
	void build(int p, int L, int R) {
		l[p] = L, r[p] = R;
		if(l[p] == r[p]) return;
		build(ls, L, mid), build(rs, mid + 1, R);
	}
	
	void modify(int p, int L, int R, int v) {
		if(l[p] >= L && r[p] <= R) return tag(p, v);
		pushdown(p);
		if(mid >= L) modify(ls, L, R, v);
		if(mid < R) modify(rs, L, R, v);
		pushup(p);
	}
	
	inline ll query() {
		return val[1];
	}
} smt;
 
int a[N], b[N], n;
 
int main() {
	read(n); 
	fu(i, 1, n) read(a[i]);
	fu(i, 1, n) read(b[i]);
	smt.build(1, 0, n); ll ans = 1e18;
	fu(i, 1, n) smt.modify(1, a[i], n, b[i]);
	fu(i, 1, n - 1) {
		smt.modify(1, a[i], n, -b[i]);
		smt.modify(1, 0, a[i] - 1, b[i]);
		ckmin(ans, smt.query());
	}
	printf("%lld\n", ans);
}