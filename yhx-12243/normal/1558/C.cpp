#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 2054;

int n;
int p[N];
int L, seq[N * 5];

inline void run(int x) {seq[L++] = x, std::reverse(p + 1, p + (x + 1));}

void solve(int n) {
	int a, b;
	a = std::find(p + 1, p + (n + 1), n) - p, run(a);
	b = std::find(p + 1, p + (n + 1), n - 1) - p, run(b - 1);
	run(b + 1), run(3), run(n), assert(p[n] == n && p[n - 1] == n - 1);
}

void work() {
	int i; L = 0;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> p[i];
	for (i = 1; i <= n && !((p[i] ^ i) & 1); ++i);
	if (i <= n) {cout << "-1\n"; return;}
	for (i = n; i > 1; i -= 2) solve(i);
	cout << L << '\n';
	for (i = 0; i < L; ++i) cout << seq[i] << (i == L - 1 ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}