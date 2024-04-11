#include <bits/stdc++.h>
#define EB emplace_back

typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 500054;

int n, q;
char s[N];
int at[N], root[N], ans[N];
pr qry[N];
vector qs[N];

inline bool up(pr &x, const pr &y) {return x < y ? x = y, 1 : 0;}

namespace SAM {
	const int N = 400054;
	int p, np, cnt = 1;
	int pa[N], d[N][26], val[N];
	int pos[N], child[N][26];
	bool used[N];

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

	void build() {
		int i, j, c; used[1] = true;
		for (i = cnt; i; --i) if (~pos[i])
			for (j = i; !used[j]; j = pa[j])
				c = pos[j] - val[pa[j]], pos[pa[j]] = pos[j],
				child[pa[j]][int(s[c])] = j, used[j] = true;
	}
}

namespace ST {
	struct node {int v, lc, rc;} x[5000054];
	int cnt;

	int add(int id, int L, int R, int h, int v) {
		id || (id = ++cnt);
		if (L == R) return x[id].v += v, id;
		int M = (L + R - 1) >> 1;
		h <= M ? x[id].lc = add(x[id].lc, L, M, h, v) : (x[id].rc = add(x[id].rc, M + 1, R, h, v));
		return x[id].v = x[id].lc[x].v + x[id].rc[x].v, id;
	}

	int merge(int id1, int id2, int L, int R) {
		if (!(id1 && id2)) return id1 | id2;
		if (L == R) return x[id1].v += x[id2].v, id1;
		int M = (L + R - 1) >> 1;
		x[id1].lc = merge(x[id1].lc, x[id2].lc, L, M);
		x[id1].rc = merge(x[id1].rc, x[id2].rc, M + 1, R);
		return x[id1].v = x[id1].lc[x].v + x[id1].rc[x].v, id1;
	}

	int range(int id, int L, int R, int ql, int qr) {
		if (!id || (ql <= L && R <= qr)) return x[id].v;
		int M = (L + R - 1) >> 1, s = 0;
		if (ql <= M) s += range(x[id].lc, L, M, ql, qr);
		if (qr > M) s += range(x[id].rc, M + 1, R, ql, qr);
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
	int i, v = 0, l, r, k; char *p = s;
	memset(SAM::pos, -1, sizeof SAM::pos);
	scanf("%d%d", &n, &q);
	for (i = 0; i < n; ++i) {
		for (SAM::np = 1, scanf("%s", p); *p; ++p)
			v = SAM::extend(*p -= 97), SAM::pos[v] = p - s,
			root[v] = ST::add(root[v], 1, n, i + 1, 1);
		at[i] = v;
	}
	SAM::build();
	for (i = 0; i < q; ++i)
		scanf("%d%d%d", &l, &r, &k), qry[i] = pr(l, r), qs[at[--k]].EB(i);
	solve(1);
	for (i = 0; i < q; ++i) printf("%d\n", ans[i]);
	return 0;
}