#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int inf = 0x3f3f3f3f;
int Case, n, a[N], b[N];
deque<int> c[N];

struct SegT {
	int l, r, v;	
} t[N << 2];
#define ls p << 1
#define rs p << 1 | 1
#define mid (t[p].l + t[p].r >> 1)
inline void pushup(int p) {t[p].v = min(t[ls].v, t[rs].v);}
void build(int p, int l, int r) {
	t[p].l = l, t[p].r = r;
	if(l == r) return t[p].v = a[l], void();
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(p);
}
void modify(int p, int pos, int val) {
	if(t[p].l == t[p].r) return t[p].v = val, void();
	if(mid >= pos) modify(ls, pos, val);
	else modify(rs, pos, val);
	pushup(p);
}
int query(int p, int l, int r) {
	if(t[p].l > r || t[p].r < l) return inf;
	if(t[p].l >= l && t[p].r <= r) return t[p].v;
	return min(query(ls, l, r), query(rs, l, r));
}

int main() {
	for(scanf("%d", &Case); Case; --Case) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) c[i].clear(); 
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			c[a[i]].push_back(i);
		}
		build(1, 1, n);
		bool ok = 1;
		for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
		for(int i = 1; i <= n; ++i) {
			if(c[b[i]].empty()) {ok = 0; break;}
			int nxt = c[b[i]].front(); c[b[i]].pop_front();
			if(query(1, 1, nxt) != b[i]) {ok = 0; break;}
			modify(1, nxt, inf);
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}