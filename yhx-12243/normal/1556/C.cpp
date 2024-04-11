#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
typedef unsigned long long u64;
const int N = 1054;

int n;
ll L[N], R[N];

inline ll intersect(ll L1, ll R1, ll L2, ll R2) {
	if (R1 < L2 || R2 < L1) return 0;
	return std::min(R1, R2) - std::max(L1, L2) + 1;
}

void work() {
	int i, j, x; ll l, r, cur = 0; u64 ans = 0;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> x;
		if (i & 1) R[i] = cur - 1, L[i] = cur -= x;
		else L[i] = cur + 1, R[i] = cur += x;
		if (!(i & 1)) continue;
		l = L[i], r = R[i];
		for (j = i - 1; j >= 0; --j) {
			ans += intersect(L[j], R[j], l, r);
			if (!(j & 1)) {
				r = std::min(r, L[j] - 1);
				if (l > r) break;
			}
		}
		ans += l <= 0 && 0 <= r;
	}
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (T = 1; T; --T) work();
	return 0;
}