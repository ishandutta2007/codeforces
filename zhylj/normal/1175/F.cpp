#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 3e5 + 5, INF = 0x3f3f3f3f;

#define mn(o) tr[o].mn
#define mn_cnt(o) tr[o].mn_cnt
#define tag(o) tr[o].tag
struct Seg {
	int mn, mn_cnt, tag;
	Seg() { mn = INF; mn_cnt = tag = 0; }
} tr[N << 3];
void Upd(int o) {
	mn(o) = std::min(mn(o << 1), mn(o << 1 | 1));
	mn_cnt(o) = 0;
	if(mn(o) == mn(o << 1)) mn_cnt(o) += mn_cnt(o << 1);
	if(mn(o) == mn(o << 1 | 1)) mn_cnt(o) += mn_cnt(o << 1 | 1);
}
void PushTag(int o) {
	if(tag(o)) {
		mn(o << 1) += tag(o);
		mn(o << 1 | 1) += tag(o);
		tag(o << 1) += tag(o);
		tag(o << 1 | 1) += tag(o);
		tag(o) = 0;
	}
}
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid);
		Build(o << 1 | 1, mid + 1, r);
		Upd(o);
	} else mn(o) = l, mn_cnt(o) = 1;
}
void Modify(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) tag(o) += v, mn(o) += v;
	else {
		PushTag(o);
		int mid = (l + r) >> 1;
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
		Upd(o);
	}
}
int Query(int o, int l, int r, int ql, int qr, int x) {
	if(ql <= l && r <= qr) return mn(o) == x ? mn_cnt(o) : 0;
	else {
		int mid = (l + r) >> 1, ret = 0;
		PushTag(o);
		if(ql <= mid) ret += Query(o << 1, l, mid, ql, qr, x);
		if(qr > mid) ret += Query(o << 1 | 1, mid + 1, r, ql, qr, x);
		return ret;
	}
}
int Get(int o, int l, int r, int x) {
	if(l == r) return mn(o);
	int mid = (l + r) >> 1;
	PushTag(o);
	if(x <= mid) return Get(o << 1, l, mid, x);
	else return Get(o << 1 | 1, mid + 1, r, x);
}

int n, a[N], st_g[N], st_l[N], lst[N], lst_buk[N], top_g, top_l;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		Build(1, 1, n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			lst[i] = lst_buk[a[i]];
			lst_buk[a[i]] = i;
		}
		ll ans = 0;
		for(int i = 1, cur_l = 0; i <= n; ++i) {
			cur_l = std::max(cur_l, lst[i]);
			//Modify(1, 1, n, st_g[top_g] + 1, i, a[i]);
			while(top_g > 0 && a[st_g[top_g]] <= a[i]) {
				Modify(1, 1, n, st_g[top_g - 1] + 1, st_g[top_g], a[i] - a[st_g[top_g]]);
				--top_g;
			}
			st_g[++top_g] = i;
			//Modify(1, 1, n, st_l[top_l] + 1, i, -a[i]);
			while(top_l > 0 && a[st_l[top_l]] >= a[i]) {
				Modify(1, 1, n, st_l[top_l - 1] + 1, st_l[top_l], -a[i] + a[st_l[top_l]]);
				--top_l;
			}
			st_l[++top_l] = i;
			if(a[st_l[1]] == 1) {
				//printf("Q: %d %d %d\n", cur_l, st_l[1], i);
				if(cur_l < st_l[1]) ans += Query(1, 1, n, cur_l + 1, st_l[1], i);
				//printf("mn_cnt = %d %d\n", mn_cnt(1), mn(1));
			}
			/*for(int j = 1; j <= n; ++j)
				printf("%d ", Get(1, 1, n, j));
			printf("\n");*/
		}
		printf("%lld\n", ans);
	} return 0;
}