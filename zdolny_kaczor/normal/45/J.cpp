# include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n * m == 2 || m * n == 3 || (m == 2 && n == 2))
		printf("-1\n");
	else {
		int l1 = (m * n + 1) / 2;
		int l2 = m * n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if ((i + j) % 2)
					printf("%d ", l2--);
				else
					printf("%d ", l1--);
			}
			printf("\n");
		}
	}
}