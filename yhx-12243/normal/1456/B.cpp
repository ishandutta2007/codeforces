#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;

const int N = 100054;

int n;
int a[N];
 
int main() {
	int i, j, s, b, all, ans = INT_MAX;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	for (i = 0; i < n; ++i) {
		s = all = 0;
		for (j = i; j < n; ++j) {
			s ^= a[j];
			if (s) {
				b = lg2(s);
				if (all >> b & 1) {ans = std::min(ans, j - i); break;} 
			}
			all |= s;
		}
	}
	if (ans == INT_MAX) ans = 0;
	cout << ans - 1 << '\n';
	return 0;
}