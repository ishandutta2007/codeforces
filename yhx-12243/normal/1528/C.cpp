#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 300054;

int n, ans;
int p[2][N], fc[2][N], nc[2][N];
int cnt, o[N], id[N], eid[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void link(int id, int x, int px) {p[id][x] = px, nc[id][x] = fc[id][px], fc[id][px] = x;}
inline bool check(int x, int y) {return y <= eid[x];}

namespace pb_ds {
	typedef std::set <int> set;

	int cur;
	set S;

	void init() {S.clear(), S.emplace(1), cur = 1;}

	void insert(int x) {
		if (x == 1) return;
		set::iterator it = S.emplace(x).first, jt = std::prev(it), kt = std::next(it);
		cur += !check(*jt, x);
		if (kt != S.end()) cur += check(*jt, *kt) - check(x, *kt);
	}

	void erase(int x) {
		if (x == 1) return;
		set::iterator it = S.find(x), jt = std::prev(it), kt = std::next(it);
		cur -= !check(*jt, x);
		if (kt != S.end()) cur += check(x, *kt) - check(*jt, *kt);
		S.erase(it);
	}
}

void dfs(int x) {
	o[++cnt] = x, id[x] = cnt;
	for (int y = fc[1][x]; y; y = nc[1][y]) dfs(y);
	eid[id[x]] = cnt;
}

void work(int x) {
	pb_ds::insert(id[x]),
	up(ans, pb_ds::cur);
	for (int y = fc[0][x]; y; y = nc[0][y]) work(y);
	pb_ds::erase(id[x]);
}

void work() {
	int i, x;
	cin >> n;
	memset(fc[0], 0, (n + 1) << 2), memset(fc[1], 0, (n + 1) << 2);
	for (i = 2; i <= n; ++i) cin >> x, link(0, i, x);
	for (i = 2; i <= n; ++i) cin >> x, link(1, i, x);
	cnt = 0, dfs(1), pb_ds::init();
	ans = 1, work(1);
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}