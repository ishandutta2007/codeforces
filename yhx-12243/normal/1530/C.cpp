#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int n;
int a[N], b[N];
ll B[N];

inline ll BB(int x) {return B[n] - B[std::max(n - (x - x / 4), 0)];}

void work() {
	int i, w; ll A = 0;
	cin >> n, w = n / 4;
	for (i = 0; i < n; ++i) cin >> a[i];
	std::sort(a, a + n);
	for (i = 0; i < n; ++i) cin >> b[i];
	std::sort(b, b + n);
	for (i = w; i < n; ++i) A += a[i];
	for (i = 0; i < n; ++i) B[i + 1] = B[i] + b[i];
	for (; i < 4 * n && A < BB(i); ++i) {
		A += 100;
		if (!(~i & 3)) A -= a[w], ++w;
	}
	cout << i - n << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}