#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N], c[N], ans, t[3], m, id[3], lim;

bool vis[3];

struct Node {
	int x, y;

	bool operator < (const Node tmp) const {
		return x < tmp.x;
	}
} p[3][N], q[3][N];

bool try_(int l, int r) {
	int cnt = 0, pos, x = id[1];

	for (int i = 1; i <= m; i++) {
		if (q[x][i].y > r || q[x][i].y < l) {
			continue;
		}

		cnt++;

		if (cnt == lim) {
			pos = q[x][i].x;
			break;
		}
	}

	if (cnt < lim) {
		return 0;
	}

	cnt = 0, x = id[2];

	for (int i = 1; i <= m; i++) {
		if (q[x][i].y > r || q[x][i].y < l || q[x][i].x <= pos) {
			continue;
		}

		cnt++;

		if (cnt >= lim) {
			return 1;
		}
	}

	return 0;
}

bool work_() {
	if (try_(-1e9, p[id[0]][m - lim + 1].x - 1)) {
		return 1;
	}

	if (try_(p[id[0]][lim].x + 1, 1e9)) {
		return 1;
	}

	int pos = -1e9 - 1;

	for (int i = 0; i < 3; i++) {
		int u = id[i], cnt = 0;

		for (int j = 1; j <= m; j++) {
			if (p[u][j].x <= pos) {
				continue;
			}

			cnt++;

			if (cnt == lim) {
				pos = p[u][j].x;
				break;
			}
		}

		if (cnt < lim) {
			return 0;
		}
	}

	return 1;
}

bool dfs_(int x) {
	if (x > 2) {
		return work_();
	}

	bool ok = 0;

	for (int i = 0; i < 3; i++) {
		if (!vis[i]) {
			vis[i] = 1, id[x] = i;
			ok = dfs_(x + 1);
			vis[i] = 0;

			if (ok) {
				break;
			}
		}
	}

	return ok;
}

bool check_() {
	memset(vis, 0, sizeof(vis));
	return dfs_(0);
}

void solve_() {
	t[0] = t[1] = t[2] = 0, m = n/3;

	for (int i = 1; i <= n; i++) {
		t[c[i]]++;
		p[c[i]][t[c[i]]] = (Node) {a[i], b[i]};
		q[c[i]][t[c[i]]] = (Node) {b[i], a[i]};
	}

	for (int i = 0; i < 3; i++) {
		sort(p[i] + 1, p[i] + m + 1);
		sort(q[i] + 1, q[i] + m + 1);
	}

	int l = 1, r = m;

	while (l < r) {
		int mid = (l + r + 1)>>1;
		lim = mid;

		if (check_()) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}

	ans = max(ans, l);
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		c[i]--;
	}

	solve_();

	for (int i = 1; i <= n; i++) {
		swap(a[i], b[i]);
	}

	solve_();

	printf("%d\n", ans*3);
}