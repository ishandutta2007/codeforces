#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int n;
int a[N];
ll K;
bool w[N];

void work() {
	int i, j;
	cin >> n >> K, --K;
	if (n < 64 && K >> (n - 1)) {cout << "-1\n"; return;}
	memset(w, false, n), std::iota(a, a + n, 1);
	for (i = 0; i < n - 1 && i < 64; ++i) w[n - i - 1] = K >> i & 1;
	for (i = 1; i < n; ++i)
		if (w[i]) {
			for (j = i; j < n && w[j]; ++j);
			std::reverse(a + (i - 1), a + j);
			i = j;
		}
	for (i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}