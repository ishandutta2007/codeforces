#include <bits/stdc++.h>
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 15, N2 = 1050;

int n;
int a[N], S[N2];

void work() {
	int i;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i], a[i] = abs(a[i]);
	for (i = 1; i < 1 << n; ++i) S[i] = S[i & (i - 1)] + a[ctz(i)];
	std::sort(S, S + (1 << n));
	for (i = 1; i < 1 << n; ++i)
		if (S[i - 1] == S[i]) {
			cout << "YES\n"; return;
		}
	cout << "NO\n";
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}