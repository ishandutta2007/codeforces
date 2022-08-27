#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;

const int N = 100054;

int n;
int a[N];

void work() {
	int i, s = 0, b, c[2] = {0, 0};
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i], s ^= a[i];
	if (!s) {cout << "DRAW\n"; return;}
	b = lg2(s);
	for (i = 0; i < n; ++i) ++c[a[i] >> b & 1];
	assert(c[1] & 1);
	cout << (!(c[0] & 1) && c[1] & 2 ? "LOSE\n" : "WIN\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}