#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, ll> pr;
const int N = 200054;

int n;
int a[N];
ll A[N];

inline pr operator - (const pr &A, const pr &B) {return pr(A.first - B.first, A.second - B.second);}

namespace BIT {
	const int N = 300054, B = 1350;

	int x[N];
	ll X[N];
	int y[B];
	ll Y[B];

	inline void add(int h, int v) {
		int i;
		for (i = h; i < B; ++i) ++y[i], Y[i] += v;
		for (; h < N; h |= h - 1, ++h) ++x[h], X[h] += v;
	}

	inline pr sum(int h) {
		pr ret(0, 0); h = std::min(h, N - 1), h = std::max(h, 0);
		if (h < B) return pr(y[h], Y[h]);
		for (; h > 0; h &= h - 1) ret.first += x[h], ret.second += X[h]; return ret;
	}
}

int main() {
	int i, l, r, v, x, s; ll S, ans = 0; pr last, cur;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	for (i = 0; i < n; ++i) {
		x = a[i];
		std::tie(s, S) = BIT::sum(BIT::N - 1) - (last = BIT::sum(x));
		A[i] = (ll)s * x;
		for (r = x; r; r = l) {
			v = x / r;
			l = x / (v + 1);
			std::tie(s, S) = last - (cur = BIT::sum(l));
			A[i] += (ll)s * x - S * v;
			last = cur;
		}
		for (v = 0, l = 0, r = x; l <= BIT::N; ++v, l = r, r += x) {
			std::tie(s, S) = BIT::sum(r - 1) - BIT::sum(l - 1);
			A[i] += S - (ll)s * l;
		}
		BIT::add(x, x);
	}
	for (i = 0; i < n; ++i) cout << (ans += A[i]) << (i == n - 1 ? '\n' : ' ');
	return 0;
}