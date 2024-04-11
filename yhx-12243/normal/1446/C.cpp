#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054;

int n;
int a[N];

inline int max(const int x, const int y) {return x < y ? y : x;}

int solve(int L, int R, int d) {
	if (R - L < 3 || d < 0) return R - L;
	int M, lf, rf;
	for (M = L; M < R && !(a[M] >> d & 1); ++M);
	if (M == L || M == R) return solve(L, R, d - 1);
	lf = solve(L, M, d - 1), rf = solve(M, R, d - 1);
	return max(lf, rf) + 1;
}

int main() {
	int i;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	std::sort(a, a + n);
	cout << n - solve(0, n, 30) << '\n';
	return 0;
}