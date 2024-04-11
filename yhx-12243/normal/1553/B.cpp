#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 1054;

int n, m;
char s[N], t[N];

void work() {
	int i, j, k, u;
	cin >> s >> t, n = strlen(s), m = strlen(t);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m && j <= i; ++j)
			if (!memcmp(s + (i - j), t, (j + 1))) {
				for (u = i, k = j; u >= 0 && k < m && s[u] == t[k]; --u, ++k);
				if (k == m) {cout << "YES\n"; return;}
			}
	cout << "NO\n";
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}