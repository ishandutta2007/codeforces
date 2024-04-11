#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::vector <int> vector;
typedef std::set <int> set;
const int N = 200054;

int n, m, x, y;
int a[N], b[N], c[N], d[N];
int perm[N], pos[N];
int stack[N], mat[N];
set cu[N], all;
vector appear[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

void work() {
	int i, j, u, v, w, best = 0, _ = 0, Rm = 0, top = 0;
	cin >> n >> x >> y, y -= x, m = n - x;
	memset(c, 0, (n + 5) << 2), memset(d, 0, (n + 5) << 2);
	for (i = 1; i <= n; ++i) cu[i].clear();
	for (i = 1; i <= n; ++i)
		cin >> a[i], up(Rm, ++c[a[i]]);
	for (i = 1; i <= n + 1; ++i) if (c[i]) cu[c[i]].emplace(i); else _ = i;
	assert(_);
	for (i = 0; i < x; ++i) {
		assert(Rm > 0);
		set::iterator it = --cu[Rm].end();
		j = *it, assert(c[j] == Rm), --c[j], ++d[j];
		//fprintf(stderr, "use %d\n", j);
		cu[Rm].erase(it), cu[c[j]].emplace(j);
		Rm -= cu[Rm].empty();
	}
	//fprintf(stderr, "Rmax = %d, m = %d\n", Rm, m);
	if (y > (m - Rm) * 2) {cout << "NO\n"; return;}
	if (Rm) best = *--cu[Rm].end();
	//fprintf(stderr, "_ = %d, best = %d\n", _, best);
	std::fill(b + 1, b + (n + 1), _);

	for (j = 0, i = 1; i <= n; ++i)
		if (d[a[i]]) b[i] = a[i], --d[a[i]];
		else pos[j++] = i;
	assert(j == m);

	if (Rm * 2 >= m) {
//		fputs("Case #1:\n", stderr);
		std::partition(pos, pos + m, [best] (const int x) {return a[x] == best;});
		for (i = 0, j = m - 1; i < j && y; ++i, --j) {
			b[pos[i]] = a[pos[j]];
			if (!--y) break;
			b[pos[j]] = a[pos[i]];
			if (!--y) break;
		}
	} else {
//		fputs("Case #2:\n", stderr);
		int zz = 0;
		all.clear();
		for (i = 1; i <= n; ++i) if (!cu[i].empty()) all.emplace(i);
		for (i = 0; i < m / 2; ++i) {
			//fprintf(stderr, "Rm = %d (%d)\n", Rm, (int)cu[Rm].size());
			if (cu[Rm].size() > 1u) {
			//	fprintf(stderr, " (%d)\n", (int)cu[Rm].size());
				set::iterator it = --cu[Rm].end(), jt = it--;
				perm[zz++] = u = *it, perm[zz++] = v = *jt;
				cu[Rm].erase(it), cu[Rm].erase(jt);
				cu[--c[u]].emplace(u), cu[--c[v]].emplace(v);
				all.emplace(c[u]), all.emplace(c[v]);
			} else {
				int uu = *all.begin();
			//	fprintf(stderr, "make uu = %d\n", uu);
				assert(uu != Rm);
				set::iterator it = --cu[Rm].end(), jt = --cu[uu].end();
				perm[zz++] = u = *it, perm[zz++] = v = *jt;
				cu[Rm].erase(it), cu[uu].erase(jt);
				cu[--c[u]].emplace(u), cu[--c[v]].emplace(v);
				all.emplace(c[u]), all.emplace(c[v]);
				if (cu[uu].empty()) all.erase(uu);
			}
			if (cu[Rm].empty()) all.erase(Rm--);
			all.erase(0);
		}
		for (i = 0; i < m; ++i) appear[a[pos[i]]].emplace_back(pos[i]), mat[ pos[i] ] = -1;
		zz = 0;
		for (i = 0; i < m / 2; ++i) {
			u = perm[zz++], v = perm[zz++];
		//	fprintf(stderr, "%d : %d <-> %d\n", i, u, v);
			mat[ appear[u].back() ] = appear[v].back();
			mat[ appear[v].back() ] = appear[u].back();
			appear[u].pop_back(), appear[v].pop_back();
		}
		if (m & 1) {
			for (i = 0; i < m && ~mat[pos[i]]; ++i);
			w = pos[i];
			for (i = 0; i < m; ++i) {
				u = pos[i], v = mat[u];
				if (a[u] == a[w] || a[v] == a[w] || !~v) continue;
				mat[u] = v, mat[v] = w, mat[w] = u; break;
			}
		}
		for (i = 1; i <= n + 1; ++i) appear[i].clear();
		for (i = 0; i < y; ++i) b[pos[i]] = a[mat[pos[i]]];
	}
	cout << "YES\n";
	for (i = 1; i <= n; ++i) cout << b[i] << (i == n ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}