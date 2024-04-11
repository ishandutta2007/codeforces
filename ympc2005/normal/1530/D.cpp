#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], T, ans, rt, p[N];

vector <int> e[N], A, B;

bool vis[N];

void dfs_(int x) {
	vis[x] = 1;

	bool ok = 0;

	for (int y : e[x]) {
		if (y == rt) {
			continue;
		}

		dfs_(y);

		if (!ok) {
			ok = 1;
			p[y] = x;
		}
	}
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n), ans = 0;

		for (int i = 1; i <= n; i++) {
			e[i].clear();
			p[i] = vis[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			e[a[i]].push_back(i);
		}

		for (int i = 1; i <= n; i++) {
			ans += e[i].size() > 0;
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				continue;
			}

			int x = i, y, ok = 0;

			for (; !vis[x]; x = a[x]) {
				vis[x] = 1;
			}

			y = x;

			while (1) {
				if (e[a[x]].size() > 1) {
					rt = x;
					break;
				}

				x = a[x];

				if (x == y) {
					ok = 1;
					break;
				}
			}

			if (ok) {
				for (; !p[x]; x = a[x]) {
					p[x] = a[x];
				}

				continue;
			}

			dfs_(rt);
		}

		A.clear(); B.clear();

		for (int i = 1; i <= n; i++) {
			if (!p[i]) {
				A.push_back(i);
			}

			if (!e[i].size()) {
				B.push_back(i);
			}
		}

		int m = A.size(), tag = 1;

		assert(A.size() == B.size());

		for (int i = 0; i < m; i++) {
			if (e[A[i]].size()) {
				tag = 0;

				int l = 0, r = m - 1;

				for (int j = 0; j < m; j++) {
					if (i == j) {
						continue;
					}

					if (B[l] == A[j]) {
						p[A[j]] = B[r--];
					} else {
						p[A[j]] = B[l++];
					}
				}

				p[A[i]] = B[l];
				break;
			}
		}

		if (tag) {
			reverse(B.begin(), B.end());

			for (int i = 0; i < m; i++) {
				p[A[i]] = B[i];
			}
		}

		printf("%d\n", ans);

		for (int i = 1; i <= n; i++) {
			printf("%d ", p[i]);
		}

		putchar('\n');
	}
}