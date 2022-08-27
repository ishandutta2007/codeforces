#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

const int N = 300054;

int n, ans;
int a[N];
int I[N], J[N], C[N];

inline void push(int i, int j, int c) {
	if (c) {
		I[ans] = i, J[ans] = j, C[ans++] = c;
		a[i] -= i * c, a[j] += i * c;
	}
}

void work() {
	int i, d, s = 0, avg; bool ok = false;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i], s += a[i];
	for (i = 1; i <= n; ++i) ok |= a[i] >= i;
	if (!ok || s % n) {cout << "-1\n"; return;}
	ans = 0, avg = s / n;
	for (i = 2; i <= n; ++i) {
		d = (i - 1) - (a[i] - 1) % i;
		push(1, i, d);
		push(i, 1, a[i] / i);
		assert(!a[i]);
	}
	assert(a[1] == s);
	for (i = 2; i <= n; ++i) push(1, i, avg);
	for (i = 1; i <= n; ++i) assert(a[i] == avg);
	cout << ans << '\n';
	for (i = 0; i < ans; ++i)
		cout << I[i] << ' ' << J[i] << ' ' << C[i] << '\n';
}

int main() {
	int T; 
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}