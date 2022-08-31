#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054;

int n;
int a[N];

void work() {
	int i, s = 0; bool win = false;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i], s += a[i];
	std::sort(a, a + n);
	win = (s & 1) || 2 * a[n - 1] > s;
	cout << (win ? "T\n" : "HL\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}