#include <bits/stdc++.h>
#define EB emplace_back
using std::vector;

typedef long long ll;
const int N = 200054;

inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

struct rect {
	int t, b, l, r;
	rect (int top = 0, int bottom = 0, int left = 0, int right = 0) : t(top), b(bottom), l(left), r(right) {}
	inline ll area() const {return (ll)max(b - t, 0) * max(r - l, 0);}
	inline rect operator & (const rect &B) const {return rect(max(t, B.t), min(b, B.b), max(l, B.l), min(r, B.r));}
};

typedef std::pair <rect, ll> prl;

int n, last[N];
bool occupied[N];
rect cur[N];
ll ans;
vector <prl> seq[N];

inline void archive(int val, const rect &R) {seq[val].EB(R, seq[val].back().second + R.area());}

inline void insert(int val, const rect &R) {
	if (occupied[val]) {
		if (R.l == cur[val].l && R.r == cur[val].r) return;
		else if (R.l == cur[val].r)
			cur[val].b = R.t, archive(val, cur[val]),
			cur[val] = rect(R.t, R.b, cur[val].l, R.r);
		else throw "internal error !";
	} else cur[val] = R, occupied[val] = true;
}

template <typename condition>
inline int bisect(const vector <prl> &set, condition cond) {return std::partition_point(set.begin(), set.end(), cond) - set.begin();}

ll solve(const vector <prl> &set, int lb, int ub) {
	if (set.size() < 2) return 0;
	int L, R, M; ll ret; rect z(lb, ub, lb, ub);
	L = bisect(set, [lb] (const prl &e) {return e.first.b <= lb || e.first.r <= lb;});
	R = bisect(set, [ub] (const prl &e) {return e.first.t < ub && e.first.l < ub;});
	if (L >= R) return 0;
	if (L + 1 == R) return (set[L].first & z).area();
	ret = set[R - 1].second - set[L - 1].second
		+ (set[L].first & z).area() - set[L].first.area()
		+ (set[R - 1].first & z).area() - set[R - 1].first.area();
	M = min(bisect(set, [lb] (const prl &e) {return e.first.l < lb;}), R - 1);
	if (L + 1 < M)
		assert(set[L + 1].first.l == set[M - 1].first.l),
		ret -= ll(lb - set[L + 1].first.l) * (set[M - 1].first.b - set[L + 1].first.t);
	return ret;
}

int main() {
	int i, j, x, y, l, r, k;
	scanf("%d", &n);
	for (i = 0; i <= n + 1; ++i) seq[i].EB(rect(), 0);
	for (i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &x, &l, &r, &k);
		x = (x + ans) % (n + 1), k = (k + ans) % (n + 1),
		l = (l + ans) % i + 1, r = (r + ans) % i + 1;
		if (l > r) std::swap(l, r);
		if (occupied[x]) {
			int l = cur[x].l, r = cur[x].r;
			cur[x].b = i, archive(x, cur[x]), occupied[x] = false;
			for (y = x + 1; ; ++y)
				if (j = last[y], j < l) {insert(y, rect(i, i, l, r)); break;}
				else if (j < r - 1) insert(y, rect(i, i, j + 1, r)), r = j + 1;
		}
		insert(!x, rect(i, i + 1, i, i + 1)), last[x] = i;
		ans = solve(seq[k], l, r + 1);
		if (occupied[k]) cur[k].b = i + 1, ans += (cur[k] & rect(l, r + 1, l, r + 1)).area();
		printf("%lld\n", ans);
	}
	return 0;
}