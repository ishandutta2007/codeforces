#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 100054;

int n;
ll S;
pr a[N];

int main() {
	int i, pos;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i].first >> a[i].second, S += a[i].second;
	std::sort(a, a + n);
	pos = a->first + a->second;
	for (i = 1; i < n; ++i) {
		if (a[i].first > pos) S += a[i].first - pos;
		pos = std::max(pos, a[i].first + a[i].second);
	}
	cout << S << '\n';
	return 0;
}