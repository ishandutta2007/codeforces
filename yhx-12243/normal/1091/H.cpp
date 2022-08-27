#include <bits/stdc++.h>
#define N 200054

typedef std::bitset <N> bit;

int n, forbid;
int pn = 0, c[N], p[18000], sg[N];
bit mark[100], fy;

void init(int n) {
	int i, j, v;
	for (i = 2; i <= n; ++i) {
		if (!c[i]) p[pn++] = i;
		for (j = 0; j < pn && (v = i * p[j]) <= n; ++j)
			if (c[v] = p[j], !(i % p[j])) break;
		fy.set(i, !((c[i] && c[i / c[i]]) || i == forbid));
	}
	*mark = fy | fy << 1;
	for (i = 2; i <= n; ++i) {
		int &r = sg[i]; for (; mark[r].test(i); ++r); mark[r] |= fy << i;
	}
}

int main() {
	int i, u, v, w, cur = 0;
	scanf("%d%d", &n, &forbid); init(N - 1);
	for (i = 1; i <= n; ++i) scanf("%d%d%d", &u, &v, &w), cur ^= sg[v - u - 1] ^ sg[w - v - 1];
	puts(cur ? "Alice\nBob" : "Bob\nAlice");
	return 0;
}