#include <bits/stdc++.h>
#define ctz __builtin_ctz

typedef std::pair <int, int> pr;
const int N = 200054, pw10[6] = {1, 10, 100, 1000, 10000, 100000};

int n, l, ALL;
int count[6][6], mov[6];
int weight[6], unlock = 1;

namespace O {
	int E = 0;
	pr e[N];

	inline void add(int x, int y) {e[E++] = std::minmax(x, y);}

	inline bool ok() {return E == n - 1;}

	int print() {
		std::sort(e, e + E);
		for (int i = 0; i < E; ++i) printf("%d %d\n", e[i].first, e[i].second);
		return 0;
	}
}

inline int Log(const int x) {return std::upper_bound(pw10, pw10 + 6, x) - pw10 - 1;}

inline bool Hall() {
	int u, v, S, $S, $T;
	for (S = 1; S < ALL; ++S) {
		$S = $T = 0;
		for (u = S; u; u &= u - 1) $S += weight[ctz(u)];
		for (u = 0; u < l; ++u)
			for (v = u + 1; v <= l; ++v)
				if ((S >> u | S >> v) & 1) $T += count[u][v];
		if ($T < $S) return false;
	}
	return true;
}

int ddl[6][6];

int main() {
	int i, j, u, v; char $1[8], $2[8];
	scanf("%d", &n), l = Log(n), ALL = ~(-2 << l);
	for (i = 1; i < n; ++i)
		scanf("%s%s", $1, $2), u = strlen($1) - 1, v = strlen($2) - 1,
		++count[u][v], ++count[v][u];
	memcpy(ddl, count, sizeof ddl);
	for (i = 0; i < l; ++i) weight[i] = pw10[i + 1] - pw10[i];
	weight[i] = n - pw10[i] + 1;
	for (i = 0; i <= l; ++i) {
		for (j = count[i][i] / 2; j; --j, --weight[i])
			O::add(pw10[i] + weight[i] - 2, pw10[i] + weight[i] - 1);
		if (count[i][i] = 0, weight[i] <= 0) return puts("-1"), 0;
	}
	if (!Hall()) return puts("-1"), 0;
	memcpy(mov, pw10, (l + 1) << 2);
	for (--*weight, ++*mov; !O::ok(); )
		for (v = unlock; v; v &= v - 1)
			for (i = ctz(v), j = 0; j <= l; ++j) if (count[i][j] && weight[j]) {
				if (clock() > 6 * CLOCKS_PER_SEC) {
					for (i = 0; i <= l; ++i)
						for (j = 0; j <= i; ++j)
							printf("%d%c", ddl[i][j], j==i?10:32);
					return 0;
				}
				--count[i][j], --count[j][i], --weight[j];
				if (Hall()) {O::add(pw10[i], mov[j]++), unlock |= 1 << j; continue;}
				++count[i][j], ++count[j][i], ++weight[j];
			}
	return O::print(), 0;
}