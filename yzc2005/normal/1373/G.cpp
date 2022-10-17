#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, k, m;
set <pair<int, int> > s;
multiset <int> maxr;

struct SegT {
	int l, r, mx, lzy;
} tr[N << 3];
#define ls p << 1
#define rs p << 1 | 1
#define mid (tr[p].l + tr[p].r >> 1) 
void build(int p, int l, int r) {
	tr[p].l = l, tr[p].r = r;
	tr[p].mx = r - n - 1;
	if(l == r) return;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}
void pushup(int p) {
	tr[p].mx = max(tr[ls].mx, tr[rs].mx);
}
void tag(int p, int x) {
	tr[p].lzy += x;
	tr[p].mx += x;
}
void pushdown(int p) {
	if(tr[p].lzy) {
		tag(ls, tr[p].lzy);
		tag(rs, tr[p].lzy);
		tr[p].lzy = 0;
	}
}
void modify(int p, int l, int r, int v) {
	if(tr[p].l >= l && tr[p].r <= r) return tag(p, v);
	pushdown(p);
	if(mid >= l) modify(ls, l, r, v);
	if(mid < r) modify(rs, l, r, v);
	pushup(p);
}
int query(int p, int l, int r) {
	if(tr[p].l >= l && tr[p].r <= r) return tr[p].mx;
	int res = -1e9; pushdown(p);
	if(mid >= l) res = max(res, query(ls, l, r));
	if(mid < r) res = max(res, query(rs, l, r));
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k >> m;
	build(1, 1, 2 * n); 
	for(int i = 1, x, y; i <= m; ++i) {
		cin >> x >> y;
		int r = y + abs(x - k);
		if(s.count(make_pair(x, y))) {
			modify(1, 1, r, -1);
			s.erase(make_pair(x, y));
			maxr.erase(maxr.find(r));
		} else {
			modify(1, 1, r, 1);
			s.insert(make_pair(x, y));
			maxr.insert(r);
		}
		if(maxr.empty()) cout << '0' << '\n';
		else cout << max(0, query(1, 1, *maxr.rbegin())) << '\n';
	}	
	return 0;
}