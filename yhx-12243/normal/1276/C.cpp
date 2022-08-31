#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 400054;

int n, m, R, C;
vector map[N];
std::map <int, int> count;
pr a[N];

inline bool up(int &x, const int y) {return x < y ? x = y, 1 : 0;}

int main() {
	int i, j = 0, k, x, sum = 0, total, best = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &x), ++count[x];
	for (const pr &s : count) a[m++] = pr(s.second, s.first);
	std::sort(a, a + m);
	for (i = 1; i * i <= n; ++i) {
		for (; j < m && a[j].first <= i; ++j) sum += a[j].first;
		total = sum + i * (m - j);
		if (total >= i * i && up(best, total / i * i))
			R = i;
	}
	C = best / R, assert(best == R * C);
	printf("%d\n%d %d\n", best, R, C);
	for (i = 0; i < m; ++i) if (a[i].first > R) a[i].first = R;
	for (x = k = 0, i = m - 1; i >= 0 && x < best; --i)
		for (j = 0; j < a[i].first && x < best; ++j)
			map[k].EB(a[i].second), ++k == R ? k = 0 : 0, ++x;
	assert(x == best);
	for (i = 0; i < R; ++i) {
		assert((int)map[i].size() == C);
		std::rotate(map[i].begin(), map[i].end() - i, map[i].end());
		for (j = 0; j < C; ++j)
			printf("%d%c", map[i][j], j == C - 1 ? 10 : 32);
	}
	return 0;
}
/*
A B C D E F G H
1 1 1 1 1 2 2 3

01234
aaaaa
bbbbc
cccdd
ddeee
effff
*/