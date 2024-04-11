#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fail puts("NO"), exit(0)
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
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

const int N = 2e5 + 5, M = 4e5 + 5;

int n, m, k, tmp[M], cnt;
ll mxval[M], ans = -INF;

struct item {
	int w, c;
	inline friend bool operator < (const item &i1, const item &i2) {
		return i1.w < i2.w;
	}
} a[N], b[N];

struct mst {
	int a, b, w;
	inline friend bool operator < (const mst &m1, const mst &m2) {
		return m1.a < m2.a;
	}
} c[N];

struct SegmentTree {
	int l[M << 2], r[M << 2];
	ll val[M << 2], lzy[M << 2];
	#define mid (l[p] + r[p] >> 1)
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	inline void pushup(int p) {
		val[p] = max(val[ls], val[rs]);
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
		if(l[p] == r[p]) return val[p] = mxval[L], void();
		build(ls, L, mid), build(rs, mid + 1, R);
		pushup(p);
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

int main() {
	rd(n), rd(m), rd(k);
	fu(i, 1, n) rd(a[i].w), rd(a[i].c);
	fu(i, 1, m) rd(b[i].w), rd(b[i].c), tmp[++cnt] = b[i].w;
	fu(i, 1, k) rd(c[i].a), rd(c[i].b), rd(c[i].w), tmp[++cnt] = c[i].b;
	sort(tmp + 1, tmp + cnt + 1), cnt = unique(tmp + 1, tmp + cnt + 1) - tmp - 1;
	sort(a + 1, a + n + 1), sort(c + 1, c + k + 1);
	fu(i, 1, m) b[i].w = lower_bound(tmp + 1, tmp + cnt + 1, b[i].w) - tmp;
	fu(i, 1, k) c[i].b = lower_bound(tmp + 1, tmp + cnt + 1, c[i].b) - tmp;
	mem(mxval, 0xcf);
	fu(i, 1, m) ckmax(mxval[b[i].w], -1ll * b[i].c);
	smt.build(1, 1, cnt);
	for(int i = 1, r = 0; i <= n; ++i) {
		while(r < n && c[r + 1].a < a[i].w) {
			++r; if(c[r].b == cnt) continue;
			smt.modify(1, c[r].b + 1, cnt, c[r].w);
		}
		ckmax(ans, -a[i].c + smt.query());
	}
	cout << ans << endl;
}