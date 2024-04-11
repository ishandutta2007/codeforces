#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 108;

int n, C, O, rem;
int c[N * N];
int u[N];
bool A[N];
int L[N], R[N];

void sweep() {
	int i;
	memset(u, 0, sizeof u);
	for (i = 0; i < n; ++i) if (A[c[i]]) {
		if (u[c[i]]) {
			L[c[i]] = u[c[i]], R[c[i]] = i + 1;
			A[c[i]] = false, --rem;
			memset(u, 0, sizeof u);
		} else u[c[i]] = i + 1;
	}
}

int main() {
	int i;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> C >> O, n = C * O;
	for (i = 0; i < n; ++i) cin >> c[i];
	memset(A, true, sizeof A), rem = C;
	for (; rem; ) sweep();
	for (i = 1; i <= C; ++i) cout << L[i] << ' ' << R[i] << '\n';
	return 0;
}