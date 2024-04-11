#include <bits/stdc++.h>
#define ctz __builtin_ctz

const int N = 2054, M = 13, M2 = 4154;
	
int R, C, ALL;
int a[M][N];
int mp[M2], lyn[M2];
int s[M2], dp[2][M2], *cur = *dp, *nxt = dp[1];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

void work() {
	int i, j, k, l = 0, x, S, cc = 0;
	scanf("%d%d", &R, &C), ALL = ~(-1 << R);
	for (i = 0; i < R; ++i)
		for (j = 0; j < C; ++j) scanf("%d", a[i] + j);
	for (i = 0; i <= ALL; ++i) {
		for (mp[i] = x = i, j = 0; j < R; ++j)
			down(mp[i], x), x = x >> 1 | (x & 1) << (R - 1);
		if (mp[i] == i) lyn[l++] = i;
	}
//	fprintf(stderr, "# of lyndon words = %d\n", l);
	memset(nxt, 0, sizeof *dp);
	for (j = 0; j < C; ++j) {
		memcpy(cur, nxt, sizeof *dp);
		for (s[0] = 0, i = 1; i <= ALL; ++i)
			s[i] = s[i & (i - 1)] + a[ctz(i)][j];
		for (i = 0; i < ALL; ++i) up(s[mp[i]], s[i]);
		for (k = 0; k < l; ++k)
			for (S = ~lyn[k] & ALL; S; S = (S - 1) & ~lyn[k])
				up(nxt[mp[lyn[k] | S]], cur[lyn[k]] + s[mp[S]]); //, ++cc;
//		fprintf(stderr, "cc[%d] = %d\n", j, cc);
	}
	printf("%d\n", nxt[ALL]);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}