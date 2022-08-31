#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054;

int n, m;
char s[N], t[N];
int f[N][26], g[N][26];

void work() {
	int i, j, x, (*p)[26];
	cin >> s >> t, n = strlen(s), m = strlen(t);
	std::reverse(s, s + n), std::reverse(t, t + m);
	memset(f[n], 63, 104), memset(g[n], 63, 104);
	for (i = n - 1; i >= 0; --i) {
		memcpy(f[i], f[i + 1], 104), memcpy(g[i], g[i + 1], 104);
		(i & 1 ? g : f)[i][s[i] - 97] = i + 1;
	}
	p = f;
	for (x = j = 0; j < m; ++j) {
		x = p[x][t[j] - 97];
		if (x > n) break;
		p = (p == f ? g : f);
	}
	if (j >= m) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}