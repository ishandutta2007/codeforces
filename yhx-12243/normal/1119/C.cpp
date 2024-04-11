#include <bits/stdc++.h>

const int N = 540;

int r, c;
int a[N][N], b[N][N];
int A[N], B[N], X[N], Y[N];
int main() {
	int i, j;
	scanf("%d%d", &r, &c);
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) scanf("%d", a[i] + j), X[j] += a[i][j];
		A[i] = std::accumulate(a[i], a[i] + c, 0);
	}
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) scanf("%d", b[i] + j), Y[j] += b[i][j];
		B[i] = std::accumulate(b[i], b[i] + c, 0);
	}
	for (i = 0; i < r && !((A[i] ^ B[i]) & 1); ++i);
	for (j = 0; j < c && !((X[j] ^ Y[j]) & 1); ++j);
	puts(i == r && j == c ? "Yes" : "No");
	return 0;
}