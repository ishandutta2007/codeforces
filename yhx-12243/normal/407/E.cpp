#include <bits/stdc++.h>

typedef std::pair <int, int> pr;
typedef std::map <int, int> map;
const int N = 200054;

int n, K, d;
int a[N], r[N];
int stack1[N], stack2[N];
map M;

inline bool cmp(const pr &a, const pr &b) {return a.second - a.first < b.second - b.first || (a.second - a.first == b.second - b.first && a.first > b.first);}

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void up(pr &x, const pr y) {cmp(x, y) ? x = y, 1 : 0;}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	struct node {int v, tag;} x[N * 4];

	void build(int id, int L, int R) {
		x[id].v = L, x[id].tag = 0;
		if (L == R) return;
		segc; build(lc, L, M), build(rc, M + 1, R);
	}

	void add(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {x[id].v += v, x[id].tag += v; return;}
		segc;
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		x[id].v = std::min(x[lc].v, x[rc].v) + x[id].tag;
	}

	int find_suf(int id, int L, int R, int h, int v, int cv = 0) {
		if (cv + x[id].v > v) return -1;
		if (L == R) return L;
		segc, p; cv += x[id].tag;
		if (h > M) return find_suf(rc, M + 1, R, h, v, cv);
		p = find_suf(lc, L, M, h, v, cv);
		return ~p ? p : find_suf(rc, M + 1, R, M + 1, v, cv);
	}
}

// max[l, r] - min[l, r] + l <= r + k
pr solve(int L, int R) {
	int l, r, top1 = 0, top2 = 0, curL = L; pr ret(L, L);
	map::iterator it; M.clear(), ST::build(1, L, R);
	*stack1 = *stack2 = L - 1;
	for (r = L; r <= R; ++r) {
		if ((it = M.find(a[r])) == M.end()) M.emplace(a[r], r);
		else up(curL, it->second + 1), it->second = r;
		for (; top1 && a[r] > a[stack1[top1]]; --top1)
			ST::add(1, L, R, stack1[top1 - 1] + 1, stack1[top1], a[r] - a[stack1[top1]]);
		for (; top2 && a[r] < a[stack2[top2]]; --top2)
			ST::add(1, L, R, stack2[top2 - 1] + 1, stack2[top2], a[stack2[top2]] - a[r]);
		stack1[++top1] = stack2[++top2] = r;
		l = ST::find_suf(1, L, R, curL, r + K);
		if (~l) up(ret, pr(l, r));
	}
	return ret;
}

int main() {
	int i, j; div_t t; pr ans(1, 1);
	scanf("%d%d%d", &n, &K, &d);
	for (i = 1; i <= n; ++i) scanf("%d", a + i); r[n + 1] = a[n + 1] = INT_MAX;
	if (!d) {
		for (j = i = 1; i <= n; ++i) if (a[i + 1] != a[j]) up(ans, pr(j, i)), j = i + 1;
		return printf("%d %d\n", ans.first, ans.second), 0;
	}
	for (i = 1; i <= n; ++i) t = div(a[i], d), r[i] = t.rem + (t.rem >> 31 & d), a[i] = t.quot + (t.rem >> 31);
	for (j = i = 1; i <= n; ++i) if (r[i + 1] != r[j]) up(ans, solve(j, i)), j = i + 1;
	return printf("%d %d\n", ans.first, ans.second), 0;
}