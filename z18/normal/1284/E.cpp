#include <bits/stdc++.h>
using namespace std;

const int maxn = 2500;
int n, m, x[maxn + 3], y[maxn + 3], z[maxn + 3], t[maxn + 3];
int cur_x, cur_y, cnt_1, cnt_2;
int res[maxn + 3], ans[maxn + 3], bit[maxn + 3];

struct point_1 {
	int x, y, id;
	friend bool operator < (const point_1 &a, const point_1 &b) {
		return 1ll * (a.y - cur_y) * (b.x - cur_x) < 1ll * (b.y - cur_y) * (a.x - cur_x);
	}
} p_1[maxn + 3];

struct point_2 {
	int x, y, id;
	friend bool operator < (const point_2 &a, const point_2 &b) {
		return 1ll * (cur_y - a.y) * (cur_x - b.x) < 1ll * (cur_y - b.y) * (cur_x - a.x);
	}
} p_2[maxn + 3];

void add(int x) {
	for (int i = x; i <= m; i += i & -i) {
		bit[i]++;
	}
}

int sum(int x) {
	int ans = 0;
	for (int i = x; i; i ^= i & -i) {
		ans += bit[i];
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		t[i] = x[i];
	}
	sort(t + 1, t + n + 1);
	m = unique(t + 1, t + n + 1) - (t + 1);
	for (int i = 1; i <= n; i++) {
		z[i] = lower_bound(t + 1, t + m + 1, x[i]) - t;
	}
	long long fuck = 0;
	for (int i = 1; i <= n; i++) {
		cnt_1 = cnt_2 = 0;
		cur_x = x[i], cur_y = y[i];
		for (int j = 1; j <= n; j++) if (x[j] > x[i]) {
			p_1[++cnt_1].x = x[j], p_1[cnt_1].y = y[j];
			p_1[cnt_1].id = j;
		}
		sort(p_1 + 1, p_1 + cnt_1 + 1);
		for (int j = 1; j <= n; j++) if (x[j] < x[i]) {
			p_2[++cnt_2].x = x[j], p_2[cnt_2].y = y[j];
			p_2[cnt_2].id = j;
		}
		sort(p_2 + 1, p_2 + cnt_2 + 1);
		memset(res, 0, sizeof(res));
		memset(ans, 0, sizeof(ans));
		memset(bit, 0, sizeof(bit));
		int foo = 0;
		for (int j = 1; j <= n; j++) if (x[j] == x[i] && y[j] < y[i]) {
			add(z[j]), foo++;
		}
		for (int j = 1; j <= cnt_1; j++) {
			res[p_1[j].id] = sum(z[p_1[j].id] - 1);
			add(z[p_1[j].id]);
		}
		int p = 1;
		for (int j = 1; j <= cnt_1; j++) {
			while (p <= cnt_2 && 1ll * (cur_y - p_2[p].y) * (p_1[j].x - cur_x) < 1ll * (p_1[j].y - cur_y) * (cur_x - p_2[p].x)) {
				p++;
			}
			ans[p_1[j].id] = foo + (j - 1) + (cnt_2 - p + 1);
		}
		for (int j = 1; j <= cnt_1; j++) {
			int r = res[p_1[j].id], a = ans[p_1[j].id];
			fuck += r * a - r * (n - 2 - a) - r;
		}
	}
	printf("%I64d\n", 1ll * fuck * (n - 4) / 2);
	return 0;
}