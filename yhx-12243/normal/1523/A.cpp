#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 1054;

int n, m;
char s[N], t[N];

void work() {
	int i;
	cin >> n >> m >> s + 1;
	s[0] = s[n + 1] = 48;
	for (; m; --m) {
		t[0] = t[n + 1] = 48;
		for (i = 1; i <= n; ++i)
			t[i] = s[i] | (s[i - 1] ^ s[i + 1]);
		if (!memcmp(s, t, n + 2)) break;
		memcpy(s, t, n + 2);
	}
	s[n + 1] = 0,
	cout << s + 1 << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}