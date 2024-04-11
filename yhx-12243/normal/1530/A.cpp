#include <bits/stdc++.h>
using std::cin;
using std::cout;

int n;

void work() {
	int w = 0;
	cin >> n;
	for (; n; n /= 10) w = std::max(w, n % 10);
	cout << w << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}