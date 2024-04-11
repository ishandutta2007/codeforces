#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main() {
	int n;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n, cout << (n - 1) % 9 + 1 << '\n';
	return 0;
}