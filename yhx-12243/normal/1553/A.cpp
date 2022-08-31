#include <bits/stdc++.h>
using std::cin;
using std::cout;

int n;

void work() {
	cin >> n;
	cout << (n + 1) / 10 << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}