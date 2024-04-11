#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
#define gcd std::__gcd
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054;

int n;
ll a[N];

namespace pb_ds {
	int T1, T2;
	ll S1[N], G1[N], S2[N], G2[N];

	inline void clear() {T1 = T2 = 0;}

	inline void push(ll x) {S1[++T1] = x, G1[T1] = gcd(G1[T1 - 1], x);}

	inline ll query() {return gcd(G1[T1], G2[T2]);}

	inline void pop() {
		if (!T2) {
			for (; T1; --T1) S2[++T2] = S1[T1], G2[T2] = gcd(G2[T2 - 1], S1[T1]);
		}
		--T2;
	}
}

void work() {
	int i, j = 1, ans = 1;
	cin >> n, pb_ds::clear();
	for (i = 0; i < n; ++i) cin >> a[i];
	for (i = n - 1; i; --i) a[i] = llabs(a[i] - a[i - 1]);
	for (i = 1; i < n; ++i) {
		for (; j < n && pb_ds::query() != 1; ++j) {
			ans = std::max(ans, j - i + 1);
			pb_ds::push(a[j]);
		}
		if (pb_ds::query() != 1) ans = std::max(ans, j - i + 1);
		pb_ds::pop();
	}
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}