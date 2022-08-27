#include <bits/stdc++.h>
#define EB emplace_back

const int N = 200054;

int n, m, S, M, W;
char s[N], b[N];
int pos[N], cc[26], cu[N];
int stack[N];
int cnt, al[N], ar[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	struct node {int v, tag;} x[N * 3];

	inline void cover(node &ret) {ret.v = 0, ret.tag = 1;}

	inline void push_down(node &ret, node &l, node &r) {if (ret.tag) cover(l), cover(r);}

	void build(int id, int L, int R) {
		x[id].v = R - L + 1, x[id].tag = 0;
		if (L == R) return;
		segc; build(lc, L, M), build(rc, M + 1, R);
	}

	void clear(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return cover(x[id]);
		segc; push_down(x[id], x[lc], x[rc]);
		if (ql <= M) clear(lc, L, M, ql, qr);
		if (qr > M) clear(rc, M + 1, R, ql, qr);
		x[id].v = x[lc].v + x[rc].v;
	}

	int range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id].v;
		segc, s = 0;
		if (ql <= M) s += range(lc, L, M, ql, qr);
		if (qr > M) s += range(rc, M + 1, R, ql, qr);
		return s;
	}

	void Do(int l, int r) {
		int lp = (l ? ST::range(1, 0, n - 1, 0, l - 1) + 1 : 1), rp = ST::range(1, 0, n - 1, 0, r);
		assert(lp <= rp), printf("%d %d\n", lp, rp);
		ST::clear(1, 0, n - 1, l, r);
	}
}

inline void add(int x) {--cu[cc[x]], ++cu[++cc[x]], ++S, up(M, cc[x]), W = S - 2 * M;}
inline void del(int x) {--cu[cc[x]], ++cu[--cc[x]], --S, M -= !cu[M],  W = S - 2 * M;}

inline bool check(int l, int r) {
	if (b[l] == b[r]) return false; int oW = W;
	return del(b[l]), del(b[r]), W >= min(oW, -1) || (add(b[l]), add(b[r]), false);
}

void work() {
	int i, top = 0;
	scanf("%s", s), n = strlen(s), m = cnt = 0, memset(cc, 0, 104);
	for (i = 1; i < n; ++i)
		if (s[i - 1] == s[i]) ++cc[ b[m] = s[i] - 97 ], pos[m++] = i;
	for (S = M = i = 0; i < 26; ++i) S += cc[i], up(M, cc[i]), ++cu[cc[i]];
	printf("%d\n", max(-~S / 2, M) + 1), W = S - 2 * M;
	for (i = 0; i < m; ++i)
		if (top && check(stack[top - 1], i)) al[cnt] = stack[--top][pos], ar[cnt++] = pos[i] - 1;
		else stack[top++] = i;
	for (; top; al[cnt] = stack[--top][pos], ar[cnt++] = n - 1);
	al[cnt] = 0, ar[cnt++] = n - 1;
	ST::build(1, 0, n - 1);
	for (i = 0; i < cnt; ++i) ST::Do(al[i], ar[i]);
	for (i = 0; i < 26; ++i) cu[cc[i]] = 0;
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}