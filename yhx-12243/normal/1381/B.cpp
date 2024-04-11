#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 4054;
typedef std::bitset <N> bitset;

int n;
int a[N];
int cc[N];
bitset R;

inline void trans(int x) {R |= R << x;}

void work() {
	int i, L = 1, B;
	cin >> n;
	for (i = 1; i <= 2 * n; ++i) cin >> a[i];
	B = a[1], R.reset(), R.set(0);
	for (i = 2; i <= 2 * n; ++i) if (a[i] > B) trans(i - L), L = i, B = a[i];
	trans(i - L);
	cout << (R.test(n) ? "YES\n" : "NO\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}