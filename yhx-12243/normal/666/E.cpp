#include <bits/stdc++.h>
#define EB emplace_back

typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 500054, M = 1111111, LN = 21;

int n, q;
char s[M];
int at[M], root[M];
pr qry[N], ans[N];
vector qs[M];

inline bool up(pr &x, const pr &y) {return x < y ? x = y, 1 : 0;}

namespace SAM {
	int p, np = 1, cnt = 1;
	int P[LN][M];
	int *pa = *P, d[M][26], val[M];
	int pos[M], child[M][26];
	bool used[M];

	#define q d[p][x]
	#define try_split(v) { \
		if (val[p] + 1 == val[q]) v = q; \
		else { \
			int nq = ++cnt; \
			val[nq] = val[p] + 1, memcpy(d[nq], d[q], 104); \
			pa[nq] = pa[q], v = pa[q] = nq; \
			for (int Q = q; p && q == Q; q = nq, p = pa[p]); \
		} \
	}

	int extend(int x) {
		if (p = np, q) try_split(np)
		else {
			for (val[np = ++cnt] = val[p] + 1; p && !q; q = np, p = pa[p]);
			if (p) try_split(pa[np]) else pa[np] = 1;
		}
		return np;
	}
	#undef q

	void dfs(int x) {
		int i, y;
		for (i = 0; i < LN - 1 && P[i][x]; ++i)
			P[i + 1][x] = P[i][P[i][x]];
		for (i = 0; i < 26; ++i)
			if (y = child[x][i]) dfs(y);
	}

	void build() {
		int i, j, c; used[1] = true;
		for (i = cnt; i; --i) if (~pos[i])
			for (j = i; !used[j]; j = pa[j])
				c = pos[j] - val[pa[j]], pos[pa[j]] = pos[j],
				child[pa[j]][int(s[c])] = j, used[j] = true;
		dfs(1);
	}

	int jump_until(int x, int v) {for (int i = LN - 1; i >= 0; --i) val[ P[i][x] ] >= v && (x = P[i][x]); return x;}
	inline int extract(int l, int r) {return jump_until(at[r], r - l + 1);} // [l, r]
}

namespace ST {
	struct node {pr v; int lc, rc;} x[20030731];
	int cnt;

	int add(int id, int L, int R, int h, int v) {
		id || (id = ++cnt);
		if (L == R) return ++x[id].v.first, x[id].v.second = h, id;
		int M = (L + R - 1) >> 1;
		h <= M ? x[id].lc = add(x[id].lc, L, M, h, v) : (x[id].rc = add(x[id].rc, M + 1, R, h, v));
		return x[id].v = std::max(x[id].lc[x].v, x[id].rc[x].v), id;
	}

	int merge(int id1, int id2, int L, int R) {
		if (!(id1 && id2)) return id1 | id2;
		if (L == R) return x[id1].v.first += x[id2].v.first, id1;
		int M = (L + R - 1) >> 1;
		x[id1].lc = merge(x[id1].lc, x[id2].lc, L, M);
		x[id1].rc = merge(x[id1].rc, x[id2].rc, M + 1, R);
		return x[id1].v = std::max(x[id1].lc[x].v, x[id1].rc[x].v), id1;
	}

	pr range(int id, int L, int R, int ql, int qr) {
		if (!id) return pr(0, qr);
		if (ql <= L && R <= qr) return x[id].v;
		int M = (L + R - 1) >> 1; pr s(-1, -1);
		if (ql <= M) up(s, range(x[id].lc, L, M, ql, qr));
		if (qr > M) up(s, range(x[id].rc, M + 1, R, ql, qr));
		return s;
	}
}

void solve(int x) {
	int i, y;
	for (i = 0; i < 26; ++i)
		if (y = SAM::child[x][i])
			solve(y), root[x] = ST::merge(root[x], root[y], 1, n);
	for (int id : qs[x]) ans[id] = ST::range(root[x], 1, n, qry[id].first, qry[id].second);
}

int main() {
	int i, v, pl, pr, l, r; char *p;
	memset(SAM::pos, -1, sizeof SAM::pos);
	scanf("%s%d", s, &n);
	for (p = s; *p; ++p) at[p - s] = SAM::extend(*p -= 97), SAM::pos[ at[p - s] ] = p - s;
	for (i = 0; i < n; ++i)
		for (SAM::np = 1, scanf("%s", p); *p; ++p)
			v = SAM::extend(*p -= 97), SAM::pos[v] = p - s,
			root[v] = ST::add(root[v], 1, n, n - i, 1);
	SAM::build();
	scanf("%d", &q);
	for (i = 0; i < q; ++i)
		scanf("%d%d%d%d", &l, &r, &pl, &pr), qry[i] = ::pr(n - r + 1, n - l + 1),
		v = SAM::extract(--pl, --pr), qs[v].EB(i);
	solve(1);
	for (i = 0; i < q; ++i) printf("%d %d\n", n - ans[i].second + 1, ans[i].first);
	return 0;
}