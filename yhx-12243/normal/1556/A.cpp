#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

void work() {
	int a, b, ans;
	cin >> a >> b;
	if ((a ^ b) & 1) {cout << -1 << '\n'; return;}
	if (!a && !b) ans = 0;
	else if (a == b) ans = 1;
	else ans = 2;
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}