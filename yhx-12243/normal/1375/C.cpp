#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 300054;

int n;
int a[N];

void work() {
	int i;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	cout << (a[1] < a[n] ? "YES\n" : "NO\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}