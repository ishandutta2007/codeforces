#include <bits/stdc++.h>
 
const int N = 200054;
 
int n, r;
int p[N], fc[N], nc[N];
int dep[N], size[N], isize[N];
int cnt = 0, o[N], id[N];
int ans[N], prf[N], sef[N], little[N];
int vtop = N, vstack[N];
int root[N], ROOT;
 
inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}
inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x;}
 
namespace ST {
	struct node {int v, lc, rc;} x[2003731 * 4];
 
	int cnt = 0;
 
	int merge(int id1, int id2, int L, int R) {
		if (!(id1 && id2)) return id1 | id2;
		if (L == R) return x[id1].v += x[id2].v, id1;
		int M = (L + R - 1) >> 1;
		x[id1].lc = merge(x[id1].lc, x[id2].lc, L, M);
		x[id1].rc = merge(x[id1].rc, x[id2].rc, M + 1, R);
		return x[id1].v = x[id1].lc[x].v + x[id1].rc[x].v, id1;
	}
 
	int build(int L, int R) {
		int id = ++cnt; x[id] = *x;
		if (L == R) return x[id].v = isize[L], id;
		int M = (L + R - 1) >> 1;
		x[id].lc = build(L, M), x[id].rc = build(M + 1, R);
		return x[id].v = x[id].lc[x].v + x[id].rc[x].v, id;
	}
 
	int add(int id, int L, int R, int h, int v) {
		id || (x[++cnt] = *x, id = cnt), x[id].v += v;
		if (L == R) return id;
		int M = (L + R - 1) >> 1;
		h <= M ? x[id].lc = add(x[id].lc, L, M, h, v) : (x[id].rc = add(x[id].rc, M + 1, R, h, v));
		return id;
	}
 
	int succ(int id1, int id2, int L, int R, int h) {
		int cv = x[id1].v - x[id2].v;
		if (cv <= 0) return INT_MAX;
		if (L == R) return L;
		int M = (L + R - 1) >> 1;
		if (h > M) return succ(x[id1].rc, x[id2].rc, M + 1, R, h);
		int pos = succ(x[id1].lc, x[id2].lc, L, M, h);
		return pos <= M ? pos : succ(x[id1].rc, x[id2].rc, M + 1, R, M + 1);
	}
 
	int pred(int id1, int id2, int L, int R, int h) {
		int cv = x[id1].v - x[id2].v;
		if (cv <= 0) return INT_MIN;
		if (L == R) return L;
		int M = (L + R - 1) >> 1;
		if (h <= M) return pred(x[id1].lc, x[id2].lc, L, M, h);
		int pos = pred(x[id1].rc, x[id2].rc, M + 1, R, h);
		return pos > M ? pos : pred(x[id1].lc, x[id2].lc, L, M, M);
	}
}
 
void dfs(int x) {
	int y, &A = prf[x], &B = sef[x], &C = little[x];
	o[++cnt] = x, id[x] = cnt, size[x] = 1;
	A = B = -1, C = INT_MAX;
	for (y = fc[x]; y; y = nc[y]) {
		dep[y] = dep[x] + 1, dfs(y), size[x] += size[y];
		if (size[y] > A) B = A, A = size[y];
		else up(B, size[y]);
		down(C, size[y]);
	}
	if (x != r) {
		if (n - size[x] > A) B = A, A = n - size[x];
		else up(B, n - size[x]);
		down(C, n - size[x]);
	}
	ans[x] = A;
	++isize[size[x]];
}
 
#define little_gift_is_a_cancer() for (y = fc[x]; y; y = nc[y]) root[x] = ST::merge(root[x], root[y], 1, n); root[x] = ST::add(root[x], 1, n, size[x], 1);
#define little_gift_is_a_big_cancer() for (y = fc[x]; y; y = nc[y]) root[x] = ST::merge(root[x], root[y], 1, n);
 
void solve_all(int x) {
	int s, y, f, lb, ub, *ptr;
	vstack[--vtop] = size[x];
	ROOT = ST::add(ROOT, 1, n, size[x], -1);
	for (y = fc[x]; y; y = nc[y])
		solve_all(y);
	if (prf[x] != sef[x] && ~sef[x]) {
		for (y = fc[x]; y; y = nc[y]) if (size[y] == prf[x]) break;
		// max(x + little, prf[x] - x)
		if (y) {
			assert(size[y] == prf[x]);
			s = prf[x] - little[x], assert(s > 0);
			lb = s / 2, ub = (s + 1) / 2;
			if (ub <= n) {
				f = ST::succ(root[y], 0, 1, n, ub);
				if (f != INT_MAX) down(ans[x], f + little[x]);
			}
			if (lb >= 1) {
				f = ST::pred(root[y], 0, 1, n, lb);
				if (f != INT_MIN) down(ans[x], prf[x] - f);
			}
			little_gift_is_a_cancer();
		} else {
			assert(n - size[x] == prf[x]);
			little_gift_is_a_big_cancer();
			s = prf[x] - little[x], assert(s > 0);
			lb = s / 2, ub = (s + 1) / 2;
			if (ub <= n) {
				f = ST::succ(ROOT, root[x], 1, n, ub);
				if (f != INT_MAX) down(ans[x], f + little[x]);
				ptr = std::lower_bound(vstack + vtop, vstack + N, ub + size[x]);
				if (vstack + vtop <= ptr && ptr < vstack + N)
					down(ans[x], (*ptr - size[x]) + little[x]);
			}
			if (lb >= 1) {
				f = ST::pred(ROOT, root[x], 1, n, lb);
				if (f != INT_MIN) down(ans[x], prf[x] - f);
				ptr = std::upper_bound(vstack + vtop, vstack + N, lb + size[x]) - 1;
				if (vstack + vtop <= ptr && ptr < vstack + N)
					down(ans[x], prf[x] - (*ptr - size[x]));
			}
			root[x] = ST::add(root[x], 1, n, size[x], 1);
		}
	} else {
		little_gift_is_a_cancer();
	}
	ROOT = ST::add(ROOT, 1, n, size[x], 1), ++vtop;
}
 
int main() {
	int i, u, v, root;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%d%d", &u, &v);
		if (u) link(v, u);
		else r = v;
	}
	dfs(r);
	ROOT = ST::build(1, n);
	solve_all(r);
	for (i = 1; i <= n; ++i) up(ans[i], sef[i]), up(ans[i], 0);
	for (i = 1; i <= n; ++i) printf("%d%c", ans[i], i == n ? 10 : 32);
	return 0;
}