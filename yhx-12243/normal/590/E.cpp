#include <bits/stdc++.h>

const int N = 754, LEN = 10000754;
typedef std::bitset <N> bitset;

int n;
char buffer[LEN], *s[N];
bitset G[N], used;
int L[N], R[N];
bool covL[N], covR[N];
int cnt = 0, ans[N];

namespace AC {
	int cnt = 1, d[LEN][2], f[LEN], val[LEN], que[LEN];

	int append(char *s, int tag_) {
		char *p = s;
		int t = 1, id;
		for (; *p; ++p)
			id = *p - 97, t = (d[t][id] ? d[t][id] : (d[t][id] = ++cnt));
		return val[t] = tag_, p - s;
	}

	void build() {
		int h, ta = 1, i, t, id;
		*que = 1, f[1] = 0;	
		for (h = 0; h < ta; ++h)
			for (i = que[h], id = 0; id < 2; ++id) {
				t = (f[i] ? d[f[i]][id] : 1);
				int &u = d[i][id];
				if (!u) {u = t; continue;}
				f[u] = t, que[ta++] = u, val[u] || (val[u] = val[t]);
			}
	}

	bitset match(char *s) {
		int t = 1, id; bitset ret;
		for (; *s; ++s) {
			id = *s - 97, t = (d[t][id] ? d[t][id] : 1);
			if (val[t]) ret.set(val[t]);
			if (val[f[t]]) ret.set(val[f[t]]);
		}
		return ret;
	}
}

bool dfs(int x) {
	for (int y = G[x]._Find_first(); y != N; y = G[x]._Find_next(y))
		if (!used.test(y) && (used.set(y), !L[y] || dfs(L[y])))
			return L[y] = x, R[x] = y, true;
	return false;
}

void konig(int x) {
	for (int y = G[x]._Find_first(); y != N; y = G[x]._Find_next(y))
		if (!covR[y]) covR[y] = true, konig(L[y]);
}


int main() {
	int i, j, M = 0;
	scanf("%d", &n), *s = buffer;
	for (i = 0; i < n; ++i)
		scanf("%s", s[i]), s[i + 1] = s[i] + 1 + AC::append(s[i], i + 1);
	AC::build();
	for (i = 1; i <= n; ++i) (G[i] = AC::match(s[i - 1])).reset(i);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			if (G[j].test(i)) G[j] |= G[i];
	for (i = 1; i <= n; ++i) used.reset(), M += dfs(i);
	printf("%d\n", n - M);
	for (i = 1; i <= n; ++i) if (!R[i]) konig(i);
	for (i = 1; i <= n; ++i) if (R[i] && !covR[R[i]]) covL[i] = true;
	for (i = 1; i <= n; ++i) if (!(covL[i] || covR[i])) ans[cnt++] = i;
	for (i = 0; i < cnt; ++i) printf("%d%c", ans[i], i == cnt - 1 ? 10 : 32);
	return 0;
}