#include <bits/stdc++.h>

const int N = 200054;

int n, m, q;
int root[N], chg[N];
char s[N], si[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace ST {
	struct node {int v, lc, rc;} x[20030731];
	int cnt = 0;

	int add(int id, int L, int R, int h, int v) {
		int nid = ++cnt; x[nid] = x[id];
		if (L == R) return x[nid].v += v, nid;
		int M = (L + R - 1) >> 1;
		h <= M ? x[nid].lc = add(x[id].lc, L, M, h, v) : (x[nid].rc = add(x[id].rc, M + 1, R, h, v));
		return x[nid].v = x[nid].lc[x].v + x[nid].rc[x].v, nid;
	}

	bool range(int id1, int id2, int L, int R, int ql, int qr) {
		if (!id2) return false;
		if (ql <= L && R <= qr) return x[id1].v < x[id2].v;
		int M = (L + R - 1) >> 1;
		return (ql <= M && range(x[id1].lc, x[id2].lc, L, M, ql, qr))
			|| (qr > M && range(x[id1].rc, x[id2].rc, M + 1, R, ql, qr));
	}
}

namespace SAM {
	int p, np = 1, cnt = 1;
	int pa[N], d[N][26], val[N];
	int pos[N], rgt[N], child[N][26];
	int dfn = 0, o[N], id[N], eid[N];
	bool used[N];

	#define q d[p][x]
	int extend(int x) {
		for (p = np, val[np = ++cnt] = val[p] + 1; p && !q; q = np, p = pa[p]);
		if (!p) pa[np] = 1;
		else if (val[p] + 1 == val[q]) pa[np] = q;
		else {
			int nq = ++cnt;
			val[nq] = val[p] + 1, memcpy(d[nq], d[q], 104);
			pa[nq] = pa[q], pa[np] = pa[q] = nq;
			for (int Q = q; p && q == Q; q = nq, p = pa[p]);
		}
		return np;
	}
	#undef q

	void dfs(int x) {
		int i, y;
		o[++dfn] = x, id[x] = dfn;
		for (i = 0; i < 26; ++i) if ((y = child[x][i])) dfs(y);
		eid[x] = dfn;
	}

	void build() {
		int i, j, c; used[1] = true;
		memcpy(pos, rgt, sizeof pos);
		for (i = cnt; i; --i) if (~pos[i])
			for (j = i; !used[j]; j = pa[j])
				c = pos[j] - val[pa[j]], pos[pa[j]] = pos[j],
				child[pa[j]][int(s[c])] = j, used[j] = true;
		dfs(1);
		for (i = 1; i <= cnt; ++i)
			c = rgt[o[i]], root[i] = (~c ? ST::add(root[i - 1], 0, n - 1, c, 1) : root[i - 1]);
	}
}

int main() {
	int i, j, l, r, id, t, nt;
	using SAM::rgt; memset(rgt, -1, sizeof rgt);
	scanf("%s%d", s, &q), n = strlen(s);
	for (i = 0; i < n; ++i) rgt[SAM::extend(s[i] -= 97)] = i;
	SAM::build();
	for (; q; --q) {
		scanf("%d%d%s", &l, &r, si), m = strlen(si), si[m++] = 96,
		down(m, r-- - --l), memset(chg, -1, (m + 1) << 2), t = 1;
		for (i = 0; i < m; ++i) {
			id = si[i] - 97;
			for (j = id + 1; j < 26; ++j)
				if ((nt = SAM::d[t][j]) && ST::range(root[SAM::id[nt] - 1], root[SAM::eid[nt]], 0, n - 1, l + i, r)) {
					chg[i] = j; break;
				}
			if (~id && (nt = SAM::d[t][id]) && ST::range(root[SAM::id[nt] - 1], root[SAM::eid[nt]], 0, n - 1, l + i, r)) t = nt;
			else break;
		}
		for (; i >= 0 && !~chg[i]; --i);
		puts(~i ? (si[i] = chg[i] + 97, si[i + 1] = 0, si) : "-1");
	}
	return 0;
}