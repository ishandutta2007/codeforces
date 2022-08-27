#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 20;

int n;
char s[N];

inline bool check(int x, int y, int z) {
	return (x + y) % 26 == z;
}

int main() {
	int i;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> s, n = strlen(s);
	for (i = 0; i < n; ++i) s[i] -= 65;
	for (i = 2; i < n; ++i)
		if (!check(s[i - 2], s[i - 1], s[i])) break;
	cout << (i >= n ? "YES\n" : "NO\n");
	return 0;
}