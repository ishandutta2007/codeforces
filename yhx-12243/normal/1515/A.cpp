#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 108;

int n, A;
int a[N];

void work() {
	int i, s = 0;
	cin >> n >> A;
	for (i = 0; i < n; ++i) cin >> a[i];
	std::sort(a, a + n);
	for (i = 0; i < n; ++i) {
		s += a[i];
		if (s == A) {
			if (i == n - 1) {cout << "NO\n"; return;}
			std::swap(a[i], a[i + 1]);
		}
	}
	cout << "YES\n";
	for (i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}