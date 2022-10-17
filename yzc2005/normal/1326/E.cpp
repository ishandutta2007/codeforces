#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)

const int N = 300005;

struct SegmentTree {
    int l[N << 2], r[N << 2], val[N << 2], lzy[N << 2];
    #define mid (l[p] + r[p] >> 1)
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    inline void pushup(int p) {
        val[p] = min(val[ls], val[rs]);
    } 
    inline void tag(int p, int v) {
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
        pushup(p);
    }
    void modify(int p, int L, int R, int v) {
        if(l[p] >= L && r[p] <= R) return tag(p, v);
        pushdown(p);
        if(mid >= L) modify(ls, L, R, v);
        if(mid < R) modify(rs, L, R, v);
        pushup(p);
    }
} smt;

int n, a[N], x;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &x), a[x] = i;
	int cur = n + 1; smt.build(1, 1, n);
	rep(i, 1, n) {
		scanf("%d", &x);
		while(smt.val[1] >= 0) smt.modify(1, 1, a[--cur], -1);
		printf("%d ", cur);
		smt.modify(1, 1, x, 1);
	}
	return 0;
}