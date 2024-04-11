#include <bits/stdc++.h>

typedef long long ll;
const int N = 1054;

int n, H;
int a[N], b[N];

inline bool test(int K) {
	int i; ll H1 = 0;
	std::partial_sort_copy(a + 1, a + (K + 1), b + 1, b + (K + 1));
	for (i = K; i > 1; i -= 2) H1 += std::max(b[i], b[i - 1]);
	if (i >= 1) H1 += b[i];
	return H1 <= H;
}

int main() {
	int i, L = 0, R, M;
	scanf("%d%d", &n, &H);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (R = n; L < R; ) test(M = (L + R + 1) / 2) ? L = M : (R = M - 1);
	printf("%d\n", R);
	return 0;
}