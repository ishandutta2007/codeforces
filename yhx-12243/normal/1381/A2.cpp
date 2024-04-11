#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054;

int n;
char a[N], b[N];
int ans[N];

void work() {
	int i, c = 0, y, L, R; bool rev = false;
	cin >> n >> a >> b, L = 0, R = n - 1;
	for (i = n - 1; i >= 0; --i) {
		y = b[i];
		if (rev) {
			if (a[R] != y) ans[c++] = 0, a[R] ^= 1;
			ans[c++] = i, --R, rev = false;
		} else {
			if (a[L] == y) ans[c++] = 0, a[L] ^= 1;
			ans[c++] = i, ++L, rev = true;
		}
	}
	cout << c;
	for (i = 0; i < c; ++i) cout << ' ' << ans[i] + 1;
	cout << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}