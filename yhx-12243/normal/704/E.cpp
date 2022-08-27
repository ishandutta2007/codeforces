#include <bits/stdc++.h>
#define EB emplace_back
using std::vector;

typedef std::pair <int, int> pr;
const int N = 100054, M = N * 2;

struct event {
	double x1, y1, x2, y2;
	event (double x1_ = 0., double y1_ = 0., double x2_ = 0., double y2_ = 0.) : x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}
};

int n, q, E = 0;
int to[M], first[N], next[M];
int p[N], dep[N], size[N];
int cnt = 0, id[N], prf[N], top[N];
int qTime[N], qVelo[N], qOrig[N], qDest[N];
vector <event> es[N];

inline bool down(double &x, const double y) {return x > y ? x = y, 1 : 0;}
inline bool down(long double &x, const long double y) {return x > y ? x = y, 1 : 0;}
inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}
inline int dmax(const int x, const int y) {return dep[x] < dep[y] ? y : x;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs_wt(int x) {
	int i, y, &z = prf[x]; size[x] = !next[first[x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x, dep[y] = dep[x] + 1;
			dfs_wt(y), size[x] += size[y];
			size[y] > size[z] ? z = y : 0;
		}
}

void dfs_hld(int x, int r) {
	int i, y; id[x] = ++cnt, top[x] = r;
	if (!prf[x]) return;
	dfs_hld(prf[x], r);
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]]) dfs_hld(y, y);
}

void decomposition(int u, int v, int time, int velo) {
	static pr buf[N], rev[N];
	int x = top[u], y = top[v], z, c = 0, d = 0, i, next_time; time *= velo;
	for (; x != y; dep[x] > dep[y] ? (buf[c++] = pr(u, p[x]), u = p[x], x = top[u]) : (rev[d++] = pr(p[y], v), v = p[y], y = top[v]));
	buf[c++] = pr(u, v);
	c = std::reverse_copy(rev, rev + d, buf + c) - buf;
	for (i = 0; i < c; ++i) {
		std::tie(x, y) = buf[i], z = dmax(top[x], top[y]);
		next_time = time + abs(dep[x] - dep[y]);
		es[z].EB((double)time / velo, dep[x] - dep[z], (double)next_time / velo, dep[y] - dep[z]);
		time = next_time;
 	}
}

namespace G {	
	typedef bool (*cmpFn)(const int &, const int &);

	struct sweepLine {
		double x; int id;
		sweepLine (double x_ = 0., int id_ = 0) : x(x_), id(id_) {}
		inline bool operator < (const sweepLine &B) const {return x < B.x || (x == B.x && id > B.id);}
	} sl[2003731 * 2]; 

	int E, cnt;
	double X;
	event e[2003731];

	inline double getY(int id, double x0) {
		if (id == -1) return INFINITY;
		if (id == -2) return -INFINITY;
		if (e[id].x1 == e[id].x2) return e[id].y1;
		return (e[id].x1 * e[id].y2 - e[id].x2 * e[id].y1 + x0 * (e[id].y1 - e[id].y2)) / (e[id].x1 - e[id].x2);
	}

	inline double interX(const event &p, const event &q) {
		double a = p.x1 - p.x2, b = q.x1 - q.x2, D = a * (q.y1 - q.y2) - b * (p.y1 - p.y2), N = b * (p.x1 * p.y2 - p.x2 * p.y1) - a * (q.x1 * q.y2 - q.x2 * q.y1);
		return fabs(D) < 7e-14 ? (fabs(N) < 1e-19 ? std::max(p.x1, q.x1) : INFINITY) : N / D;
	}
	
	inline bool slCmp(const int &x, const int &y) {return getY(x, X) < getY(y, X);}

	std::set <int, cmpFn> s(slCmp);

	double main(int heavy_chain) {
		int i, j;
		double xi, time_limit = INFINITY;
		E = std::copy(es[heavy_chain].begin(), es[heavy_chain].end(), e) - e;
		for (cnt = i = 0; i < E; ++i) sl[cnt++] = sweepLine(e[i].x1, i), sl[cnt++] = sweepLine(e[i].x2, ~i);
		std::sort(sl, sl + cnt);
		s.emplace(-2), s.emplace(-1);
		for (j = 0; j < cnt; ++j) {
			X = sl[j].x, i = sl[j].id;
			if (X > time_limit - 1e-8) break;
			if (i >> 31) s.erase(~i);
			else {
				auto it = s.lower_bound(i);
				if (~*it >> 31) {
					xi = interX(e[i], e[*it]);
					if (X - 1e-8 < xi && xi < std::min(e[i].x2, e[*it].x2) + 1e-8 && fabs(getY(i, xi) - getY(*it, xi)) < 1e-8)
						down(time_limit, xi);
				}
				if (it != s.begin() && ~*--it >> 31) {
					xi = interX(e[i], e[*it]);
					if (X - 1e-8 < xi && xi < std::min(e[i].x2, e[*it].x2) + 1e-8 && fabs(getY(i, xi) - getY(*it, xi)) < 1e-8)
						down(time_limit, xi);
				}
				s.emplace_hint(it, i);
			}
		}
		return s.clear(), time_limit;
	}
}

int main() {
	int i, u, v; double ans = INFINITY;
	scanf("%d%d", &n, &q);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs_wt(1), dfs_hld(1, 1);
	for (i = 0; i < q; ++i) scanf("%d%d%d%d", qTime + i, qVelo + i, qOrig + i, qDest + i), decomposition(qOrig[i], qDest[i], qTime[i], qVelo[i]);
	for (i = 1; i <= n; ++i) if (top[i] == i) down(ans, G::main(i));
	printf("%.12lg\n", std::isfinite(ans) ? ans : -1.);
	return 0;
}