#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 111;

int n;
int a[N];

void work() {
	int i, x;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> x, x = abs(x);
		if (i & 1) x = -x;
		cout << x << (i == n ? '\n' : ' ');
	}
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}