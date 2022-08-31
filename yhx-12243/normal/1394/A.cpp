#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int n, n1, n2, d, lim;
int a[N], b[N];
ll A[N], B[N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

int main() {
	int i, j, x; ll ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> d >> lim;
	for (i = 0; i < n; ++i)
		if (cin >> x, x <= lim)
			a[n1++] = x;
		else
			b[n2++] = x;
	std::sort(a, a + n1, std::greater <int> ());
	std::sort(b, b + n2, std::greater <int> ());
	for (i = 0; i < n1; ++i) A[i + 1] = A[i] + a[i];
	for (i = 0; i < n2; ++i) B[i + 1] = B[i] + b[i];
	for (i = 0; i <= n1; ++i) {
		j = (n - i + d) / (1 + d);
		j = std::min(j, n2);
		up(ans, A[i] + B[j]);
	}
	cout << ans << '\n';
	return 0;
}