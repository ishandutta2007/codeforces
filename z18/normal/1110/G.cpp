#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6;
int T, n, deg[maxn + 3];
vector<int> G[maxn + 3];
char s[maxn + 3];

void clear(int i) {
	vector<int>().swap(G[i]);
	deg[i] = 0;
}

void add(int u, int v) {
	G[u].push_back(v), G[v].push_back(u);
	deg[u]++, deg[v]++;
}

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			clear(i);
		}
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d %d", &u, &v), add(u, v);
		}
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'W') {
				clear(++n), add(i, n);
				clear(++n), add(n - 1, n);
				clear(++n), add(n - 2, n);
			}
		}
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (deg[i] >= 4) {
				puts("White");
				flag = true;
				break;
			}
			if (deg[i] == 3) {
				int cnt = 0;
				for (int j = 0; j < 3; j++) {
					cnt += deg[G[i][j]] != 1;
				}
				if (cnt >= 2) {
					puts("White");
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			int x = 0, y = 0;
			for (int i = 1; i <= n; i++) {
				if (deg[i] == 3) {
					if (!x) {
						x = i;
					} else if (!y) {
						y = i;
					} else {
						exit(1);
					}
				}
			}
			if (x && y && ((n - 4) & 1)) {
				puts("White");
			} else {
				puts("Draw");
			}
		}
	}
	return 0;
}