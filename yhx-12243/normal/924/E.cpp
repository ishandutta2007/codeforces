#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 10054;

int n, l, r;
int f[N];
pr a[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main() {
	int i, j, H = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> l >> r;
	for (i = 0; i < n; ++i) cin >> a[i].second, H -= a[i].second = -a[i].second;
	for (i = 0; i < n; ++i) cin >> a[i].first;
	std::sort(a, a + n), memset(f, 192, (H + 1) << 2), f[H] = 0;
	for (i = 0; i < n; ++i)
		for (j = 0; j <= H + a[i].second; ++j)
			up(f[j], f[j - a[i].second] + (a[i].first && l <= j && j <= r));
	cout << *std::max_element(f, f + (H + 1)) << '\n';
	return 0;
}