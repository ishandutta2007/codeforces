#include <bits/stdc++.h>
#define adding(x) for (cnt += 2 * ((x) >= n), i = first[x]; i; i = next[i]) cnt += to[i][deg] == 1;

const int N = 1000054, M = N * 2;

int n, V, E = 0;
int to[M], first[N], next[M], deg[N], lu[N];
char s[N];

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E, ++deg[u];
	to[++E] = u, next[E] = first[v], first[v] = E, ++deg[v];
}

bool solve() {
	int Delta = *std::max_element(deg, deg + V), i, v, *p, cnt = 0;
	if (Delta >= 4) return true;
	if (Delta <= 2) return false;
	switch (std::count(deg, deg + V, 3)) {
		case 1:
			v = std::find(deg, deg + V, 3) - deg; adding(v);
			return cnt < 2;
		case 2:
			p = std::find(deg, deg + V, 3); adding(p - deg);
			v = std::find(p + 1, deg + V, 3) - deg; adding(v);
			return cnt < 4 || (V & 1);
		default: return true;
	}
}

void work() {
	int i, u, v;
	scanf("%d", &n), V = n, E = 0;
	memset(first, 0, n << 3), memset(deg, 0, n << 3);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(--u, --v);
	scanf("%s", s);
	for (i = 0; i < n; ++i) if (s[i] == 87) addedge(V, i), deg[V++] += 2;
	puts(solve() ? "White" : "Draw");
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}