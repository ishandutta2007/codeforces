#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4;
int n, m, t[maxn + 3], k, a[maxn + 3], o, b[maxn + 3];

struct point {
	int id, x, y, z;
	friend bool operator < (const point &a, const point &b) {
		return a.x == b.x ? a.y == b.y ? a.z < b.z : a.y < b.y : a.x < b.x;
	}
} p[maxn + 3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		p[i].id = i;
		scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
	}
	sort(p + 1, p + n + 1);
	for (int l = 1, r = 1; l <= n; l = r + 1, r = l) {
		while (r < n && p[r + 1].x == p[l].x) {
			r++;
		}
		k = 0;
		for (int i = l, j = l; i <= r; i = j + 1, j = i) {
			m = 0;
			t[++m] = p[i].id;
			while (j < r && p[j + 1].y == p[i].y) {
				t[++m] = p[++j].id;
			}
			for (int i = 1; i <= m - 1; i += 2) {
				printf("%d %d\n", t[i], t[i + 1]);
			}
			if (m & 1) {
				a[++k] = t[m];
			}
		}
		for (int i = 1; i <= k - 1; i += 2) {
			printf("%d %d\n", a[i], a[i + 1]);
		}
		if (k & 1) {
			b[++o] = a[k];
		}
	}
	for (int i = 1; i <= o; i += 2) {
		printf("%d %d\n", b[i], b[i + 1]);
	}
	return 0;
}