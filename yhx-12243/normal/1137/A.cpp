#include <bits/stdc++.h>
#define N 1054

typedef std::pair <int, int> pr;

int r, c;
int a[N][N];
int r1[N][N], r2[N][N], c1[N][N], c2[N][N];

namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0;
		std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

int main() {
	int i, j, z;
	scanf("%d%d", &r, &c);
	for (i = 0; i < r; ++i)
		for (j = 0; j < c; ++j)
			scanf("%d", a[i] + j);
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) DC::D[j] = pr(a[i][j], j);
		z = DC::Discretize(c);
		for (j = 0; j < c; ++j) r1[i][j] = DC::F[j], r2[i][j] = z - DC::F[j] - 1;
	}
	for (j = 0; j < c; ++j) {
		for (i = 0; i < r; ++i) DC::D[i] = pr(a[i][j], i);
		z = DC::Discretize(r);
		for (i = 0; i < r; ++i) c1[i][j] = DC::F[i], c2[i][j] = z - DC::F[i] - 1;
	}
	for (i = 0; i < r; ++i)
		for (j = 0; j < c; ++j) {
			z = std::max(r2[i][j], c2[i][j]) + std::max(r1[i][j], c1[i][j]) + 1;
			printf("%d%c", z, j == c - 1 ? 10 : 32);
		}
	return 0;
}