#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int n = 10, ALL = 1023;

char s[n + 5];
int f[ALL + 5];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

int solve(int X) {
	int i, A = 0, B = 0;
	for (i = 0; i < 10; ++i) {
		if (A + (10 - i) / 2 < B) return i;
		if (B + (11 - i) / 2 < A) return i;
		(i & 1 ? B : A) += X >> i & 1;
	}
	return 10;
}

void init() {
	for (int i = 0; i <= ALL; ++i) f[i] = solve(i);
}

void work() {
	int i, A = 0, B = 0, ans = 10;
	cin >> s;
	for (i = 0; i < 10; ++i)
		if (s[i] == '?') B |= 1 << i;
		else if (s[i] == '1') A |= 1 << i;
	down(ans, f[A]);
	for (i = B; i; i = (i - 1) & B) down(ans, f[A | i]);
	cout << ans << '\n';
}

int main() {
	int T; init();
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}