#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 54;

int n;
char s[N], t[N];

void work() {
	int i, ans = 0;
	cin >> n >> s;
	memcpy(t, s, n);
	std::sort(t, t + n);
	for (i = 0; i < n; ++i) ans += s[i] != t[i];
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}