#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 100 + 1;
const int MAX_M = 10000 + 1;
char map[MAX_N][MAX_M];
int n, m;
const int INF = ~0U >> 2;

void doit(char a[], int d[], int m) {
	static int que[MAX_M], qh, qt;
	qh = qt = 0;
	for (int i = 0; i < m; ++i) {
		d[i] = a[i] == '1' ? 0 : INF;
		if (d[i] == 0) {
			que[qt++] = i;
		}
	}
	while (qh < qt) {
		int u = que[qh++];
		int v = (u + 1) % m;
		if (d[v] == INF) {
			d[v] = d[u] + 1;
			que[qt++] = v;
		}
		v = (u + m - 1) % m;
		if (d[v] == INF) {
			d[v] = d[u] + 1;
			que[qt++] = v;
		}
	}
}

int d[MAX_M];
int cst[MAX_M];

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		scanf("%s", map[r]);
	}
	for (int r = 0; r < n; ++r) {
		doit(map[r], d, m);
		for (int c = 0; c < m; ++c) {
			if (d[c] == INF || cst[c] == INF) {
				cst[c] = INF;
			} else {
				cst[c] += d[c];
			}
		}
	}
	int ans = *min_element(cst, cst + m);
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}