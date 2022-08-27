#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 108, N2 = 5400;

enum type {invalid, conjunct, disjunct};

struct path {
	type S; pr last;
	path () {}
	path (type S_, pr la_) : S(S_), last(la_) {}
} f[N][N2];

int C2[N], last[N2];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

void init() {
	int i, j, k;
	for (i = 1; i < 107; ++i) C2[i + 1] = C2[i] + i;
	f[1][0] = path(conjunct, {0, 0}),
	f[2][1] = path(conjunct, {1, 0}),
	f[3][2] = path(conjunct, {2, 1}),
	f[3][3] = path(conjunct, {1, 0}),
	last[1] = 2, last[2] = last[3] = 3;
	for (i = 4; i <= 100; ++i) {
		f[i][1] = path(disjunct, {1, 0}), f[i][C2[i]] = path(conjunct, {1, 0});
		// disjunct
		for (j = 2; j < C2[i]; ++j)
			if (last[j - 1] && last[j - 1] < i - 2)
				f[i][j] = path(disjunct, {last[j - 1], j - 1});
		// conjunct
		for (j = 2; j < C2[i]; ++j) if (f[i][j].S == invalid)
			for (k = 1; k < i && C2[k + 1] < j; ++k)
				if (f[i - k][j - C2[k + 1]].S != invalid) {
					f[i][j] = path(conjunct, {i - k, j - C2[k + 1]});
					break;
				}
		for (j = 1; j <= C2[i]; ++j) if (f[i][j].S != invalid && !last[j]) last[j] = i;
	}
}

vector recursion(int n, int W) {
	if (n == 1) return vector(1, 1);
	int i, m = f[n][W].last.first, deg = n - m + 1;
	vector ret(recursion(f[n][W].last.first, f[n][W].last.second));
	ret.reserve(n);
	if (f[n][W].S == conjunct) {
		assert(deg > 1);
		for (int &x : ret) x = m - x + 1;
		for (; ++m <= n; ret.EB(m));
	} else {
		assert(deg > 3);
		for (int &x : ret) ++x;
		for (i = 4; i <= deg; i += 2) ret.EB(i + m - 1);
		ret.EB(1);
		for (i = 3; i < deg - 2; i += 2) ret.EB(i + m - 1);
		if (deg & 1) ret.EB(n);
		ret.EB(i + m - 1);
	}
	return ret;
}

inline vector solve(int n, int W) {return n == 1 ? (W == 1 ? vector(1, 1) : vector()) : (W <= n || f[n][W - n].S == invalid ? vector() : recursion(n, W - n));}

int main() {
	int T, i, n, W; vector ret; init();
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) {
		cin >> n >> W, ret = solve(n, W);
		if (ret.empty()) cout << "NO\n";
		else for (cout << "YES\n", i = 0; i < n; ++i) cout << ret[i] << (i == n - 1 ? '\n' : ' ');
	}
	return 0;
}