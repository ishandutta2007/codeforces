#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 1000054;

int n, d;
int c[N];
ll a[N];

int main() {
	int i, j; ll ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> d, ++d;
	for (i = 0; i < n; ++i) cin >> c[i];
	std::sort(c, c + n, std::greater <int> ());
	for (i = 0; i < n; ++i) a[i + 1] = a[i] + c[i];
	a[n] = LLONG_MIN;
	for (i = 1; i <= n && a[i] >= 0; ++i) ans += a[i];
	for (j = n - d; j >= i; j -= d) ans += a[j];
	cout << ans << '\n';
	return 0;
}