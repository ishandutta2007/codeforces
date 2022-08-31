#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
typedef long long ll;
const int N = 200054;

int n;
pr a[N];
ll W;

void work() {
	int i, j, x, left = 0; ll s = 0;
	cin >> n >> W;
	for (i = 0; i < n; ++i) cin >> x, a[i] = pr(x, i + 1);
	std::sort(a, a + n, std::greater <pr> ());
	a[n].first = 0;
	for (i = 0; i <= n; ++i) {
		if (a[i].first > W) {++left; continue;}
		if (W <= 2 * s && s <= W) {
			cout << i - left << '\n';
			for (j = left; j < i; ++j) cout << a[j].second << (j == i - 1 ? '\n' : ' ');
			return;
		} else
			s += a[i].first;
	}
	cout << "-1\n";
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}