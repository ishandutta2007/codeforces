#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, m, T, a[N][N];

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d", &n, &m);

		memset(a, 0, sizeof(a));

		for (int i = 1; i <= m; i += 2) {
			a[1][i] = 1;
		}

		for (int i = 3; i <= n; i += 2) {
			a[i][m] = 1;
		}

		for (int i = m - 2; i >= 1; i -= 2) {
			a[n][i] = 1;
		}

		for (int i = n - 2; i > 2; i -= 2) {
			a[i][1] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				putchar(a[i][j] + '0');
			}

			putchar('\n');
		}
	}
}