#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, m, k, deg, fa[maxn + 3];
bool b[maxn + 3];

struct edge {
	int u, v, w, id, x;
	friend bool operator < (const edge &a, const edge &b) {
		return a.w == b.w ? a.x < b.x : a.w < b.w;
	}
} e[maxn + 3];

bool comp(const edge &a, const edge &b) {
	return a.w == b.w ? a.x > b.x : a.w < b.w;
}

int find(int x) {
	return fa[x] == x ? x : x = find(fa[x]);
}

int mst(int x, bool flag = false) {
	for (int i = 1; i <= m; i++) if (e[i].x) e[i].w += x;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	int cnt = 0, sum = 0;
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue;
		cnt++, sum += e[i].x, fa[u] = v;
		if (flag && e[i].x) b[e[i].id] = true;
	}
	for (int i = 1; i <= m; i++) if (e[i].x) e[i].w -= x;
	return cnt == n - 1 ? sum : -1;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
		e[i].id = i, e[i].x = e[i].u == 1 || e[i].v == 1, deg += e[i].x;
	}
	if ((n > 1 && k == 0) || deg < k || mst(0) == -1) puts("-1"), exit(0);
	int l = -1e5, r = 1e5;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (mst(mid) <= k) r = mid;
		else l = mid + 1;
	}
	k -= mst(l, true);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) if (b[e[i].id]) fa[find(e[i].u)] = find(e[i].v);
	for (int i = 1; i <= m; i++) if (e[i].x) e[i].w += l;
	sort(e + 1, e + m + 1, comp);
	for (int i = 1; i <= m; i++) if (!b[e[i].id]) {
		if (!k && e[i].x) continue;
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue;
		b[e[i].id] = true, fa[u] = v, k -= e[i].x;
	}
	printf("%d\n", n - 1);
	for (int i = 1; i <= m; i++) if (b[i]) printf("%d ", i);
	puts("");
	return 0;
}