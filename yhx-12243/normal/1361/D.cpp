#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
typedef std::pair <pr, int> ppi;
typedef std::vector <int> vector;
const int N = 500054;

int n, K, A = 0;
ppi g[N];
vector ps[N];
double sum = 0., unit[N], buf[N];
double a[N], pre[N], suf[N];

inline void up(double &x, const double y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

double solve_center() {
	int i, j, k = 0, m; long long $; double ret = 0.;
	for (i = 0; i < A; ++i) {
		m = ps[i].size();
		for (j = 0; j < m; ++j)
			$ = (K - 2 * j - 1ll) * ps[i][j], a[i] += buf[k++] = unit[i] * $;
		pre[i + 1] = pre[i] + a[i];
	}
	for (i = A - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i];
	assert(k == n), std::sort(buf, buf + n, std::greater <double> ());
	for (i = 0; i < K && i < n; ++i) ret += buf[i];
	return ret;
}

double solve_arm() {
	int i, j, k, m, c, u; long long $; double cur, ret = 0.;
	if (K > n) return 0.;
	for (i = 0; i < A; ++i) {
		m = ps[i].size();
		if (K <= n - m) continue;
		c = K - (n - m + 1), u = m - c;
		cur = pre[i] + suf[i + 1];
		for (j = 0; j < m - u; ++j)
			$ = (K - 2 * j - 1ll) * ps[i][j], cur += unit[i] * $;
		up(ret, cur);
		for (j = m - u, k = m; j > 0; )
			--j, --k, $ = (K - 2 * j - 1ll) * (ps[i][k] - ps[i][j]), up(ret, cur += unit[i] * $);
	}
	return ret;
}

int main() {
	int i, j = -1, x, y, d; double ans;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> K;
	for (i = 0; i < n; ++i) {
		if (cin >> x >> y, !(x || y)) {j = i; continue;}
		d = abs(std::__gcd(x, y)), x /= d, y /= d, g[i] = ppi(pr(x, y), -d);
	}
	assert(~j), std::swap(g[j], g[--n]);
	std::sort(g, g + n);
	for (j = 0, i = 1; i <= n; ++i)
		if (i == n || g[j].first != g[i].first) {
			unit[A] = hypot(g[j].first.first, g[j].first.second);
			for (ps[A].reserve(i - j); j < i; ++j) ps[A].EB(-g[j].second);
			++A;
		}
	ans = solve_center(), up(ans, solve_arm());
	cout << std::setprecision(12) << ans << '\n';
	return 0;
}