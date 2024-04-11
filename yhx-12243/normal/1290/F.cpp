#include <bits/stdc++.h>

const int N = 32, L = 20, mod = 998244353;

int n, R, ALL;
int spx[N], snx[N], spy[N], sny[N];
int dp[2][L][L][L][L][2][2], (*cur)[L][L][L][2][2] = *dp, (*nxt)[L][L][L][2][2] = dp[1];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int & reduce(int &x) {return x += x >> 31 & mod;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

int main() {
	int i, c, d, x, y, v, ox, oy;
	int cpx, cnx, cpy, cny, ncpx, ncnx, ncpy, ncny;
	scanf("%d%d", &n, &R), ALL = ~(-1 << n);
	for (i = 0; i < n; ++i)
		scanf("%d%d", &x, &y),
		x >> 31 ? snx[1 << i] -= x : spx[1 << i] += x,
		y >> 31 ? sny[1 << i] -= y : spy[1 << i] += y;
	for (i = 3; i <= ALL; ++i)
		spx[i] = spx[i & (i - 1)] + spx[i & -i],
		snx[i] = snx[i & (i - 1)] + snx[i & -i],
		spy[i] = spy[i & (i - 1)] + spy[i & -i],
		sny[i] = sny[i & (i - 1)] + sny[i & -i];
	******nxt = 1;
	for (; R; R >>= 1) {
		c = R & 1, std::swap(cur, nxt), memset(nxt, 0, sizeof *dp);
		for (cpx = 0; cpx <= spx[ALL]; ++cpx) for (cnx = 0; cnx <= snx[ALL]; ++cnx)
		for (cpy = 0; cpy <= spy[ALL]; ++cpy) for (cny = 0; cny <= sny[ALL]; ++cny)
		for (ox = 0; ox < 2; ++ox) for (oy = 0; oy < 2; ++oy)
			if (v = cur[cpx][cnx][cpy][cny][ox][oy])
				for (d = 0; d <= ALL; ++d) {
					ncpx = cpx + spx[d], ncnx = cnx + snx[d];
					ncpy = cpy + spy[d], ncny = cny + sny[d];
					if (((ncpx ^ ncnx) | (ncpy ^ ncny)) & 1) continue;
					add(nxt[ncpx >> 1][ncnx >> 1][ncpy >> 1][ncny >> 1][(ncpx ^ c) & 1 ? !c : ox][(ncpy ^ c) & 1 ? !c : oy], v);
				}
	}
	printf("%d\n", reduce(--******nxt));
	return 0;
}