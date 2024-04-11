#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef std::pair <int, int> pr;
const int N = 2054;

int n;
int d[N][N];
vector <pr> G;

inline void query(int x) {
	cout << '?' << ' ' << x << endl;
	for (int i = 1; i <= n; ++i) cin >> d[x][i];
}

int main() {
	int i, j, r, w[2] = {0};
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n, query(1);
	for (i = 2; i <= n; ++i) ++w[d[1][i] & 1];
	r = *w <= w[1];
	for (i = 2; i <= n; ++i) if ((d[1][i] ^ r) & 1) query(i);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j) if (d[i][j] == 1) G.EB(std::minmax(i, j));
	std::sort(G.begin(), G.end()), G.erase(std::unique(G.begin(), G.end()), G.end());
	assert((int)G.size() == n - 1);
	cout << '!' << '\n';
	for (const pr &e : G) cout << e.first << ' ' << e.second << '\n';
	return 0;
}