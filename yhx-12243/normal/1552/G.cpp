#include <bits/stdc++.h>
#define popc64 __builtin_popcountll
using std::cin;
using std::cout;

typedef unsigned long long u64;
const int N = 18;

int n, k;
u64 a[N];

bool dfs(int d, u64 zeros, u64 ones) {
	if (d == k) return ~(zeros ^ ones) == -1ull << n && (!zeros || !ones || zeros + 1 == (ones & -ones));
	int i, n0 = popc64(zeros & a[d]), n1 = popc64(ones & a[d]), tot = popc64(a[d]);
	u64 rzeros = zeros & ~a[d], rones = ones & ~a[d], U = a[d];
	for (i = tot; U; U &= U - 1, --i)
		if (n1 <= i && i <= tot - n0)
			if (!dfs(d + 1, rzeros | (U ^ a[d]), rones | U)) return false;
	if (!n1 && !dfs(d + 1, rzeros | a[d], rones)) return false;
	return true;
}

int main() {
	int i, r, x;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> k;
	for (i = 0; i < k; ++i)
		for (cin >> r; r; --r) cin >> x, a[i] |= 1ull << (x - 1);
	cout << (n == 1 || dfs(0, 0, 0) ? "ACCEPTED\n" : "REJECTED\n");
	return 0;
}