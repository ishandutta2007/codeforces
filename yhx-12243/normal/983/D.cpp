#include <bits/stdc++.h>
#define EB emplace_back

typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
typedef std::set <int> set;
const int N = 200054;

struct rect {
	int x1, x2, y1, y2;
	rect * read() {return scanf("%d%d%d%d", &x1, &y1, &x2, &y2), this;}
} r[N];

int n, X, Y;
vector op[N], cl[N];
bool exist[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	struct node {int min, max; set ps;} x[1054000];

	inline void refresh(node &ret) {
		if (!ret.ps.empty()) {int x = *--ret.ps.end(); up(exist[x - 1] ? ret.min : ret.max, x);}
		if (ret.max < ret.min) ret.max = 0;
	}

	inline void update(node &ret, const node &l, const node &r) {ret.min = min(l.min, r.min), ret.max = max(l.max, r.max), refresh(ret);}

	void ins(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {
			x[id].ps.emplace(v); segc;
			return update(x[id], x[lc], x[rc]);
		}
		segc;
		if (ql <= M) ins(lc, L, M, ql, qr, v);
		if (qr > M) ins(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}

	void erase(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {
			x[id].ps.erase(v); segc;
			return update(x[id], x[lc], x[rc]);
		}
		segc;
		if (ql <= M) erase(lc, L, M, ql, qr, v);
		if (qr > M) erase(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}
}

namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0;
		std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

int main() {
	int i, y;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) DC::D[i] = pr(r[i].read()->x1, i), DC::D[i + n] = pr(r[i].x2, i + n);
	X = DC::Discretize(2 * n);
	for (i = 0; i < n; ++i) r[i].x1 = DC::F[i], r[i].x2 = DC::F[i + n], DC::D[i] = pr(r[i].y1, i), DC::D[i + n] = pr(r[i].y2, i + n);
	Y = DC::Discretize(2 * n);
	for (i = 0; i < n; ++i) op[ r[i].y1 = DC::F[i] ].EB(i), cl[ r[i].y2 = DC::F[i + n] ].EB(i);
	for (y = 0; y < Y; ++y) {
		for (int id : op[y]) ST::ins(1, 0, X - 1, r[id].x1, r[id].x2 - 1, id + 1);
		for (int id : cl[y]) ST::erase(1, 0, X - 1, r[id].x1, r[id].x2 - 1, id + 1);
		for (; (i = ST::x[1].max); exist[--i] = true, ST::ins(1, 0, X - 1, r[i].x1, r[i].x2 - 1, i + 1));
	}
	printf("%d\n", 1 + (int)std::count(exist, exist + n, true));
	return 0;
}