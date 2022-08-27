#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054;

int n;

inline bool check(int n, int a) {
	if (n % a) return false;
	int s = sqrt(n /= a);
	return s * s == n;
}

void work() {
	cin >> n;
	cout << (check(n, 2) || check(n, 4) ? "YES\n" : "NO\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}