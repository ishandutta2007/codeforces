#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, ll> pr;
const int N = 200054, W = 1000000;

int n, m, q;
int a[N], b[N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

struct pb_ds {
	int x[W + 1];
	ll X[W + 1];

	void add(int h, int v, int V) {for (; h <= W; h |= h + 1) x[h] += v, X[h] += V;}
	pr sum(int h) {pr ret(0, 0); for (; h >= 0; h &= h + 1, --h) ret.first += x[h], ret.second += X[h]; return ret;}

	inline void insert(int x) {add(x, 1, x);}
	inline void erase(int x) {add(x, -1, -x);}
	inline int kth(int k) {
		int i, l = -1, r;
		for (i = 19; i >= 0; --i)
			if ((r = (1 << i) + l) <= W && x[r] < k) k -= x[l = r];
		return l + 1;
	}
} A, B;

int main() {
	int i, op, x, y, t, g_min, a_min, a_max, b_min, b_max;
	ll a_sum = 0, b_sum = 0, P, s, cur, ans;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> m >> q;
	for (i = 1; i <= n; ++i) cin >> a[i], a_sum += a[i], A.insert(a[i]);
	for (i = 1; i <= m; ++i) cin >> b[i], b_sum += b[i], B.insert(b[i]);
	for (; q; --q)
		switch (cin >> op, op) {
			case 1:
				cin >> i >> x;
				if (a[i] != x) a_sum += x - a[i], A.erase(a[i]), A.insert(a[i] = x);
				break;
			case 2:
				cin >> i >> x;
				if (b[i] != x) b_sum += x - b[i], B.erase(b[i]), B.insert(b[i] = x);
				break;
			case 3:
				cin >> x,
				a_min = A.kth(1), a_max = A.kth(n),
				b_min = B.kth(1), b_max = B.kth(m),
				g_min = min(a_min, b_min),
				P = a_sum - (ll)n * g_min,
				ans = a_sum - b_sum + ll(n - m) * (x - g_min);

				y = max(
					g_min + x >= a_max ? a_max : A.kth(A.sum(g_min + x).first),
					g_min + x >= b_max ? b_max : B.kth(B.sum(g_min + x).first)
				),
				up(ans, cur = a_sum - b_sum + ll(n - m) * (x - y));

				if (b_max > g_min + x)
					std::tie(t, s) = B.sum(max(b_max - x, 0) - 1), t = m - t, s = b_sum - s,
					up(ans, cur = P - s + t * ll(b_max - x));

				if (b_max + x < a_max) {
					i = A.sum(b_max + x).first;

					y = A.kth(i);
					if (y > g_min + x)
						std::tie(t, s) = B.sum(max(y - x, 0) - 1), t = m - t, s = b_sum - s,
						up(ans, cur = P - s + g_min + (t - 1ll) * (y - x));

					y = A.kth(i + 1);
					if (y > g_min + x)
						std::tie(t, s) = B.sum(max(y - x, 0) - 1), t = m - t, s = b_sum - s,
						up(ans, cur = P - s + g_min + (t - 1ll) * (y - x));
				}

				if (a_max > g_min + x)
					std::tie(t, s) = B.sum(max(a_max - x, 0) - 1), t = m - t, s = b_sum - s,
					up(ans, cur = P - s + g_min + (t - 1ll) * (a_max - x));

				cout << ans << '\n';
				break;
		}
	return 0;
}