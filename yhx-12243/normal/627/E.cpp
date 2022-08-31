#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef std::vector <int> vector;
typedef std::multiset <int> set;
const int N = 3054;

int R, C, n, inf;
int fy_[54], *col = fy_ + 27;
vector row[N];
set U;

int main() {
	int i, u, r, c, cur; ll ans = 0; set::iterator le, ri;
	scanf("%d%d%d%d", &R, &C, &n, &inf);
	for (i = 0; i < n; ++i) scanf("%d%d", &r, &c), row[r].EB(c);
	for (u = 1; u <= R; ++u)
		for (U.clear(), cur = 0, r = u; r <= R; ++r, ans += cur)
			for (int c : row[r]) {
				++(ri = le = U.emplace(*col = c));
				for (i = 1; i <= inf; ++i) col[-i] = (le == U.begin() ? 0 : *--le), col[i] = (ri == U.end() ? C + 1 : *ri++);
				for (i = 1; i <= inf; ++i) cur += (col[i] - col[i - 1]) * (col[i - inf] - col[i - inf - 1]);
			}
	printf("%lld\n", ans);
	return 0;
}